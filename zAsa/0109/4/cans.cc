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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  multiset<ll> ss;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll x; cin >> x;
      ss.insert(x);
    }else if (tp == 2) {
      ll x, k; cin >> x >> k;
      auto get = [&]() -> ll {
        auto it = ss.lower_bound(x + 1);
        REP(i, 0, k) {
          if (it == ss.begin()) return -1;
          it--;
        }
        return *it;
      };
      cout << get() << "\n";
    }else if (tp == 3) {
      ll x, k; cin >> x >> k;
      auto get = [&]() -> ll {
        auto it = ss.lower_bound(x);
        if (it == ss.end()) return -1;
        REP(i, 0, k - 1) {
          it++;
          if (it == ss.end()) return -1;
        }
        return *it;
      };
      cout << get() << "\n";
    }
  }

  return 0;
}

