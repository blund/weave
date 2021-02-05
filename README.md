# weave
A single-header C string library meant to make working with strings a little more comfortable.

Works by making a struct ```str``` containing a ```char *``` pointing to the string and an ```int``` containing the length of the string.
This means that a ```str``` can be passed to a function expecting a ```char *```, by passing directly or casting. This lets you use a ```str``` directly with normal C functions, as well as using the ```weave``` functions.

More details soon!
