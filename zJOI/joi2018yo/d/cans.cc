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

  ll N; cin >> N;
  vector L(N, 0LL), acc(N+1, 0LL);
  for (ll i = 0; i < N; i++) {
    cin >> L[i];
    acc[i + 1] = acc[i] + L[i];
  }
  ll tot = acc[N];
  
  ll big = 1e9;
  vector cur(tot + 1, vector(N+1, big));
  for (ll i = 1; i <= N; i++) {
    vector prev = move(cur);
    cur = vector(tot + 1, vector(N+1, big));
    if (i < N) updMin(cur[acc[i]][i], acc[i]);
    for (ll x = 0; x <= tot; x++) {
      for (ll b = 0; b < i; b++) {
	updMin(cur[x][b], prev[x][b]);
	ll w = acc[i] - acc[b];
	ll y = prev[x][b];
	if (x <= w && w <= y) {
	  updMin(cur[x][i], y);
	}else if (w < x) {
	  updMin(cur[w][i], y);
	}else {
	  updMin(cur[x][i], w);
	}
      }
    }
  }
  ll ans = big;
  for (ll x = 1; x <= tot; x++) {
    ans = min(ans, cur[x][N] - x);
  }
  cout << ans << endl;

  return 0;
}

