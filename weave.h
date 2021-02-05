/*

I 'str' vil 'len'-feltet inneholde _ANTALL TEGN_ i strengen. Dette telles UTEN 0-terminatoren. Det vil si at den tomme strengen har lengde 1.

Prosedyrene tar alltid inn pekere til 'str'-variabler, men benevner de som 'const' for å garantere at de som ikke skal bli endret forblir uendret. Data som returneres fungerer som vanlige c 'bools', hvor 0 betyr at noe mislyktes og positive tall betyr at alt gikk som forventet. Negative tall er ikke i bruk.

Det siste eller de to siste variablene er som regel 'ut'-variabler. Disse vil aldri være const, og VIL muteres fullstendig som følge av et prosedyrekall. Skal data i disse brukes videre, må det lagres med wvCopy.

'Inn'-variabler er alltid const, med mindre de faktisk skal muteres (trim-funksjonene).


*/


#ifndef WAVE_H
#define WEAVE_H


#include <malloc.h>
#include <assert.h>


typedef struct str {
  char *str;
  int len;
} str;


#define WV(x) (str){ .str = x, .len = sizeof x }


void wvCons    (const str *a, const str *b, str *s);
int  wvCmp     (const str *a, const str *b);
int  wvCopy    (const str *a, str *s);

void wvSplitAt (const str *s, int pos, str *a, str *b);
int  wvSplitOn (const str *s, char c, str *a, str *b);

int  wvTrim      (str *a);
int  wvTrimLeft  (str *a);
int  wvTrimRight (str *a);


void wvCons(const str *a, const str *b, str *s) {
  s->len = a->len + b->len - 1; // Trekk fra 1 for å gjøre opp for 0-terminator
  s->str = malloc(s->len);
  for (int i = 0; i < a->len; i++) {
    s->str[i] = a->str[i];
  }
  for (int i = 0; i < b->len; i++) {
    s->str[a->len - 1 + i] = b->str[i];
  }
}


void wvSplitAt(const str *s, int pos, str *a, str *b) {
  assert(pos > 0);
  assert(s->len >= pos);
  
  a->len = pos;
  b->len = s->len - pos;

  // Alloker minne for både a og b, og fordel etterpå
  char *tmp = malloc(a->len + b->len);
  a->str = tmp;
  b->str = tmp + pos;
  
  b->str = malloc(b->len);
  
  for (int i = 0; i < pos ; i++) {
    a->str[i] = s->str[i];
  }
  a->str[a->len] = 0;

  for (int i = 0; i < s->len - pos; i++) {
    b->str[i] = s->str[pos + i];
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
        
      b->len = s->len - i;
      b->str = tmp + i + 1; // Legg til 1, siden vi setter inn 0-terminal i forrige streng hvor det var en separator
      b->str[s->len] = 0;
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
  char *c = a->str + a->len - 2;
  int count = 0;
  
  while (*c == ' ' || *c == '\t' || *c == '\n') {
    count += 1;
    c--;
  }

  a->len -= count;
  a->str[a->len-1] = 0;

  return count;
}

int wvTrim(str *a) {
  int count = 0;
  count += wvTrimLeft(a);
  count += wvTrimRight(a);
  return count;
}





#endif