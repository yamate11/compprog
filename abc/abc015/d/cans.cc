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

  ll W; cin >> W;
  ll N, K; cin >> N >> K;
  // vector<ll> A(N), B(N);
  using Vec1 = vector<ll>;
  using Vec2 = vector<Vec1>;
  using Vec3 = vector<Vec2>;
  Vec3 dp(N+1, Vec2(K+1, Vec1(W+1, 0)));
  dp.at(0).at(0).at(0) = 0;
  for (ll i = 0; i < N; i++) {
    ll a, b; cin >> a >> b;
    for (ll j = 0; j <= K; j++) {
      for (ll k = 0; k <= W; k++) {
	updMax(dp.at(i+1).at(j).at(k), dp.at(i).at(j).at(k));
	if (j+1 <= K && k+a <= W) {
	  updMax(dp.at(i+1).at(j+1).at(k+a), dp.at(i).at(j).at(k) + b);
	}
      }
    }
  }
  ll vmax = 0;
  for (ll j = 0; j <= K; j++) {
    for (ll k = 0; k <= W; k++) {
      ll x = dp.at(N).at(j).at(k);
      if (x >= 1e10) continue;
      updMax(vmax, x);
    }
  }
  cout << vmax << endl;

  return 0;
}

