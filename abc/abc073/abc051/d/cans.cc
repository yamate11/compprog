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

  ll N, M; cin >> N >> M;
  vector<bool> used(M);
  ll big = 1000 * 1000;
  vector<vector<ll>> dist(N, vector<ll>(N, big));
  vector<ll> A(M), B(M), C(M);
  for (ll i = 0; i < M; i++) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    A.at(i) = a;
    B.at(i) = b;
    C.at(i) = c;
    dist.at(a).at(b) = c;
    dist.at(b).at(a) = c;
  }
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      for (ll k = 0; k < N; k++) {
	updMin(dist.at(j).at(k), dist.at(j).at(i) + dist.at(i).at(k));
      }
    }
  }
  ll cnt = 0;
  for (ll i = 0; i < M; i++) {
    if (C.at(i) > dist.at(A.at(i)).at(B.at(i))) cnt++;
  }
  cout << cnt << endl;

  return 0;
}

