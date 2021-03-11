#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<ll> col(n);
  vector<bool> red(n), blue(n);
  ll root = -1;
  for (ll i = 0; i < n; i++) {
    ll c; cin >> c;
    col[i] = c;
    if (c == 1) root = i;
  }
  vector<vector<ll>> nbr(n);
  for (ll i = 0; i < n-1; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  auto dfs1 = [&](auto rF, ll nd, ll p) -> void {
    if (col[nd] == 1) red[nd] = true;
    if (col[nd] == 2) blue[nd] = true;
    for (ll c : nbr[nd]) {
      if (c == p) continue;
      rF(rF, c, nd);
      red[nd] = red[nd] || red[c];
      blue[nd] = blue[nd] || blue[c];
    }
  };
  dfs1(dfs1, root, -1);
  ll cnt = 0;
  auto dfs2 = [&](auto rF, ll nd, ll p) -> void {
    if (col[nd] == 2) return;
    ll nb = 0;
    ll c0 = -1;
    for (ll c : nbr[nd]) {
      if (c == p) continue;
      if (blue[c]) {
	c0 = c;
	nb++;
      }
    }
    if (nb >= 2) return;
    assert(nb == 1);
    if (!red[c0]) cnt++;
    rF(rF, c0, nd);
  };
  dfs2(dfs2, root, -1);
  cout << cnt << endl;

  return 0;
}

