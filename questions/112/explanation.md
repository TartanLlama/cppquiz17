First, `b1` is default initialized. All members are initialized before the body of the constructor, so `b1.a` is default initialized first, and we get the output `14`.

[class.base.init]§12.6.2¶8 in the standard: "In a non-delegating constructor, if a given non-static data member or base class is not designated by a
mem-initializer-id (...) then if the entity is a non-static data member that has a brace-or-equal-initializer, the entity is initialized as specified in §8.5 (...) otherwise, **the entity is default-initialized.**"

Then, `b2` is initialized with the move construcor (since `std::move(b1)`converts the reference to `b1` to an xvalue, allowing it to be moved from.) In `B`'s move constructor, `a` is initialized in the initializer list. Even though `a` is an rvalue reference (and bound to an rvalue), `a` itself is an lvalue, and cannot be moved from. `b2.a` is then copy initialized, printing `2`, and finally the body of `B`'s move constructor prints `6`.

(If the concept of rvalue references being lvalues is confusing, read <http://isocpp.org/blog/2012/11/universal-references-in-c11-scott-meyers> . Search for "In widget".)