#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
#include <atcoder/dsu>
using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

template<typename T>
struct A {
  void func1(int a) {
  }

  template<typename U = T>
  enable_if_t<is_same_v<U, unsigned>, void> func2(int a, int b) {
  }
};
  

int main() {
  A<int> a;
  a.func1(0);
  a.func2(0, 0);
}
