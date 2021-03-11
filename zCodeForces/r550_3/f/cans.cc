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
  using sta = pair<ll, ll>;
  vector<ll> rec(n, -1);
  vector<sta> edges;
  vector<vector<ll>> nbr(n);
  for (ll i = 0; i < m; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    edges.emplace_back(u, v);
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  rec[0] = 0;
  queue<ll> que;
  que.push(0);
  while (!que.empty()) {
    ll x = que.front(); que.pop();
    ll r = 1 - rec[x];
    for (ll y : nbr[x]) {
      if (rec[y] < 0) {
	rec[y] = r;
	que.push(y);
      }else if (rec[y] == r) {
      }else {
	cout << "NO\n";
	return 0;
      }
    }
  }
  cout << "YES\n";
  for (ll i = 0; i < m; i++) {
    auto [u, v] = edges[i];
    cout << rec[u];
  }
  cout << endl;

  return 0;
}

