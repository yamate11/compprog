#include <bits/stdc++.h>

#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m, k0; cin >> n >> m >> k0;
  vector prohib(k0 + 1, vector(k0 + 1, vector(k0 + 1, vector(k0 + 1, false))));
  using sta = pair<ll, ll>;
  using stb = pair<ll, ll>;
  vector nxt(n, vector<sta>());
  vector prv(n, set<stb>());
  for (ll i = 0; i < m; i++) {
    ll u, v, w; cin >> u >> v >> w; u--; v--;
    nxt[u].emplace_back(w, v);
  }
  for (ll i = 0; i < n; i++) {
    sort(nxt[i].begin(), nxt[i].end());
    ll k = nxt[i].size();
    for (ll j = 0; j < k; j++) {
      auto [w, y] = nxt[i][j];
      stb t(k, j);
      for (auto [kk, jj] : prv[y]) {
	prohib[k][j][kk][jj] = true;
	prohib[kk][jj][k][j] = true;
      }
      prv[y].insert(t);
    }
  }
  vector hist(k0 + 1, 0LL);
  auto dfs = [&](auto rF, ll k) -> ll {
    if (k > k0) return 1;
    ll cnt = 0;
    for (ll i = 0; i < k; i++) {
      hist[k] = i;
      bool fail = false;
      for (ll h = 1; h <= k; h++) {
	if (prohib[h][hist[h]][k][i]) {
	  fail = true;
	  break;
	}
      }
      if (!fail) cnt += rF(rF, k+1);
    }
    return cnt;
  };
  ll ans = dfs(dfs, 1);
  cout << ans << endl;

  return 0;
}

