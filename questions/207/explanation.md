The `[]` operator inserts an element if the key is not present. For a simple `int`, it inserts `0`.

According to [map.access]§23.4.4.3¶5 in the standard:

> `T& operator[](key_type&& x);` 
>
> Effects: If there is no key equivalent to `x` in the map, inserts `value_type(std::move(x), T())` into the map.

`value_type` is just a `typedef` for `pair<const Key, T>`, which in our case is `pair<const int, int>`. So it inserts a `pair(42, int())`

`int()` is a *value-initialization*, which for non-class, non-array types means *zero-initialization* (see [dcl.init]§8.5¶7). And according to [dcl.init]§8.5¶5:

> To zero-initialize an object or reference of type `T` means:
> — if `T` is a scalar type (3.9), the object is set to the value `0` (zero), taken as an integral constant expression, converted to `T`;

So setting the value for the key `42` to `T()` means setting it to `0`.