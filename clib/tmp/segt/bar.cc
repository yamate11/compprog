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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))


template <int e>
struct A {
  template<int f = e>
  enable_if_t<f> f1() {
    if constexpr(e) { cout << "Yes\n"; }
    else { cout << "No\n"; }
  }
  template<int f = e>
  enable_if_t<! f> f1() {
    cout <<"alternate\n";
  }
};


int main() {
  A<1> a;
  a.f1();
  A<0> b;
  b.f1();

  return 0;
}
