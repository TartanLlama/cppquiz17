[dcl.fct.default]§8.3.6¶10 in the standard:
A virtual function call (10.3) uses the default arguments in the declaration of the virtual function determined by the static type of the pointer or reference denoting the object. An overriding function in a derived class does not acquire default arguments from the function it overrides.

Thus, an overridden function `foo()` will be called with argument `int a = 1`, and the output is `B1`.