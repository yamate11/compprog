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

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [LYLGCqM4]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [LYLGCqM4]
  // @InpVec(M, B) [3K2Tp5wl]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [3K2Tp5wl]
  vector tbl(N + 1, vector(M + 1, 0LL));
  REP(i, 0, N + 1) tbl[i][0] = i;
  REP(j, 0, M + 1) tbl[0][j] = j;
  REP(i, 1, N + 1) REP(j, 1, M + 1) {
    tbl[i][j] = LLONG_MAX;
    updMin(tbl[i][j], tbl[i - 1][j] + 1);
    updMin(tbl[i][j], tbl[i][j - 1] + 1);
    updMin(tbl[i][j], tbl[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 0 : 1));
  }
  cout << tbl[N][M] << endl;

  return 0;
}

