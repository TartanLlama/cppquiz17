For the call `f(i)`, since the type of `i` is `int`, template argument deduction deduces `T = int`.

The explicit specialization `template <> void f(const int &i)` has `T = const int`, which is not the same type as `int`, so it doesn't match.

Instead, `template <class T> void f(T &i)` with `T = int` is used to create the implicit instantiation `void f<int>(int&)`.