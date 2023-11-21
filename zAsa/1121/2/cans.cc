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

  string S; cin >> S;
  ll N = SIZE(S);
  ll K = 4;
  ll big = 1e18;
  vector tbl(N, vector(K + 1, -big));
  tbl[0][1] = 1;
  REP(i, 1, N) {
    REP(j, 1, K + 1) {
      REP(k, 1, K + 1) {
        if (j != k and i - j >= 0) updMax(tbl[i][j], tbl[i - j][k] + 1);
        else if (i - 2 * j + 1 >= 0 and S.substr(i - j + 1, j) != S.substr(i - 2 * j + 1, j)) updMax(tbl[i][j], tbl[i - j][k] + 1);
      }
    }
  }
  ll ans = 0;
  REP(i, 1, K + 1) updMax(ans, tbl[N - 1][i]);
  cout << ans << endl;

  return 0;
}

