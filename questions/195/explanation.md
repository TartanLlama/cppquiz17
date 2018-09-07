`nullptr_t` (the type of `nullptr`) is not actually a pointer type. Instead, `nullptr` is a "null pointer constant" which can be *converted* to a pointer.

[lex.nullptr]§2.14.7¶1 in the C++11 standard:

"`std::nullptr_t` is a distinct type that is neither a pointer type nor a pointer to member type; rather, a prvalue of this type is a null pointer constant and can be converted to a null pointer value or null member pointer value."