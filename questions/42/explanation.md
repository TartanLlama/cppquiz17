According to [dcl.init.list]§8.5.4¶3 in the C++ standard:

"List-initialization of an object or reference of type T is deﬁned as follows:
— If the initializer list has no elements and T is a class type with a default constructor, the object is value-initialized.
— Otherwise, if T is an aggregate, aggregate initialization is performed (§8.5.1).
— Otherwise, if T is a specialization of std::initializer_list<E>, an initializer_list object is constructed as described below and used to initialize the object according to the rules for initialization of an object from a class of the same type (§8.5).
— Otherwise, if T is a class type, constructors are considered. The applicable constructors are enumerated and the best one is chosen through overload resolution (§13.3, §13.3.1.7). If a narrowing conversion (see below) is required to convert any of the arguments, the program is ill-formed.
— (more cases...)"

`a1` is default initialized, as described in [dcl.init.list]§8.5.¶11

`a2` doesn't actually use the initializer_list constructor with a list of zero elements, but the default constructor, as described by the first option of the list above.

`a3`'s and `a4`'s constructor is chosen in overload resolution, as described in [over.match.list]§13.3.1.7:

"When objects of non-aggregate class type T are list-initialized (§8.5.4), overload resolution selects the constructor in two phases:
— Initially, the candidate functions are the initializer-list constructors (§8.5.4) of the class T and the argument list consists of the initializer list as a single argument.
— If no viable initializer-list constructor is found, overload resolution is performed again, where the candidate functions are all the constructors of the class T and the argument list consists of the elements of the initializer list."

Initializer list constructors are greedy, so even though `A(int)` constructor is available, the standard mandates that `initializer_list<int>` is prioritized, and if - and only if - it's not available, the compiler is allowed to look for other constructors. (This is why it is not recommended to provide a constructor that ambiguously overloads with an initializer_list constructor. See the answer to #4 in <http://herbsutter.com/2013/05/09/gotw-1-solution/> )