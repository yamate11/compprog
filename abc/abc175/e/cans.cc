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

  ll R, C, K; cin >> R >> C >> K;
  // using sta = pair<ll, ll>;
  // map<sta, ll> mp;
  vector val(R, vector(C, 0LL));
  for (ll i = 0; i < K; i++) {
    ll r, c, v; cin >> r >> c >> v; r--; c--;
    val[r][c] = v;
  }
  vector tbl(R+1, vector(C+1, vector(4, 0LL)));
  for (ll r = 0; r <= R; r++) {
    for (ll c = 0; c <= C; c++) {
      for (ll p = 0; p <= 3; p++) {
	ll cur = tbl[r][c][p];
	ll v = (r < R && c < C) ? val[r][c] : 0;
	if (r+1 <= R) updMax(tbl[r+1][c][0], cur);
	if (c+1 <= C) updMax(tbl[r][c+1][p], cur);
	if (v > 0 && p < 3) {
	  if (r+1 <= R) updMax(tbl[r+1][c][0], cur + v);
	  if (c+1 <= C) updMax(tbl[r][c+1][p+1], cur + v);
	}
      }
    }
  }
  cout << tbl[R][C][0] << endl;

  return 0;
}

