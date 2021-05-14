#include <iostream>
#include <iomanip>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>


class A {
  int x;
public:
  int getX() { return x; }
  void setX(int x_) { x = x_; }

  friend int func(A a);
};

int func(A a) {
  return a.x;
}

int main() {
  A a;
  a.setX(3);
  cout << a.getX() << endl;
  
  cout << func(a) << endl;

  return 0;
}
