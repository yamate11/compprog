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

  u64 big = 4e18;
  ll K = 64;
  vector tbl(K, vector(K, big));
  tbl[0][0] = 0;
  REP(k, 1, 61) {
    auto prev = tbl;
    REP(i, 0, K) REP(j, 0, K) {
      if (prev[i][j] == big) continue;
      if (i + k < K) updMin(tbl[i + k][j], prev[i][j] + (1ULL << k));
      if (j + k < K) updMin(tbl[i][j + k], prev[i][j] + (1ULL << k));
    }
  }

  auto solve = [&]() -> void {
    u64 x, y; cin >> x >> y;
    /*
    ll x0 = x == 0 ? 0 : bit_width(x);
    ll y0 = y == 0 ? 0 : bit_width(y);
    */
    u64 ans = big;
    REP(i, 0, K) REP(j, 0, K) {
      if ((x >> i) == (y >> j)) updMin(ans, tbl[i][j]);
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

