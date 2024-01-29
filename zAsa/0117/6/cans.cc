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

  ll r, g, b; cin >> r >> g >> b;
  ll ans = 1e10;
  REP(tg, -500, 201) {
    ll cnt_g = 0;
    REP(i, 0, g) cnt_g += abs(tg + i);
    ll tr = min(-100 - r / 2, tg - r);
    ll cnt_r = 0;
    REP(i, 0, r) cnt_r += abs(tr + i + 100);
    ll tb = max(100 - b / 2, tg + g);
    ll cnt_b = 0;
    REP(i, 0, b) cnt_b += abs(tb + i - 100);
    updMin(ans, cnt_g + cnt_r + cnt_b);
  }
  cout << ans << endl;
  return 0;
}

