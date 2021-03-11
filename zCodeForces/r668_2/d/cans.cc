#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:updMaxMin)
// --> f:updMaxMin
// ---- inserted function updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end updMaxMin
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll n, a, b, da, db; cin >> n >> a >> b >> da >> db; a--; b--;
    vector<vector<ll>> nbr(n);
    for (ll i = 0; i < n - 1; i++) {
      ll u, v; cin >> u >> v; u--; v--;
      nbr[u].push_back(v);
      nbr[v].push_back(u);
    }
    ll big = 1e9;
    auto nDist = [&](auto rF, ll m, ll p, ll goal) -> ll {
      if (m == goal) return 0;
      for (ll c : nbr[m]) {
	if (c == p) continue;
	ll x = rF(rF, c, m, goal);
	if (x < big) return x + 1;
      }
      return big;
    };
    auto farthest = [&](auto rF, ll m, ll p) -> pair<ll, ll> {
      ll len = 0;
      ll x = m;
      for (ll c : nbr[m]) {
	if (c == p) continue;
	auto [thisLen, q] = rF(rF, c, m);
	thisLen ++;
	if (thisLen > len) {
	  len = thisLen;
	  x = q;
	}
      }
      return {len, x};
    };
    if (nDist(nDist, a, -1, b) <= da) {
      cout << "Alice\n";
      return;
    }
    auto [dummy, x1] = farthest(farthest, 0, -1);
    auto [diam, x2] = farthest(farthest, x1, -1);
    db = min(db, diam);
    if (db >= 2 * da + 1) {
      cout << "Bob\n";
    }else {
      cout << "Alice\n";
    }
    
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

