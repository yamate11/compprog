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
  vector<vector<ll>> nbr(n);
  for (ll i = 0; i < n - 1; i++) {
    ll x, y; cin >> x >> y; x--; y--;
    nbr[x].push_back(y);
    nbr[y].push_back(x);
  }
  vector<ll> col(n);
  ll vmax = 0;
  auto dfs = [&](auto rF, ll nd, ll pnt, ll c) -> void {
    col[nd] = c;
    ll pcol = pnt == -1 ? -1 : col[pnt];
    ll t = 0;
    for (ll cld : nbr[nd]) {
      if (cld == pnt) continue;
      while (t == c || t == pcol) t++;
      vmax = max(vmax, t);
      rF(rF, cld, nd, t);
      t++;
    }
  };
  dfs(dfs, 0, -1, 0);
  cout << vmax + 1 << endl;
  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << col[i] + 1;
  }
  cout << endl;
  return 0;
}

