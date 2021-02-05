#include "weave.h"

int main() {

  // Test wvCmp
  str cmp_test_a;
  str cmp_test_b;
  
  cmp_test_a = WV("AA");
  cmp_test_b = WV("AA");
  
  assert(wvCmp(&cmp_test_a, &cmp_test_b));

  cmp_test_a = WV("AA");
  cmp_test_b = WV("BB");

  assert(!wvCmp(&cmp_test_a, &cmp_test_b));

  cmp_test_a = WV("AA");
  cmp_test_b = WV("B");

  assert(!wvCmp(&cmp_test_a, &cmp_test_b));
  printf("wvCmp tests passed\n");

  
  // Test wvCons
  str cons_test_a;
  str cons_test_b;
  str cons_test_res;
  str cons_test_right;
  
  cons_test_a     = WV("A");
  cons_test_b     = WV("B");
  cons_test_right = WV("AB");

  wvCons(&cons_test_a, &cons_test_b, &cons_test_res);

  assert(wvCmp(&cons_test_res, &cons_test_right));
  printf("wvCons tests passed\n");


  
  // Test wvSplitAt
  str splitAt_test_s;
  str splitAt_test_a;
  str splitAt_test_b;
  str splitAt_test_res_a;
  str splitAt_test_res_b;

  splitAt_test_s     = WV("aa,bb");
  splitAt_test_res_a = WV("aa");
  splitAt_test_res_b = WV("bb");
  
  wvSplitAt(&splitAt_test_s, 2, &splitAt_test_a, &splitAt_test_b);

  assert(wvCmp(&splitAt_test_res_a, &splitAt_test_a));
  assert(wvCmp(&splitAt_test_res_b, &splitAt_test_b));
  printf("wvSplitAt tests passed\n");


  
  // Test wvSplitOn
  str splitOn_test_s;
  str splitOn_test_a;
  str splitOn_test_b;
  str splitOn_test_res_a;
  str splitOn_test_res_b;

  splitOn_test_s     = WV("aa,bb");
  splitOn_test_res_a = WV("aa");
  splitOn_test_res_b = WV("bb");
  
  wvSplitOn(&splitOn_test_s, ',', &splitOn_test_a, &splitOn_test_b);

  assert(wvCmp(&splitOn_test_res_a, &splitOn_test_a)); 
  assert(wvCmp(&splitOn_test_res_b, &splitOn_test_b));
  printf("wvSplitOn tests passed\n");


  
  // Test wvTrimLeft
  str wvTrimLeft_test;
  str wvTrimLeft_right;
  int count;

  wvTrimLeft_test  = WV("    A");
  wvTrimLeft_right = WV("A"); 

  count = wvTrimLeft(&wvTrimLeft_test);
  assert(count == 4);
  assert(wvCmp(&wvTrimLeft_test, &wvTrimLeft_right));

  wvTrimLeft_test  = WV("A    ");
  wvTrimLeft_right = WV("A    "); 

  count = wvTrimLeft(&wvTrimLeft_test);
  assert(count == 0);
  assert(wvCmp(&wvTrimLeft_test, &wvTrimLeft_right));
  printf("wvTrimLeft tests passed\n");


  
  // Test wvTrimRight
  str wvTrimRight_test;
  str wvTrimRight_right;
  count;

  wvTrimRight_test  = WV("A    ");
  wvTrimRight_right = WV("A"); 

  count = wvTrimRight(&wvTrimRight_test);
  
  assert(count == 4);
  assert(wvCmp(&wvTrimRight_test, &wvTrimRight_right));

  wvTrimRight_test  = WV("    A");
  wvTrimRight_right = WV("    A"); 

  count = wvTrimRight(&wvTrimRight_test);
  assert(count == 0);
  assert(wvCmp(&wvTrimRight_test, &wvTrimRight_right));
  printf("wvTrimRight tests passed\n");


  
  str wvTrim_test;
  str wvTrim_right;
  count;

  wvTrim_test  = WV("    A    ");
  wvTrim_right = WV("A"); 

  count = wvTrim(&wvTrim_test);


  assert(count == 8);
  assert(wvCmp(&wvTrim_test, &wvTrim_right));

  wvTrim_test  = WV("A");
  wvTrim_right = WV("A"); 

  count = wvTrim(&wvTrim_test);
  assert(count == 0);
  assert(wvCmp(&wvTrim_test, &wvTrim_right));
  printf("wvTrim tests passed\n");





}
