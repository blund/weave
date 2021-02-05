/*

I 'str' vil 'len'-feltet inneholde _ANTALL TEGN_ i strengen. Dette telles UTEN 0-terminatoren. Det vil si at den tomme strengen har lengde 1.

Prosedyrene tar alltid inn pekere til 'str'-variabler, men benevner de som 'const' for å garantere at de som ikke skal bli endret forblir uendret. Data som returneres fungerer som vanlige c 'bools', hvor 0 betyr at noe mislyktes og positive tall betyr at alt gikk som forventet. Negative tall er ikke i bruk.

Det siste eller de to siste variablene er som regel 'ut'-variabler. Disse vil aldri være const, og VIL muteres fullstendig som følge av et prosedyrekall. Skal data i disse brukes videre, må det lagres med wvCopy.

'Inn'-variabler er alltid const, med mindre de faktisk skal muteres (trim-funksjonene).



Et av målene er å 'veve' sammen funksjonaliteten her med ordinær c-funksjonalitet. Det vil si at man bare skal kunne passe en 'str' direkte til en c-funksjon (som ikke muterer den), og at alt bare skal fungere. I tillegg skal headeren tilby trygge funksjoner som er lette å bruke.

*/


#ifndef WAVE_H
#define WEAVE_H


#include <malloc.h>
#include <assert.h>
#include <string.h> // For strlen for testing purposes

typedef struct str {
  char *str;
  int len;
} str;


#define WV(x) (str){ .str = x, .len = sizeof(x) - 1}  // Trekk fra 1, siden vi ikke vil telle med 0-terminatoren


void wvCons    (const str *a, const str *b, str *s);  // Sett sammen to strenger
int  wvCmp     (const str *a, const str *b);          // Sammenlign to strenger
int  wvCopy    (const str *a, str *s);                // Kopier en streng til enn annen (dyp kopi med ny allokering)

void wvSplitAt (const str *s, int pos, str *a, str *b);  // Splitt ved indeks
int  wvSplitOn (const str *s, char c, str *a, str *b);   // Splitt på tegn

int  wvTrim      (str *a);  // Fjern whitespace
int  wvTrimLeft  (str *a);  // Fjern whitespace til venstre
int  wvTrimRight (str *a);  // Fjern whitespace til høyre

int  wvValidateString(const str *s);  // Sjekk at lengden på strengen stemmer med 0-termineringen, og sjekk at det er en 0-terminering der den skal være
void wvPrint(const str *s);           // Print streng og lengde





void wvCons(const str *a, const str *b, str *s) {
  s->len = a->len + b->len; // Trekk fra 1 for å gjøre opp for 0-terminator
  s->str = malloc(s->len + 1);
  for (int i = 0; i < a->len; i++) {
    s->str[i] = a->str[i];
  }
  
  for (int i = 0; i < b->len; i++) {
    s->str[a->len + i] = b->str[i];
  }
  s->str[s->len] = 0;
  
}


void wvSplitAt(const str *s, int pos, str *a, str *b) {
  assert(pos > 0);
  assert(s->len >= pos);
  
  a->len = pos;
  b->len = s->len - pos - 1;

  // Alloker minne for både a og b, og fordel etterpå
  char *tmp = malloc(s->len + 2);
  a->str = tmp;
  b->str = tmp + pos + 2; // +1 for 'a' sin terminator og +1 for plassen etter
  
  //b->str = malloc(b->len);
  
  for (int i = 0; i < pos ; i++) {
    a->str[i] = s->str[i];
  }
  a->str[a->len] = 0;

  for (int i = 0; i < s->len - pos; i++) {
    b->str[i] = s->str[pos + i + 1];
  }
  b->str[b->len] = 0;

}


int wvSplitOn(const str *s, char c, str *a, str *b) {
  int first = 1;
  char *tmp = malloc(s->len);

  a->str = tmp;
  for (int i = 0; i < s->len; i++) {
    tmp[i] = s->str[i];
    
    if (s->str[i] == c && first) {
      first = 0;
      a->len = i;
      a->str[i] = 0;
        
      b->len = s->len - i - 1;
      b->str = tmp + i + 1; // Legg til 1, siden vi setter inn 0-terminal i forrige streng hvor det var en separator
      b->str[b->len] = 0;
    }
  }
  
  if (first) {
    a->len = s->len;
    b->len = 0;
    b->str = 0;
    return 0;
  }
  return 1; 
}

             
int wvCmp(const str *a, const str *b) {
  if (a->len != b->len) { return 0; }

  int result = 0;
  for (int i = 0; i < a->len; i++) {
    result += (a->str[i] != b->str[i]);
  }
  return !result;
}


int wvCopy(const str *a, str *s) {
  s->str = malloc(a->len);
  
  if (!s->str) return 0; // Could not get any memory
  
  for (int i = 0; i <= a->len; i++) {
    s->str[i] = a->str[i];
  }

  return 1;
}


int wvTrimLeft(str *a) {
  char *c = a->str;
  int count = 0;
  while (*c == ' ' || *c == '\t' || *c == '\n') {
    count += 1;
    c++;
  }

  a->len -= count;
  a->str = a->str + count;

  return count;
}


int wvTrimRight(str *a) {
  char *c = a->str + a->len - 1;
  int count = 0;
  
  while (*c == ' ' || *c == '\t' || *c == '\n') {
    count += 1;
    c--;
  }

  a->len -= count;
  a->str[a->len] = 0;

  return count;
}


int wvTrim(str *a) {
  int count = 0;
  count += wvTrimLeft(a);
  count += wvTrimRight(a);
  return count;
}



//
// Debug-prosedyrer
//

void wvValidateString(const str *s) {
  assert(strlen(s->str) == s->len);
  assert(s->str[s->len] == '\0');
}


void wvPrint(const str *s) {
  printf("%s (%i)\n", s->str, s->len);
}

#endif
