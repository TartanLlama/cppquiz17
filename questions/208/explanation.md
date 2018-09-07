The `[]` operator inserts an element if the key is not present. In the case of a class, the element is default constructed. So doing `m[7]` calls the default constructor of `C` (no matter if we assign to it right after), setting  `default_constructed` to `true`.

The expression `C(1)` constructs an instance of `C` using the constructor taking an `int`, setting `constructed` to `true`.

The `=` in `m[7] = C(1)` calls the copy assignment operator to copy assign the newly created `C(1)` to the previously default constructed `C` inside the map, setting `assigned` to `true`.

The fact that an object is first default constructed is covered by [map.access]§23.4.4.3¶5 in the standard:

> `T& operator[](key_type&& x);` 
>
> Effects: If there is no key equivalent to `x` in the map, inserts `value_type(std::move(x), T())` into the map.

`value_type` is just a `typedef` for `pair<const Key, T>`, which in our case is `pair<const int, C>`. So it inserts a `pair(7, C())`, which calls the default constructor for `C`.

To avoid the default construction followed by a copy assignment, you can use one of the following:

    m.insert(pair<int, C>(7, C(1)));
    m.emplace(7, C(1));