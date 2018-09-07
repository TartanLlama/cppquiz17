One can not use a  keyword as an identifier. We would for instance not be allowed to name our function "`public`". However, `override` is not a keyword, and we're allowed to use it as a function name. (Not that it is a good idea though.)

The list of keywords in [lex.key]§2.12 in the C++11 standard does not list `override`.

[lex.name]§2.11¶2 has this to say:

"The identifiers in Table 3 have a special meaning when appearing in a certain context. When referred to in the grammar, these identifiers are used explicitly rather than using the identifier grammar production. any ambiguity as to whether a given identifier has a special meaning is resolved to interpret the token as a regular identifier." (Table 3 lists `override` and  `final`)

So `override` is a regular identifier except when referred to especially in the grammar. The grammar for class members in [class.mem]§9.2 does just that:


    member-declarator:
        declarator virt-specifier-seq(opt) pure-specifier(opt)
        (...)

    virt-specifier-seq:
        virt-specifier
        virt-specifier-seq virt-specifier

    virt-specifier:
         override
         final

So `override` and `final` only have their special meanings when appearing after a declarator.