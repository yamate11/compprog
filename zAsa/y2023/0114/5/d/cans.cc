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
  ll big = 1e18;

  auto f = [&](ll H, ll W, ll C, auto& A) -> ll {
    vector tbl(H, vector(W, big));
    REP(i, 0, H) REP(j, 0, W) {
      if (i > 0) {
        updMin(tbl[i][j], tbl[i - 1][j] + C);
        updMin(tbl[i][j], A[i - 1][j] + C);
      }
      if (j > 0) {
        updMin(tbl[i][j], tbl[i][j - 1] + C);
        updMin(tbl[i][j], A[i][j - 1] + C);
      }
    }
    ll ans = big;
    REP(i, 0, H) REP(j, 0, W) updMin(ans, tbl[i][j] + A[i][j]);
    return ans;
  };


  ll H, W, C; cin >> H >> W >> C;
  // @InpGrid(H, W, A) [uKy5GLv1]
  auto A = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [uKy5GLv1]
  ll x = f(H, W, C, A);
  vector B(H, vector(W, 0LL));
  REP(i, 0, H) REP(j, 0, W) B[i][j] = A[i][W - 1 - j];
  ll y = f(H, W, C, B);
  cout << min(x, y) << endl;

  return 0;
}

