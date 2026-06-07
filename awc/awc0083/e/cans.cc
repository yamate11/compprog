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

  ll big = 1LL << 60;
  ll N, K; cin >> N >> K;
  // @InpVec(N, P) [Azrr0h3v]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [Azrr0h3v]
  // @InpGrid(N, N, C) [aRMJSoFO]
  auto C = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; C[i][j] = v; }
  // @End [aRMJSoFO]

  vector tbl(1LL << N, vector(N, vector(N, -big)));
  REP(i, 0, N) tbl[1LL << i][i][i] = P[i];
  REP(x, 0, 1LL << N) REP(a, 0, N) REP(t, 0, N) {
    if (popcount((u64)x) < K and tbl[x][a][t] > -big) {
      REP(s, 0, N) if (not (x >> s & 1)) {
        updMax(tbl[x | (1LL << s)][a][s], tbl[x][a][t] + P[s] + C[t][s]);
      }
    }
  }
  ll ans = -big;
  REP(x, 0, 1LL << N) REP(a, 0, N) REP(t, 0, N) {
    if (popcount((u64)x) == K and tbl[x][a][t] > -big) updMax(ans, tbl[x][a][t] + C[a][t]);
  }
  cout << ans << endl;
  return 0;
}

