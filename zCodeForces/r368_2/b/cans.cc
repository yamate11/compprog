#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m, k; cin >> n >> m >> k;
  using sta = pair<ll, ll>;
  vector<vector<sta>> nbr(n);
  vector<ll> U(m), V(m), L(m);
  for (ll i = 0; i < m; i++) {
    ll u, v, l; cin >> u >> v >> l; u--; v--;
    nbr[u].emplace_back(v, l);
    nbr[v].emplace_back(u, l);
  }
  vector<ll> hasS(n);
  for (ll i = 0; i < k; i++) {
    ll a; cin >> a; a--;
    hasS[a] = true;
  }
  // ll minarg = -1;
  ll lim = 1e10;
  ll minv = lim;
  for (ll i = 0; i < n; i++) {
    if (! hasS[i]) continue;
    for (auto [j, d] : nbr[i]) {
      if (hasS[j]) continue;
      if (d < minv) {
	minv = d;
      }
    }
  }
  cout << (minv == lim ? -1 : minv) << endl;

  return 0;
}

