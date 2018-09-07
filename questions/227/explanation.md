`using Func = int()` is an alias-declaration introducing the typedef-name `Func` for a function taking no parameters and returning an int.

This typedef-name can be used both for free functions and, as in this question, for member functions. [class.mfct]§9.3¶9 in the C++11 standard:

> [Note: A member function can be declared (but not defined) using a typedef for a function type. The resulting member function has exactly the same type as it would have if the function declarator were provided explicitly

The use of `Func f` in `struct S` is therefore equivalent to `int f()`.