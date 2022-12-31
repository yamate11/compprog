#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

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

  ll H, W; cin >> H >> W;
  vector C(H, vector(W, 0LL));
  vector T(H, vector(W + 1, 0LL));
  vector S(H + 1, vector(W + 1, 0LL));
  REP(i, H) REP(j, W) {
    ll c; cin >> c;
    C[i][j] = ((i + j) % 2 == 0) ? c : -c;
  }
  REP(i, H) REP(j, W) T[i][j + 1] = T[i][j] + C[i][j];
  REP(j, W) REP(i, H) S[i + 1][j + 1] = S[i][j + 1] + T[i][j + 1];
  ll ans = 0;
  REP(i, H) REP(j, W) REP2(k, i + 1, H + 1) REP2(l, j + 1, W + 1) {
    if (S[k][l] + S[i][j] - S[k][j] - S[i][l] == 0) updMax(ans, (k - i) * (l - j));
  }
  cout << ans << endl;

  return 0;
}

