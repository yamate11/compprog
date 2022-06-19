#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    vector<vector<ll>> child(N);
    REP2(i, 1, N) {
      ll p; cin >> p; p--;
      child[p].push_back(i);
    }
    vector<ll> L(N), R(N);
    REP(i, N) cin >> L[i] >> R[i];
    using pll = pair<ll, ll>;
    auto dfs = [&](auto rF, ll nd) -> pll {
      ll cnt = 0;
      ll val = 0;
      for (ll cld : child[nd]) {
        auto [c, v] = rF(rF, cld);
        cnt += c;
        val += v;
      }
      if (L[nd] <= val) return pll(cnt, min(val, R[nd]));
      else return pll(cnt + 1, R[nd]);
    };
    auto [ans, _] = dfs(dfs, 0);
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

