#include <iostream>
#include <type_traits>

int main() {
  std::cout << std::is_pointer<std::nullptr_t>::value;
}