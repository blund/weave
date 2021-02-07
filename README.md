# weave
A single-header C string library meant to make working with strings a little more comfortable.

It offers functions for comparisons, concatinating, splitting and trimming, with none of the bounds errors!
The goal is to be able to use strings in my game engine without my hair turning gray! Features will be added as they are needed :)

## Example usage
```
str a = WV("we");
str b = WV("ave");
str c;
wvCons(&a, &b, &c);
printf("%s\n", c.str);
// will print "weave"!

```

## Implementation details
Internally, a ```str``` is a ```char *``` pointing to its string and an ```int``` containing the length of the string. The strings are normal, ```0```-terminated C-strings. The library functions take advantage of the known length, but make sure to maintain the ```0```-terminator so that the strings can be used by other standard C-libraries without any sort of conversion. Thus we attempt to 'weave' together these two ways of acting on strings :)

## TODO!
* Add an update function, to be called after a string has been used with a normal C function to update it's line length.
* Add string formatting, hopefully type safe formatting using C11 magic.
* Maybe eliminate some ```malloc```s by allocating a memory pool for the library to use.. We'll see!

More details soon!
