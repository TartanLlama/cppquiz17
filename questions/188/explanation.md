Modifying string literals is undefined behavior. In practice, the implementation can for instance store the string literal in read-only memory, such as the code segment. Two string literals might even be stored in overlapping memory. So allowing them to be modified is clearly not a good idea.

Let's look at [lex.literal]§2.14 in the C++ standard:

According to  [lex.string]§2.14.5¶1 `"Hello"` is a string literal :

"A string literal is a sequence of characters (as defined in 2.14.3) surrounded by double quotes, optionally
prefixed by R, u8, u8R, u, uR, U, UR, L, or LR, as in "...", R"(...)", u8"...", u8R"**(...)**", u"...",
uR"*˜(...)*˜", U"...", UR"zzz(...)zzz", L"...", or LR"(...)", respectively."

The particularity of storing of string literals is implementation-defined. Thus the result of modification of a string literal is undefined :

[lex.string]§2.14.5¶12

"Whether all string literals are distinct (that is, are stored in nonoverlapping objects) is implementation-defined. The effect of attempting to modify a string literal is undefined."