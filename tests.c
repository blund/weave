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


  // Test wvCons
  str cons_test_a;
  str cons_test_b;
  str cons_test_res;
  str cons_test_right;
  
  cons_test_a = WV("A");
  cons_test_b = WV("B");
  cons_test_right = WV("AB");
  wvCons(&cons_test_a, &cons_test_b, &cons_test_res);
  assert(wvCmp(&cons_test_res, &cons_test_right));


  // Test wvSplitOn
  str splitOn_test_s;
  str splitOn_test_a;
  str splitOn_test_b;
  str splitOn_test_res_a;
  str splitOn_test_res_b;



  // Test wvSplitAt
  // Test wvTrimLeft
  // Test wvTrimRight
  
  /*
  str test  = WV("epic bacon");
  str test2 = WV(" YOOO");
  
  str result;
  wvCons(&test, &test2, &result);

  //str a, b;
  //splitAt(&result, 7, &a, &b);

  str s = WV("  Epic Bacon  ");
  str a;
  str b;

  wvCopy(&s, &b);

  int res = wvTrim(&test2);
  */
  //printf("%s: %i\n", test2.str, res);
}
