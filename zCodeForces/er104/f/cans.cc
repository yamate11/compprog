#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(f:intDiv f:updMaxMin)

// ---- inserted function f:intDiv from util.cc
// imod, divFloor, divCeil

// imod(x, y) : remainder of x for y
// for y > 0:
//   imod(x, y)  = r where x = dy + r, 0 <= r < y
//   imod(x, -y) = r where x = dy + r, 0 >= r > y
// Thus, imod( 10,  7) =  3
//       imod(-10,  7) =  4
//       imod( 10, -7) = -4
//       imod(-10, -7) = -3
ll imod(ll x, ll y) {
  ll v = x % y;
  if ((x >= 0) == (y >= 0)) return v;
  else                      return v == 0 ? 0 : v + y;
}

// Integer Division; regardless pos/neg
ll divFloor(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return x / y;
    else       return (x - y - 1) / y;
  }else {
    if (y > 0) return (x - y + 1) / y;
    else       return x / y;
  }
}

ll divCeil(ll x, ll y) {
  if (x > 0) {
    if (y > 0) return (x + y - 1) / y;
    else       return x / y;
  }else {
    if (y > 0) return x / y;
    else       return (x + y + 1) / y;
  }
}
//   Just a note.  For d \in Z and t \in R,
//       d < t <=> d < ceil(t),     d <= t <=> d <= floor(t),
//       d > t <=> d > floor(t),    d >= t <=> d >= ceil(t).

// ---- end f:intDiv

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

  string N; cin >> N;
  reverse(ALL(N));
  N += "0";
  ll big = 1e18;
  ll limN = 5 * N.size();
  ll limC = divCeil(limN, 9);
  auto acc = [&](auto& tb, ll carry, ll cp, ll cn) -> ll& {
    return tb[carry + limC][cp][cn];
  };
  vector tbl_init(2 * limC + 1, vector(limN, vector(limN, big)));
  auto tbl = tbl_init;
  REP(cp, limN) REP(cn, limN) acc(tbl, 0, cp, cn) = 0;
  for (char dd : N) {
    int d = dd - '0';
    auto prev = move(tbl);
    tbl = tbl_init;
    REP2(carry, -limC, limC + 1) REP(cp, limN) REP(cn, limN) {
      ll pval = acc(prev, carry, cp, cn);
      ll diff = (carry + cp - cn) - d;
      if (pval < big and diff % 10 == 0) updMin(acc(tbl, diff / 10, cp, cn), pval + cp + cn);
    }
    REP2(carry, -limC, limC+1) REP2R(cp, limN-1, 0) REP2R(cn, limN-1, 0) {
      if (cp > 0) updMin(acc(tbl, carry, cp-1, cn), acc(tbl, carry, cp, cn));
      if (cn > 0) updMin(acc(tbl, carry, cp, cn-1), acc(tbl, carry, cp, cn));
    }
  }
  ll ans = big;
  REP(cp, limN) REP(cn, limN) updMin(ans, acc(tbl, 0, cp, cn));
  cout << ans << endl;


  return 0;
}

