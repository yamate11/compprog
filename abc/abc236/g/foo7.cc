#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

struct A {
  A() { cout << "Hello, A\n"; }
};

struct B {
  B(int i) { cout << "Hello, B.  It is " << i << ".\n"; }
};

template<typename T>
void foo() {
  if constexpr (is_constructible_v<T, int>) {
    cout << "yes\n";
  }else {
    cout << "no\n";
  }
}

int main() {
  foo<A>();
  foo<B>();
  return 0;
}

          
