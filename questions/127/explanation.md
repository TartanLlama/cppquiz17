[expr.prim.lambda]§5.1.2¶18 says
Every occurrence of `decltype((x))` where `x` is a possibly parenthesized id-expression that names an entity of automatic storage duration is treated as if `x` were transformed into an access to a corresponding data member of the closure type that would have been declared if `x` were an odr-use of the denoted entity.

So additional parentheses, as the in the code snippet above, are ignored.

The member of the closure type corresponding to the as-if-captured `j` will be not a reference, but will have the referenced type of the reference, since it is captured by copy ([expr.prim.lambda]§5.1.2¶14).

Since the lambda is not declared `mutable`, the overloaded `operator()` of the closure type will be a const member function. [expr.prim.lambda]§5.1.2¶5: "The closure type for a lambda-expression has a public inline function call operator (...) This function call operator is declared const if and only if the lambda-expression’s parameter-declaration-clause is not followed by mutable."
 
Since the expression for `decltype` is a parenthesized lvalue expression, [dcl.type.simple]§7.1.6.2¶4 has this to say: "The type denoted by decltype(e) is (...)  T&, where T is the type of e;" As the expression occurs inside a const member function, the expression is const, and `decltype((j))` denotes `int const&`. See also the example in [expr.prim.lambda]§5.1.2¶18.