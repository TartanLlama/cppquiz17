According to [dcl.type.simple]§7.1.6.2¶4 in the C++ standard:
"The type denoted by decltype(e) is deﬁned as follows:
— if e is an unparenthesized id-expression or an unparenthesized class member access (5.2.5), decltype(e) is the type of the entity named by e. If there is no such entity, or if e names a set of overloaded functions, the program is ill-formed;
— otherwise, if e is an xvalue, decltype(e) is T&&, where T is the type of e;
— otherwise, if e is an lvalue, decltype(e) is T&, where T is the type of e;
— otherwise, decltype(e) is the type of e."

Because `a` is encapsulated in parentheses, it doesn't qualify for the first case, it is treated as an lvalue, therefore `b`'s type is `int&`, not `int`.