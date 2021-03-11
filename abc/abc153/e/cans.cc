#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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

  ll H, N; cin >> H >> N;
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
  }
  ll big = 1e10;
  vector cur(H + 1, big);
  cur[0] = 0;
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < H; j++) {
      ll t = min(H, j + A[i]);
      updMin(cur[t], cur[j] + B[i]);
    }
  }
  cout << cur[H] << endl;

  return 0;
}

