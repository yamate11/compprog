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

  ll N, M; cin >> N >> M;
  vector nbr(N, vector<pll>());
  REP(i, M) {
    ll u, v, l; cin >> u >> v >> l; u--; v--;
    nbr[u].emplace_back(v, l);
    nbr[v].emplace_back(u, l);
  }
  const ll big = 1e18;
  auto f = [&](ll goal) -> ll {
    vector<ll> dist(N, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[0] = 0;
    pque.emplace(0, 0);
    while (not pque.empty()) {
      auto [d, nd] = pque.top(); pque.pop();
      if (dist[nd] < d) continue;
      if (nd == goal) return d;
      for (auto [fwd, len] : nbr[nd]) {
        if (nd == 0 and fwd == goal) continue;
        if (nd == goal and fwd == 0) continue;
        ll newD = d + len;
        if (dist[fwd] <= newD) continue;
        dist[fwd] = newD;
        pque.emplace(newD, fwd);
      }
    }
    return big;
  };
  ll ans = big;
  for (auto [fwd, len] : nbr[0]) {
    ans = min(ans, f(fwd) + len);
  }
  if (ans == big) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}

