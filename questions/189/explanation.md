In both calls `A::fn` is overridden, so `B::fn` will be called. The first call `a.fn(1)` is trivial, the argument `1` is used, and `3` is printed.

The second call `a.fn()` is less trivial. The implementation doesn't care about the "virtuality" of a function when determining the default argument, but instead uses the static type of the the referenced object. Thus, the default argument `5` from `A::fn` will be used even if `B::fn` is called, and `7` is printed.

[dcl.fct.default]§8.3.6¶10 in the C++11 standard:

"A virtual function call (10.3) uses the default arguments in the declaration of the virtual function determined by the static type of the pointer or reference denoting the object. An overriding function in a derived class does not acquire default arguments from the function it overrides."