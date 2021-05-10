#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
#include <atcoder/convolution>


template<typename T>
void mult(T& a, const T& b) {
  a *= b;
}

template<>
void mult(ll& a, const ll& b) {
  a -= b;
}

template<typename T>
struct A {
  T v;

  A(T t) : v(t) {}

  A& operator +=(const A& o) {
    v += o.v;
    return *this;
  }

  A& operator *=(const A& o) {
    mult(v, o.v);
    return *this;
  }


};


int main() {

  A<ll> a1((ll)5);
  A<ll> a2((ll)2);
  A<int> b1((int)7);
  A<int> b2((int)4);
  
  a1 *= a2;
  b1 *= b2;
  cout << a1.v << endl;
  cout << b1.v << endl;

  return 0;
}
