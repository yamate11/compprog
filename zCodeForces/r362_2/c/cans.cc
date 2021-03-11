#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  map<ll, ll> mp;

  ll q; cin >> q;
  for (ll _q = 0; _q < q; _q++) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll v, u, w; cin >> v >> u >> w;
      while (v != u) {
	if (v > u) {
	  mp[v] += w;
	  v >>= 1;
	}else if (u > v) {
	  mp[u] += w;
	  u >>= 1;
	}
      }
    }else if (tp == 2) {
      ll v, u; cin >> v >> u;
      ll cost = 0;
      while (v != u) {
	if (v > u) {
	  cost += mp[v];
	  v >>= 1;
	}else if (u > v) {
	  cost += mp[u];
	  u >>= 1;
	}
      }
      cout << cost << "\n";
    }
  }


  return 0;
}

