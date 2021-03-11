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
  ll gr = 0;
  for (ll i = 0; i < N; i++) {
    vector<ll> sz(3);
    for (ll j = 0; j < 3; j++) cin >> sz.at(j);
    ll M; cin >> M;
    vector<ll> vMax(3, -1), vMin(3, (ll)(1e9+10));
    for (ll k = 0; k < M; k++) {
      for (ll j = 0; j < 3; j++) {
	ll p; cin >> p;
	updMax(vMax.at(j), p);
	updMin(vMin.at(j), p);
      }
    }
    for (ll j = 0; j < 3; j++) {
      gr ^= (sz.at(j) - 1 - vMax.at(j)) ^ (vMin.at(j));
    }
  }
  cout << (gr ? "WIN" : "LOSE") << endl;

  return 0;
}

