`??/` is a trigraph. According to [lex.trigraph]§2.4¶1, this trigraph is translated to `\` before any other processing takes place.

Since that `\` is followed by a newline,  the line `x=1` is treated as a continuation of the comment.

Note: Trigraphs will be removed from the standard in C++17.