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

  ll X, Y; cin >> X >> Y;
  vector tbl(X + 1, vector(Y + 1, -1LL));
  tbl[X][Y] = 0LL;
  ll N; cin >> N;
  REP(i, 0, N) {
    ll t, h; cin >> t >> h;
    REP(x, 0, X + 1) REP(y, 0, Y + 1) {
      if (tbl[x][y] >= 0) {
        if (x + y >= t and x >= 1) {
          ll x0, y0;
          if (y >= t - 1) { x0 = 1; y0 = t - 1; }
          else { y0 = y; x0 = t - y; }
          updMax(tbl[x - x0][y - y0], tbl[x][y] + h);
        }
      }
    }
  }
  ll ans = 0;
  REP(x, 0, X + 1) REP(y, 0, Y + 1) updMax(ans, tbl[x][y]);
  cout << ans << endl;

  return 0;
}

