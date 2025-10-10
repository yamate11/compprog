#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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

  ll H, W, C; cin >> H >> W >> C;

  auto f = [&](const auto&A) -> ll {
    ll big = 1e18;
    vector tbl(H, vector(W, big));
    ll ans = big;
    REP(i, 0, H) REP(j, 0, W) {
      if (i == 0 and j == 0) {
        tbl[0][0] = A[0][0];
      }else {
        if (i > 0) updMin(tbl[i][j], tbl[i - 1][j] + C);
        if (j > 0) updMin(tbl[i][j], tbl[i][j - 1] + C);
        updMin(ans, tbl[i][j] + A[i][j]);
        updMin(tbl[i][j], A[i][j]);
      }
    }
    return ans;
  };

  // @InpGrid(H, W, A) [cIzj5vTu]
  auto A = vector(H, vector(W, ll()));
  for (int i = 0; i < H; i++) for (int j = 0; j < W; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [cIzj5vTu]

  ll ans1 = f(A);
  REP(i, 0, H) reverse(ALL(A[i]));
  ll ans2 = f(A);
  cout << min(ans1, ans2) << endl;


  return 0;
}

