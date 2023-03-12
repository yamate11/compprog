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

  auto solve = [&]() -> ll {
    ll N; cin >> N;

    auto func = [&](auto& vec) -> ll {
      ll ret = 0;
      set<ll, greater<ll>> ss;
      REPrev(i, N-1, 0) ss.insert(ss.end(), i);
      sort(ALL(vec), greater<pll>());
      for (auto [d, k] : vec) {
        auto it = ss.lower_bound(k);
        if (it != ss.end()) {
          ret += d;
          ss.erase(it);
        }
      }
      return ret;
    };

    ll base = 0;
    vector<pll> left, right;
    REP(i, 0, N) {
      ll k, l, r; cin >> k >> l >> r;
      if (l > r) {
        left.emplace_back(l - r, k - 1);
        base += r;
      }else {
        right.emplace_back(r - l, N - k - 1);
        base += l;
      }
    }
    ll v1 = func(left);
    ll v2 = func(right);
    return base + v1 + v2;
  };

  ll T; cin >> T;
  REP(i, 0, T) cout << solve() << "\n";

  return 0;
}

