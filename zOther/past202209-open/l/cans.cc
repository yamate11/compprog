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
  // @InpVec(N, A) [62egLrKP]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [62egLrKP]
  vector PLR(N + 1, vector(3, vector(3, 0LL)));
  REP(i, 0, M) {
    ll p, q, l, r; cin >> p >> q >> l >> r; q--;
    PLR[q][l][r] += p;
  }
  vector tbl_init(3, vector(3, -1LL));
  auto tbl = tbl_init;
  REP(i, 0, 3) tbl[0][i] = PLR[0][0][i];
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(j, 0, 3) REP(k, 0, 3) {
      if (prev[j][k] < 0) continue;
      updMax(tbl[j][k], prev[j][k] + PLR[i + 1][j][k]);
      ll j1 = (j + 1) % 3;
      ll k2 = (k + 2) % 3;
      updMax(tbl[j1][k2], prev[j][k] + PLR[i + 1][j1][k2] + A[i]);
    }
  }
  cout << max(tbl[0][0], max(tbl[1][0], tbl[2][0])) << endl;


  return 0;
}

