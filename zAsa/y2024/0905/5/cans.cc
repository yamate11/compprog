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
  // @InpVec(N, A) [CihSvZja]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [CihSvZja]
  // @InpVec(M, B) [xHhCQtwD]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
  // @End [xHhCQtwD]

  ll big = 1e18;
  vector tbl(N + 1, vector(M + 1, big));
  tbl[0][0] = 0;
  REP(n, 0, N + 1) REP(m, 0, M + 1) {
    ll val = tbl[n][m];
    if (m + 1 <= M) updMin(tbl[n][m + 1], val + 1);
    if (n + 1 <= N) updMin(tbl[n + 1][m], val + 1);
    if (n + 1 <= N and m + 1 <= M) {
      if (A[n] == B[m]) updMin(tbl[n + 1][m + 1], tbl[n][m]);
      else              updMin(tbl[n + 1][m + 1], tbl[n][m] + 1);
    }
  }
  cout << tbl[N][M] << endl;

  return 0;
}

