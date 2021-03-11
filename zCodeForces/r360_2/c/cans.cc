#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

struct MyExc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  vector<ll> rec(n);
  vector<vector<ll>> nbr(n);
  for (ll i = 0; i < m; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  vector<vector<ll>> ans(3);
  auto dfs = [&](auto rF, ll nd, ll p) -> void {
    if (rec[nd] == 0) {
      rec[nd] = p;
      ans[p].push_back(nd);
      for (ll c : nbr[nd]) rF(rF, c, 3 - p);
    }else if (rec[nd] != p) throw MyExc();
  };

  try {
    for (ll i = 0; i < n; i++) {
      if (rec[i] == 0) dfs(dfs, i, 1);
    }
    for (ll i = 1; i <= 2; i++) {
      cout << ans[i].size() << endl;
      for (ll j = 0; j < (ll)ans[i].size(); j++) {
	if (j > 0) cout << " ";
	cout << ans[i][j] + 1;
      }
      cout << endl;
    }
  }catch(const MyExc& e) {
    cout << -1 << endl;
  }


  return 0;
}

