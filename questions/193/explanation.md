C++ provides alternative tokens for some punctuators. The two weird lines are exactly equivalent to 

```
    int a[] = {1};
    std::cout << a[0];
```

[lex.digraph]§2.6¶1-2 in the C++11 standard explains this:

"Alternative token representations are provided for some operators and punctuators."

"In all respects of the language, each alternative token behaves the same, respectively, as its primary token, except for its spelling."

Then, a list of alternative tokes is provided, which includes
- `<%` and `%>` for `{` and `}`
- `<:` and `:>` for `[` and `]`