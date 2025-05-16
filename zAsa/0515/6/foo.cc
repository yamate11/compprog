#include <iostream>

struct A {
  int x;
  A(int x_) : x(x_) {}
};

int main() {
  long long b = 20;
  A a{(int)b};
  std::cout << a.x << "\n";
}
