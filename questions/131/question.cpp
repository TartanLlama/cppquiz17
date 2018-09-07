#include <iostream>
using namespace std;

class C {
public:
  explicit C(int) {
    std::cout << "i";
  };
  C(double) {
    std::cout << "d";
  };
};

int main() {
  C c1(7);
  C c2 = 7;
}