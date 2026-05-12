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

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [6k5jQ1bj]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [6k5jQ1bj]

  ll big = 1e18;
  vector fmax(N, vector(N + 1, 0LL));
  vector fmin(N, vector(N + 1, big));
  REP(i, 0, N) fmax[i][i + 1] = fmin[i][i + 1] = A[i];
  REP(i, 0, N) REP(j, i + 2, N + 1) {
    fmax[i][j] = max(fmax[i][j - 1], A[j - 1]);
    fmin[i][j] = min(fmin[i][j - 1], A[j - 1]);
  }

  vector tbl(N + 1, vector<ll>(K + 1, big));
  tbl[0][0] = 0;
  REP(i, 0, N) {
    REP(k, 0, K) {
      if (tbl[i][k] < big) {
        REP(j, i + 1, N + 1) {
          ll vmax = fmax[i][j];
          ll vmin = fmin[i][j];
          updMin(tbl[j][k + 1], tbl[i][k] + vmax - vmin);
        }
      }
    }
  }
  cout << tbl[N][K] << endl;

  return 0;
}

