To answer this we need to look at overload resolution of vector's constructors:

[vector.cons]§23.3.6.2¶6 says (somewhat redacted):
`vector(size_type n, const T& value);`
Effects: Constructs a `vector` with `n` copies of `value`

So `v1` contains one "`2`".

[over.match.list]§13.3.1.7 says (in summary) that when non-aggregate classes (such as `vector`) are list-initialized† and have an initializer list constructor (again, like `vector`), that constructor is chosen, and the argument list consists of the initializer list as a single argument.
(†: [dcl.init.list]§8.5.4¶1: List-initialization is initialization of an object or reference from a braced-init-list.)

So `v2` is initialized from the elements (aka initializer-clauses) in the braced-init-list, and contains the elements "`1`" and "`2`".