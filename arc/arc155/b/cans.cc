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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll Q, A, B; cin >> Q >> A >> B;
  set<ll> ss;
  ss.insert(A + B);
  ss.insert(A - B);
  REP(_q, 0, Q) {
    ll t, a, b; cin >> t >> a >> b;
    if (t == 1) {
      ss.insert(a + b);
      ss.insert(a - b);
    }else if (t == 2) {
      auto f = [&]() -> ll {
        auto it1 = ss.lower_bound(a);
        if (it1 == ss.end()) {
          auto it2 = prev(it1);
          return a - *it2;
        }
        if (*it1 == a) return 0;
        if (*it1 <= b) return 0;
        ll x = *it1 - b;
        if (it1 == ss.begin()) return x;
        auto it3 = prev(it1);
        return min(x, a - *it3);
      };
      cout << f() << "\n";
    }else assert(0);
  }

  return 0;
}

