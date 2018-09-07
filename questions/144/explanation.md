As the `else` part of the branch is obvious, we concentrate on the `if` part and make the assumptions present in the condition.

[lex.icon]§2.14.2 in the standard: "The type of an integer literal is the first of the corresponding list in  Table 6." [Table 6: int, unsigned int, long int, unsigned long int … for hexadecimal literals --end Table] in which its value can be represented." 

Since the literal `0xffffffff` needs 32 digits, it can be represented as an `unsigned int` but not as a signed `int`, and is of type `unsigned int`. But what happens with the negative of an unsigned integer?

[expr.unary.op]§5.3.1 in the standard: "The negative of an unsigned quantity is computed by subtracting its value from 2^n , where n is the number of bits in the promoted operand." Here `n` is `32`, and we get:

`2^32 - 0xffffffff = 4294967296 - 4294967295 = 1`

So `i` is initialised to `1`, and `N[1]` is the only element accessed in the loop. (The second time around the loop, `i` is `0`, which evaluates to false, and the loop terminates.)