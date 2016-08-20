# Cplus

Goals and contents of this library:

* Make using C99 easier.
* Use C11 when possible, while always supporting C99.
* Add reflection to C objects that you want reflection for - and no more.
* Be fast. Don't break the C ideology.
* Be easy to use, with samples and unit-tests.
* To scratch the itch of liking using C, but not liking all the hoops.
* Provide sane multi-threading primitives.
* (Eventually) support co-routines in C99.

To this end, the library:

* Provides a well-tested and performant set of common containers like Vector, List and Map.
* Includes tracing memory model.
* Adds C++-based IDL to generate boiler-plate C code, to make a simpler `C with classes`.

The end-goal is to provide a basis for an IoT infrastructure that we can all use with
ease and confidence.

