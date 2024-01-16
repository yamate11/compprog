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

// @@ !! LIM(f:updMaxMin f:perfmeas)

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

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

/*
#define RCK

string label = "mylabel";

#if defined(RCK)
#  define VDEF vector tbl(R, vector(C, vector(4, 0LL)));
#  define LOOP LOOP_R LOOP_C LOOP_K
#  define TBL(r, c, k) tbl[r][c][k]
#elif defined(RKC)
#  define VDEF vector tbl(R, vector(4, vector(C, 0LL)));
#  define LOOP LOOP_R LOOP_K LOOP_C
#  define TBL(r, c, k) tbl[r][k][c]
#elif defined(CRK)
#  define VDEF vector tbl(C, vector(R, vector(4, 0LL)));
#  define LOOP LOOP_C LOOP_R LOOP_K
#  define TBL(r, c, k) tbl[c][r][k]
#elif defined(CKR)
#  define VDEF vector tbl(C, vector(4, vector(R, 0LL)));
#  define LOOP LOOP_C LOOP_K LOOP_R
#  define TBL(r, c, k) tbl[c][k][r]
#elif defined(KRC)
#  define VDEF vector tbl(4, vector(R, vector(C, 0LL)));
#  define LOOP LOOP_K LOOP_R LOOP_C
#  define TBL(r, c, k) tbl[k][r][c]
#elif defined(KCR)
#  define VDEF vector tbl(4, vector(C, vector(R, 0LL)));
#  define LOOP LOOP_K LOOP_C LOOP_R
#  define TBL(r, c, k) tbl[k][c][r]
#endif
*/

#define LOOP_R REP(r, 0, R)
#define LOOP_C REP(c, 0, C)
#define LOOP_K REP(k, 0, 4)

#include "myinc.h"

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(6);

  ll R, C, K; cin >> R >> C >> K;
  /*
  vector vals(R, vector(C, 0LL));
  REP(i, 0, K) {
    ll r, c, v; cin >> r >> c >> v; r--; c--;
    vals[r][c] = v;
  }
  */
  double t0 = get_time_sec();
  VDEF
  ll ans = 0;
  LOOP {
    // ll v = vals[r][c];
    ll v = 0;
    if ((r & 0x1f) == 1 and (c & 0x1f) == 1) v = (r >> 5) + (c >> 5);
    ll w = TBL(r, c, k);
    if (r + 1 < R) {
      updMax(TBL(r + 1, c, 0), w);
      if (k < 3) updMax(TBL(r + 1, c, 0), w + v);
    }
    if (c + 1 < C) {
      updMax(TBL(r, c + 1, k), w);
      if (k < 3) updMax(TBL(r, c + 1, k + 1), w + v);
    }
    if (r + 1 == R and c + 1 == C) {
      updMax(ans, w);
      if (k < 3) updMax(ans, w + v);
    }
  }
  double t1 = get_time_sec();
  cout << ans << " " << label << " " << (t1 - t0) * 1000 << endl;
  
  return 0;
}

