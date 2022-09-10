#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"


template <bool gen = false>
struct A {
  int foo() { return 0; }
};

template <>
struct A<true> {
  int foo() { return 1; }
};

int main() {
  A a1;
  A<true> a2;
  cout << a1.foo() << endl;
  cout << a2.foo() << endl;

}
