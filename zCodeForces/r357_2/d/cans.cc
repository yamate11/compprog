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
  vector<vector<ll>> child(n);
  vector<ll> parent(n, -1LL);
  for (ll i = 0; i < m; i++) {
    ll p, q; cin >> p >> q; p--; q--;
    parent[q] = p;
    child[p].push_back(q);
  }
  vector<ll> giveto(n);
  for (ll i = 0; i < n; i++) {
    ll x; cin >> x; x--;
    giveto[i] = x;
  }
  vector<ll> ans;
  auto dfs = [&](auto rF, int nd, int target) -> void {
    if (giveto[nd] == target) {
      for (ll x : child[nd]) rF(rF, x, target);
    }else if (giveto[nd] == nd) {
      rF(rF, nd, nd);
      ans.push_back(nd);
    }else {
      throw MyExc();
    }
  };
  try {
    for (ll i = 0; i < n; i++) {
      if (parent[i] == -1) {
	dfs(dfs, i, i);
	ans.push_back(i);
      }
    }
    cout << ans.size() << "\n";
    for (ll a : ans) cout << a + 1 << "\n";
  }catch (const MyExc& e) {
    cout << -1 << endl;
  }


  return 0;
}

