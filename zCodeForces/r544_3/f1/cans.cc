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
  vector nbr(n, vector<ll>());
  for (ll i = 0; i < m; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  ll vmax = 0;
  ll root = -1;
  for (ll i = 0; i < n; i++) {
    ll v = nbr[i].size();
    if (v > vmax) {
      vmax = v;
      root = i;
    }
  }
  vector<bool> visited(n);
  visited[root] = true;
  for (ll x : nbr[root]) {
    visited[x] = true;
    cout << root + 1 << " " << x + 1 << "\n";
  }
  auto dfs = [&](auto rF, ll x) -> void {
    for (ll y : nbr[x]) {
      if (!visited[y]) {
	visited[y] = true;
	cout << x + 1 << " " << y + 1 << "\n";
	rF(rF, y);
      }
    }
  };

  for (ll x : nbr[root]) dfs(dfs, x);

  return 0;
}

