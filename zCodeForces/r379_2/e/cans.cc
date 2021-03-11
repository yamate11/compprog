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
  vector<int> color(n);
  for (ll i = 0; i < n; i++) cin >> color[i];
  vector<vector<ll>> onbr(n);
  for (ll i = 0; i < n - 1; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    onbr[u].push_back(v);
    onbr[v].push_back(u);
  }
  ll seq = 0;
  vector<vector<ll>> nbr(n);
  auto dfs1 = [&](auto rF, ll nd, ll par, ll par_seq) -> void {
    ll my_seq = -1;
    if (par >= 0 && color[nd] == color[par]) {
      my_seq = par_seq;
    }else {
      my_seq = seq++;
      if (par_seq >= 0) {
	nbr[par_seq].push_back(my_seq);
	nbr[my_seq].push_back(par_seq);
      }
    }
    for (ll cld : onbr[nd]) {
      if (cld == par) continue;
      rF(rF, cld, nd, my_seq);
    }
  };
  dfs1(dfs1, 0, -1, -1);
  auto dfs2 = [&](auto rF, ll nd, ll par) -> pair<ll, ll> {
    ll dmax = 0;
    ll idx = -1;
    for (ll cld : nbr[nd]) {
      if (cld == par) continue;
      auto [d, i] = rF(rF, cld, nd);
      if (d > dmax) {
	dmax = d;
	idx = i;
      }
    }
    if (idx == -1) return make_pair(1, nd);
    return make_pair(dmax + 1, idx);
  };
  auto [dummy, p] = dfs2(dfs2, 0, -1);
  auto [dist,  q] = dfs2(dfs2, p, -1);
  cout << dist / 2 << endl;

  return 0;
}

