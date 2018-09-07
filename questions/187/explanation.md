On the first line, `C c1;`, the object `c1` is default initialized, so the default constructor is called, printing `1`.

On the second line,  `C c2 = c1;`, the object `c2` is copy initialized, so the copy constructor is called, printing `2`. (Note that no assignment is taking place, even though there's a `=` involved.)

Let's have a look at the C++11 standard:

[dcl.init]§8.5¶14:
"The initialization that occurs in the form `T x = a;` (...)  is called copy-initialization."

`C c2 = c1;` is definitely on the form `T x = a;`, so we have copy-initialization.

[dcl.init]§8.5¶16:
"If the destination type is a (possibly cv-qualified) class type (...) If the initialization is direct-initialization, or if it is copy-initialization where the cv-unqualified version of the source type is the same class as, or a derived class of, the class of the destination, constructors are considered. The applicable constructors are enumerated (13.3.1.3), and the best one is chosen through overload resolution (13.3). The constructor so selected is called to initialize the object, with the initializer expression or expression-list as its argument(s)."

The destination type here is `C`, and the initialization is copy-initialization. The source type is the same class as the class of the destination, so constructors are considered. The only constructor taking a `C` as an argument is our copy constructor, which prints `2`.