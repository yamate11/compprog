#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  vector<ll> D(n + 1);
  for (ll i = 1; i <= n; i++) cin >> D[i];
  using nbr_t = pair<ll, ll>;
  vector<vector<nbr_t>> nbr(n + 1);
  for (ll i = 1; i <= m; i++) {
    ll u, v; cin >> u >> v;
    nbr[u].emplace_back(v, i);
    nbr[v].emplace_back(u, i);
  }
  ll adj = -1;
  ll n_conf = 0;
  for (ll i = 1; i <= n; i++) {
    if (D[i] == -1) {
      if (adj == -1) adj = i;
    } else {
      if ((ll)nbr[i].size() % 2 != D[i]) {
        n_conf++;
      }
    }
  }
  if (n_conf % 2 == 1) {
    if (adj == -1) {
      cout << -1 << endl;
      return 0;
    }
  }else {
    adj = -1;
  }
  vector<bool> visited(n + 1);
  ll n_ans = m;
  vector<bool> ans(m + 1, true);
  auto dfs = [&](auto rF, ll nd) -> ll {
    if (visited[nd]) return -1;
    visited[nd] = true;
    ll cnt = 0;
    for (auto [cld, ei] : nbr[nd]) {
      ll rc = rF(rF, cld);
      if (rc == 1) {
        ans[ei] = false;
        n_ans--;
        cnt++;
      }
    }
    if (nd == adj) cnt++;
    else if (D[nd] >= 0 && (ll)nbr[nd].size() % 2 != D[nd]) cnt++;
    return (cnt % 2);
  };
  dfs(dfs, 1);
  cout << n_ans << endl;
  for (ll i = 1; i <= m; i++) {
    if (ans[i]) cout << i << "\n";
  }


  return 0;
}

