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

// @@ !! LIM()

using pll = pair<ll, ll>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector nbr(N, vector<pll>());
  REP(i, N-1) {
    ll u, v, w; cin >> u >> v >> w; u--; v--;
    nbr[u].emplace_back(v, w);
    nbr[v].emplace_back(u, w);
  }
  ll root = 0;
  while (SIZE(nbr[root]) != 1) root++;
  vector<ll> ans(N);
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    for (auto [cld, d] : nbr[nd]) {
      if (cld == pt) continue;
      if (d % 2 == 0) ans[cld] = ans[nd];
      else            ans[cld] = 1 - ans[nd];
      rF(rF, cld, nd);
    }
  };
  ans[root] = 0;
  dfs(dfs, root, -1);
  for (ll a : ans) cout << a << "\n";
  return 0;
}

