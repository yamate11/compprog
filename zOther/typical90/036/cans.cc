#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(f:updMaxMin)

// ---- inserted function f:updMaxMin from util.cc
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
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  ll s0 = LLONG_MIN;
  ll s1 = LLONG_MIN;
  ll s2 = LLONG_MIN;
  ll s3 = LLONG_MIN;

  vector<ll> X(N + 1), Y(N + 1);
  for (ll i = 1; i <= N; i++) {
    ll x, y; cin >> x >> y;
    X[i] = x;
    Y[i] = y;
    updMax(s0, x + y);
    updMax(s1, x - y);
    updMax(s2, -x + y);
    updMax(s3, -x - y);
  }
  for (ll q = 0; q < Q; q++) {
    ll i; cin >> i;
    ll ans = LLONG_MIN;
    updMax(ans, s0 - ( X[i] + Y[i]));
    updMax(ans, s1 - ( X[i] - Y[i]));
    updMax(ans, s2 - (-X[i] + Y[i]));
    updMax(ans, s3 - (-X[i] - Y[i]));
    cout << ans << "\n";
  }

  return 0;
}

