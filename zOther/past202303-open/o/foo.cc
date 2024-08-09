#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"


template <typename F = nullptr_t>
void func(int x, F f_body = nullptr) {
  if constexpr(is_same_v<F, nullptr_t>) {
    cout << "ignored" << endl;
  }else {
    if (f_body(x)) {
      cout << "yes" << endl;
    }else {
      cout << "no" << endl;
    }
  }
}


int main() {
  auto judge = [&](int x) -> bool { return x > 0; };
  func(2, judge);
  func(5);
  return 0;
}

