#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

template<typename T>
struct A {
  map<ll, T> impl;
  
  template<typename T1>
  void set(ll i, T1&& t) {
    impl[i] = forward<T1>(t);
  }

};

struct S {
  int x;
  vector<ll> v;
  S() : x(0), v() { cerr << "S()" << endl; }
  S(const S& s) : x(s.x), v(s.v) { cerr << "S(const S&)" << endl; }
  S(S&& s) : x(s.x), v(move(s.v)) { cerr << "S(S&&)" << endl; }
  S& operator =(const S& o) {
    cerr << "operator =(const S&)" << endl;
    x = o.x; v = o.v;
    return *this;
  }
  S& operator =(S&& o) {
    cerr << "operator =(S&&)" << endl;
    x = o.x; v = move(o.v);
    return *this;
  }
};


int main() {
  S s1;
  s1.x = 10;
  s1.v = {1, 2, 3};
  S s2(s1);
  const S s3(s1);
  S s4(move(s3));

  A<S> a;
  cerr << "1" << endl;
  a.set(0, s2);
  cerr << "2" << endl;
  a.set(1, s3);
  cerr << "3" << endl;
  a.set(2, move(s4));

}
