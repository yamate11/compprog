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

  string S, T; cin >> S >> T;
  ll K; cin >> K;
  ll N = ssize(S);
  ll M = ssize(T);
  vector tbl(K + 1, vector(N + 1, vector(M + 1, 0LL)));
  REP(k, 0, K + 1) REP(i, 0, N) REP(j, 0, M) {
    if (S[i] == T[j]) {
      updMax(tbl[k][i + 1][j + 1], tbl[k][i][j] + 1);
    }else {
      updMax(tbl[k][i + 1][j + 1], max(tbl[k][i + 1][j], tbl[k][i][j + 1]));
      if (k + 1 < K + 1) {
        updMax(tbl[k + 1][i + 1][j + 1], tbl[k][i][j] + 1);
      }
    }
  }
  ll ans = 0;
  REP(k, 0, K + 1) updMax(ans, tbl[k][N][M]);
  cout << ans << endl;

  return 0;
}

