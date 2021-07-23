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

  ll H, W, C; cin >> H >> W >> C;
  auto A = vector(H, vector(W, 0LL));
  for (ll i = 0; i < H; i++) for (ll j = 0; j < W; j++) cin >> A[i][j];
  ll big = 1e15;
  auto func = [&](ll bgW, ll enW, ll diffW) -> ll {
    auto tbl = vector(H, vector(W, big));
    tbl[0][bgW] = A[0][bgW];
    ll ret = big;
    for (ll i = 0; i < H; i++) {
      for (ll j = bgW; j != enW; j += diffW) {
        if (i - 1 >= 0) updMin(tbl[i][j], tbl[i - 1][j] + C);
        if (j != bgW) updMin(tbl[i][j], tbl[i][j - diffW] + C);
        if (! (i == 0 && j == bgW)) updMin(ret, tbl[i][j] + A[i][j]);
        updMin(tbl[i][j], A[i][j]);
      }
    }
    return ret;
  };
  ll ans = min(func(0, W, 1), func(W-1, -1, -1));
  cout << ans << endl;
  return 0;
}

