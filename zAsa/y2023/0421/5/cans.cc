#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

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
  // @InpGrid(H, W, C) [bRbq5Ucv]
  auto C = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; C[i][j] = v; }
  // @End [bRbq5Ucv]
  vector S(H + 1, vector(W + 1, 0LL));
  REP(i, 0, H) REP(j, 0, W) {
    if ((i + j) % 2 != 0) S[i + 1][j + 1] = -C[i][j];
    else S[i + 1][j + 1] = C[i][j];
  }
  REP(i, 1, H + 1) REP(j, 1, W + 1) S[i][j] += S[i][j - 1];
  REP(i, 1, H + 1) REP(j, 1, W + 1) S[i][j] += S[i - 1][j];
  ll ans = 0;
  REP(i1, 0, H) REP(j1, 0, W) REP(i2, i1 + 1, H + 1) REP(j2, j1 + 1, W + 1) {
    if (S[i2][j2] + S[i1][j1] - S[i1][j2] - S[i2][j1] == 0) updMax(ans, (i2 - i1) * (j2 - j1));
  }
  cout << ans << endl;

  return 0;
}

