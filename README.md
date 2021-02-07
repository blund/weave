# weave
A single-header C string library meant to make working with strings a little more comfortable.

```
// How to use

str a = WV("we");
str b = WV("ave");
str c;
wvCons(&a, &b, &c);
printf("%s", c.str);
// will print "weave"!

```

It offers functions for concatinating, splitting and trimming! 
I plan on adding type safe string formatting for C11, and perhaps avoid some ```mallocs``` by allocating a memory pool for the whole library... We'll see!

The goal is to be able to use strings in my game engine without my hair turning gray! Features will be added as they are needed :)


More details soon!
