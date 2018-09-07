In `f()`, an `E` object is constructed, and `1` is printed. This object is then returned to `main()`, and one could expect the copy constructor to be called, printing `2`.

However, [stmt.return]§6.6.3¶2 in the standard says "Note: A copy or move operation associated with a return statement may be elided", meaning that the implementation is free to skip the copy constructor. This is optional, and unspecified behaviour.

Most implementations will elide the copy constructor and output `13`, but may be urged not to so with the `-fno-elide-constructors` option and output `1233`.

For more information about the return value optimisation, and an investigation of which implementations use it, see <http://blog.knatten.org/2011/08/26/dont-be-afraid-of-returning-by-value-know-the-return-value-optimization/>