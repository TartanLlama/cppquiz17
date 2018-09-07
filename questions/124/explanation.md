[temp.param]§17.1¶14 in the C++11 standard says: "A template-parameter of a template template-parameter is permitted to have a default template-argument.
When such default arguments are specified, they apply to the template template-parameter in the scope of
the template template-parameter."

In this case, the template template-parameter is C, and the scope of C is the function g(), so the default arguments of C (i.e. T = B) are applied and C<B>::f() is called inside g().
