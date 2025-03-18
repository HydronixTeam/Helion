# Helion

Helion is a C/C++ function hooking manager for Android applications that solves the problem of function hooking conflicts between two or more compiled libraries inside or outside the APK that may hooking the same function from the same compiled library.

It is suitable for creating separate mods in the form of compiled libraries that will use this function hooking manager to resolve conflicts between function hooks.

At the moment, there is only a function hooking function. Soon, more functions for managing hooked functions will be added.

## Used libraries:

* [Dobby](<https://github.com/jmpews/Dobby>): a lightweight, multi-platform, multi-architecture hook framework.
