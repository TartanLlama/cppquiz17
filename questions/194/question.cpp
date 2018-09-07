#include <iostream>

struct A {
    virtual int override() { return 0; }
};

struct B : public A {
    int override() override { return 1; }
};

int main() {
    std::cout << B().override();
}