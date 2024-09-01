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
  // @InpVec(N, A) [4Y1Bz9S6]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [4Y1Bz9S6]

  vector tbl_init(2, vector(M + 1, -1LL));
  auto tbl = tbl_init;
  tbl[0][0] = 0;
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(b, 0, 2) REP(j, 0, M + 1) {
      ll prev_val = prev[b][j];
      if (prev_val < 0) continue;
      updMax(tbl[0][j], prev_val + A[i]);
      if (b == 0 and j + 1 <= M) updMax(tbl[1][j + 1], prev_val);
    }
  }
  ll ans = max(tbl[0][M], tbl[1][M]);
  cout << ans << endl;

  return 0;
}

