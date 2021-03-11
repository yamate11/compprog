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

  ll n, k, x; cin >> n >> k >> x;
  vector tbl(n + 1, vector(x + 1, vector(k, -1LL)));
  tbl[0][0][0] = 0;
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    for (ll j = 0; j <= x; j++) {
      for (ll p = 0; p < k; p++) {
	if (tbl[i][j][p] < 0) continue;
	if (p+1 < k) updMax(tbl[i+1][j][p+1], tbl[i][j][p]);
	if (j+1 <= x) updMax(tbl[i+1][j+1][0], tbl[i][j][p] + a);
      }
    }
  }
  ll ans = -1;
  for (ll p = 0; p < k; p++) ans = max(ans, tbl[n][x][p]);
  cout << ans << endl;


  return 0;
}

