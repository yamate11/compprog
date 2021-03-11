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

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> t(N), v(N);
  for (ll i = 0; i < N; i++) {
    ll x; cin >> x;
    t.at(i) = 2 * x;
  }
  for (ll i = 0; i < N; i++) {
    ll y; cin >> y;
    v.at(i) = 2 * y;
  }
  vector<ll> cumt(N+1);
  for (ll i = 0; i < N; i++) cumt.at(i+1) = cumt.at(i) + t.at(i);
  ll T = cumt.at(N);
  vector<ll> vv(T+1, 1e9);
  for (ll i = 0; i < N; i++) {
    for (ll p = cumt.at(i); p >= 0; p--) {
      updMin(vv.at(p), v.at(i) + (cumt.at(i) - p));
    }
    for (ll p = cumt.at(i+1); p <= T; p++) {
      updMin(vv.at(p), v.at(i) + (p - cumt.at(i+1)));
    }
    for (ll p = cumt.at(i); p <= cumt.at(i+1); p++) {
      updMin(vv.at(p), v.at(i));
    }
  }
  for (ll p = T; p >= 0; p--) {
    updMin(vv.at(p), T-p);
  }
  for (ll p = 0; p <= T; p++) {
    updMin(vv.at(p), p);
  }


  double ans = 0;
  for (ll i = 0; i < T; i++) {
    ans += double(vv.at(i) + vv.at(i+1)) / 8.0;
  }
  cout << ans << endl;

  return 0;
}

