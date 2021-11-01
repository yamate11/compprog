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

  ll H, W; cin >> H >> W;
  vector A(H, vector(W, 0LL));
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) cin >> A[i][j];
  }
  vector tbl(H, vector(W, vector(H+W, -1LL)));
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      if (i == 0 && j == 0) {
        tbl[0][0][0] = 0;
        tbl[0][0][1] = A[0][0];
        continue;
      }
      if (i > 0) {
        for (ll k = 0; k < H+W; k++) {
          if (tbl[i-1][j][k] >= 0) {
            updMax(tbl[i][j][k], tbl[i-1][j][k]);
          }
        }
        for (ll k = 1; k < H+W; k++) {
          if (tbl[i-1][j][k-1] >= 0) {
            updMax(tbl[i][j][k], tbl[i-1][j][k-1] + A[i][j]);
          }
        }
      }
      if (j > 0) {
        for (ll k = 0; k < H+W; k++) {
          if (tbl[i][j-1][k] >= 0) {
            updMax(tbl[i][j][k], tbl[i][j-1][k]);
          }
        }
        for (ll k = 1; k < H+W; k++) {
          if (tbl[i][j-1][k-1] >= 0) {
            updMax(tbl[i][j][k], tbl[i][j-1][k-1] + A[i][j]);
          }
        }
      }
    }
  }
  for (ll k = 1; k < H+W; k++) {
    cout << tbl[H-1][W-1][k] << "\n";
  }

  return 0;
}

