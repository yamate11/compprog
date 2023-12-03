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

  ll D; cin >> D;
  ll ans = D;
  REP(y, 0, D + 1) {
    ll e = D - y * y;
    if (e < 0) {
      updMin(ans, abs(e));
      break;
    }
    if (e == 0) {
      updMin(ans, 1LL);
    }else {
      double z = sqrt(e);
      ll x1 = llround(floor(z));
      ll x2 = llround(ceil(z));
      updMin(ans, abs(e - x1 * x1));
      updMin(ans, abs(e - x2 * x2));
    }
  }
  cout << ans << endl;

  return 0;
}

