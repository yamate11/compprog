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

  ll R, C, D; cin >> R >> C >> D;
  // @InpGrid(R, C, A) [g3qBKA0r]
  auto A = vector(R, vector(C, ll()));
  for (int i = 0; i < R; i++) for (int j = 0; j < C; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [g3qBKA0r]
  vector vec(R + C - 1, 0LL);
  REP(i, 0, R) REP(j, 0, C) {
    updMax(vec[i + j], A[i][j]);
  }
  ll ans = 0;
  for (ll k = D; k >= 0; k -= 2) if (0 <= k and k < R + C - 1) updMax(ans, vec[k]);
  cout << ans << endl;

  return 0;
}

