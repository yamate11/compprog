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

  ll N, K; cin >> N >> K;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  ll lim = 40;
  auto tbl_init = vector(2, -1LL);
  auto tbl = tbl_init;
  tbl[0] = 0;
  tbl[1] = -1;
  for (ll i = lim - 1; i >= 0; i--) {
    vector<ll> cnt(2);
    for (ll j = 0; j < N; j++) cnt[(A[j] >> i) & 1]++;
    auto prev = move(tbl);
    tbl = tbl_init;
    for (ll f = 0; f < 2; f++) {
      if (prev[f] < 0) continue;
      for (ll x = 0; x <= 1; x++) {
        ll f0 = f;
        if (f == 0) {
          ll d = (K >> i) & 1;
          if (x > d) continue;
          if (x < d) f0 = 1;
        }
        updMax(tbl[f0], 2 * prev[f] + cnt[1 - x]);
      }
    }
  }
  cout << max(tbl[0], tbl[1]) << endl;

  return 0;
}

