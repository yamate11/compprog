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

  ll n; cin >> n;
  vector<ll> A(n), B(n);
  ll sumb = 0;
  for (ll i = 0; i < n; i++) {
    cin >> A[i] >> B[i];
    sumb += B[i];
  }
  ll lim = 100 * n;
  vector cur(n + 1, vector(lim + 1, -1e18));
  cur[0][0] = 0;
  for (ll i = 0; i < n; i++) {
    auto prev = cur;
    for (ll j = 0; j < n; j++) {
      for (ll k = 0; k <= lim; k++) {
	if (k + A[i] <= lim) {
	  updMax(cur[j + 1][k + A[i]], prev[j][k] + B[i]);
	}
      }
    }
  }
  for (ll k = 1; k <= n; k++) {
    double ans = 0.0;
    for (ll i = 0; i <= lim; i++) {
      ans = max(ans, min(double(i),
			 double(cur[k][i]) + (sumb - cur[k][i]) / 2.0));
    }
    if (k > 1) cout << " ";
    cout << ans;
  }
  cout << "\n";

  return 0;
}

