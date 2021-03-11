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

  vector ch({'O', 'I'});

  ll M, N; cin >> M >> N;
  string S, T; cin >> S >> T;
  vector tbl(2, vector(M+1, vector(N+1, -1LL)));
  auto calc = [&](auto rF, ll t, ll m, ll n) -> ll {
    ll& ret = tbl[t][m][n];
    if (ret < 0) {
      ret = 0;
      if (m < M && S[m] == ch[t]) {
	ll len = rF(rF, 1-t, m+1, n);
	if (len > 0 || t == 1) updMax(ret, 1 + len);
      }
      if (n < N && T[n] == ch[t]) {
	ll len = rF(rF, 1-t, m, n+1);
	if (len > 0 || t == 1) updMax(ret, 1 + len);
      }
    }
    return ret;
  };

  ll ans = 0;
  for (ll t = 0; t < 2; t++) {
    for (ll m = M; m >= 0; m--) {
      for (ll n = N; n >= 0; n--) ans = max(ans, calc(calc, 1, m, n));
    }
  }
  cout << ans << endl;

  return 0;
}

