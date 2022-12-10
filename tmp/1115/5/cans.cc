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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

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

  ll W; cin >> W;
  ll N, K; cin >> N >> K;
  // @InpMVec(N, (A, B)) [FEcEy86J]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [FEcEy86J]
  ll big = 1e18;
  vector tbl_init(K + 1, vector(W + 1, -big));
  auto tbl = tbl_init;
  tbl[0][0] = 0;
  REP(i, 0, N) {
    auto prev = tbl;
    REP(k, 0, K) REP(w, 0, W) {
      if (prev[k][w] < 0) continue;
      if (w + A[i] <= W) updMax(tbl[k + 1][w + A[i]], prev[k][w] + B[i]);
    }
  }
  ll ans = 0;
  REP(k, 0, K + 1) REP(w, 0, W + 1) ans = max(ans, tbl[k][w]);
  cout << ans << endl;


  return 0;
}

