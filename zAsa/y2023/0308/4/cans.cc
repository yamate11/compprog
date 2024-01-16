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

// @@ !! LIM(input f:updMaxMin)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

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
  // @InpGrid(10, 10, C) [Av5WsXYB]
  auto C = vector(10, vector(10, ll()));
  for (int i = 0; i < 10; i++) for (int j = 0; j < 10; j++) { ll v; cin >> v; C[i][j] = v; }
  // @End [Av5WsXYB]
  // @InpGrid(H, W, A) [nwCywjzn]
  auto A = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [nwCywjzn]
  REP(k, 0, 10) REP(i, 0, 10) REP(j, 0, 10) updMin(C[i][j], C[i][k] + C[k][j]);
  ll ans = 0;
  REP(i, 0, H) REP(j, 0, W) {
    ll a = A[i][j];
    if (a == -1) continue;
    ans += C[a][1];
  }
  cout << ans << endl;

  return 0;
}

