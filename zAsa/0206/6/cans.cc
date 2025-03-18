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
  // @InpVec(N, A) [10XHzWw0]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [10XHzWw0]

  ll big = 1e18;
  vector tbl_init(2, vector(M + 1, big));
  auto tbl = tbl_init;
  tbl[0][0] = 1;
  tbl[1][A[0]] = 0;
  REP(i, 1, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(m, 0, M + 1) {
      updMin(tbl[0][m], prev[0][m]);
      if (m + A[i] <= M) updMin(tbl[1][m + A[i]], prev[0][m]);
      updMin(tbl[0][m], prev[1][m] + 1);
      if (m + A[i] <= M) updMin(tbl[1][m + A[i]], prev[1][m]);
    }
  }
  REP(m, 1, M + 1) {
    ll e = min(tbl[0][m], tbl[1][m]);
    if (e >= big) cout << -1 << "\n";
    else cout << e << "\n";
  }

  return 0;
}

