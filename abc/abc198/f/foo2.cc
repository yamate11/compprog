#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>

struct A {
};

struct B {
};

void func1(A a) {}

void func2(B b) {}

void func3() {}

template<typename T>
void g(T t) {
  func3();
}

template<>
void g(A a) {
  func1(a);
}

template<>
void g(B b) {
  func2(b);
}

int main() {
  
  A a;
  g(a);
  
  B b;
  g(b);

  int c = 0;
  g(c);

  return 0;
}
