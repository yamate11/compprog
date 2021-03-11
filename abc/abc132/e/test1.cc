#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


template <typename T>
struct AAA {
  int enc(T t) {
    return 1;
  }
  T dec(int x) {
    return T(x);
  }
};


struct C {
  int enc(double t) {
    return t + 3;
  }
  double dec(int x) {
    return x - 3;
  }
};

template<typename ED>
struct Z {
  ED ed;
  void foo() {
    cout << "enc 3: " << ed.enc(3) << endl;
  }
};


int main() {
  Z<AAA<double>> z1;
  Z<C> z2;
  z1.foo();
  z2.foo();

}
