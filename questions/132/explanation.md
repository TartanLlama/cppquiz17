Is `foo` called both times or just once? The C++11 standard says this in [dcl.fct.default]§8.3.6¶9: "Default arguments are evaluated each time the function is called."

Thus, `foo` is called twice.