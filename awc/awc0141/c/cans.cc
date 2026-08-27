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

  ll N, M; cin >> N >> M;
  // @InpGrid(N, M, G) [O1gPtxco]
  auto G = vector(N, vector(M, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; G[i][j] = v; }
  // @End [O1gPtxco]

  vector tbl_init(3, vector(M, 0LL));
  auto tbl = tbl_init;
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(j, 0, M) {
      REP(k, 0, 3) {
        if (k == 0) {
          updMax(tbl[1][j], prev[k][j] + G[i][j]);
          if (j + 1 < M) updMax(tbl[2][j + 1], prev[k][j] + G[i][j + 1]);
        }else if (k == 1) {
          if (j - 1 >= 0) updMax(tbl[0][j - 1], prev[k][j] + G[i][j - 1]);
          updMax(tbl[1][j], prev[k][j] + G[i][j]);
          if (j + 1 < M) updMax(tbl[2][j + 1], prev[k][j] + G[i][j + 1]);
        }else if (k == 2) {
          if (j - 1 >= 0) updMax(tbl[0][j - 1], prev[k][j] + G[i][j - 1]);
          updMax(tbl[1][j], prev[k][j] + G[i][j]);
        }
      }
    }
  }
  ll ans = 0;
  REP(j, 0, M) REP(k, 0, 3) updMax(ans, tbl[k][j]);
  cout << ans << "\n";

  return 0;
}

