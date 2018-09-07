#include <iostream>

struct A {
  virtual int fn(int i = 5) const { return i + 1; }
};

struct B : A {
  virtual int fn(int i = 7) const override { return i + 2; }
};


void run(const A& a) {
  std::cout << a.fn(1) << a.fn();
}

int main() {
  run(B());
}