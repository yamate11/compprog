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

  ll N; cin >> N;
  // @InpVec(N, C) [56UIGMX2]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [56UIGMX2]
  // @InpGrid(N, N, W) [N79iEySg]
  auto W = vector(N, vector(N, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; W[i][j] = v; }
  // @End [N79iEySg]

  ll big = 1LL << 60;
  vector<ll> tbl(1LL << N, big);
  tbl[0] = 0;
  REP(x, 1, 1LL << N) {
    REP(i, 0, N) {
      if (x >> i & 1) {
        ll y = x ^ (1LL << i);
        ll cost = C[i];
        REP(j, 0, N) if (y >> j & 1) cost += W[j][i];
        updMin(tbl[x], tbl[y] + cost);
      }
    }
  }
  cout << tbl[(1LL << N) - 1] << "\n";

  return 0;
}

