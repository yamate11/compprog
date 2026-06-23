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

  auto solve = [&]() -> ll {
    string S; cin >> S;
    ll N = ssize(S);
    ll K; cin >> K;
    ll marg = 4;
    ll big = 2 * N + 10;
    vector tbl_init(marg + K + marg, vector(3, big));
    auto tbl = tbl_init;
    tbl[marg][0] = 0;
    REP(i, 0, N) {
      auto prev = move(tbl);
      tbl = tbl_init;
      char c = S[i];
      REP(xx, 0, marg + K + marg) {
        if (c == 'A') {
          updMin(tbl[xx][0], prev[xx][0] + 1);
          updMin(tbl[xx][0], prev[xx][1] + 1);
          updMin(tbl[xx][0], prev[xx][2] + 1);
          if (xx + 1 < marg + K + marg) updMin(tbl[xx + 1][0], prev[xx][2] + 1);
          updMin(tbl[xx][1], prev[xx][0]);
          updMin(tbl[xx][1], prev[xx][1]);
          updMin(tbl[xx][1], prev[xx][2]);
          updMin(tbl[xx][2], prev[xx][0] + big);
          updMin(tbl[xx][2], prev[xx][1] + 1);
          updMin(tbl[xx][2], prev[xx][2] + big);
        }else if (c == 'B') {
          updMin(tbl[xx][0], prev[xx][0]);
          updMin(tbl[xx][0], prev[xx][1]);
          updMin(tbl[xx][0], prev[xx][2]);
          if (xx + 1 < marg + K + marg) updMin(tbl[xx + 1][0], prev[xx][2] + 1);
          updMin(tbl[xx][1], prev[xx][0] + 1);
          updMin(tbl[xx][1], prev[xx][1] + 1);
          updMin(tbl[xx][1], prev[xx][2] + 1);
          updMin(tbl[xx][2], prev[xx][0] + big);
          updMin(tbl[xx][2], prev[xx][1]);
          updMin(tbl[xx][2], prev[xx][2] + big);
        }else if (c == 'C') {
          updMin(tbl[xx][0], prev[xx][0]);
          updMin(tbl[xx][0], prev[xx][1]);
          updMin(tbl[xx][0], prev[xx][2] + 1);
          if (xx + 1 < marg + K + marg) updMin(tbl[xx + 1][0], prev[xx][2]);
          updMin(tbl[xx][1], prev[xx][0] + 1);
          updMin(tbl[xx][1], prev[xx][1] + 1);
          updMin(tbl[xx][1], prev[xx][2] + 1);
          updMin(tbl[xx][2], prev[xx][0] + big);
          updMin(tbl[xx][2], prev[xx][1] + 1);
          updMin(tbl[xx][2], prev[xx][2] + big);
        }else {
          updMin(tbl[xx][0], prev[xx][0]);
          updMin(tbl[xx][0], prev[xx][1]);
          updMin(tbl[xx][0], prev[xx][2]);
          if (xx + 1 < marg + K + marg) updMin(tbl[xx + 1][0], prev[xx][2] + 1);
          updMin(tbl[xx][1], prev[xx][0] + 1);
          updMin(tbl[xx][1], prev[xx][1] + 1);
          updMin(tbl[xx][1], prev[xx][2] + 1);
          updMin(tbl[xx][2], prev[xx][0] + big);
          updMin(tbl[xx][2], prev[xx][1] + 1);
          updMin(tbl[xx][2], prev[xx][2] + big);
        }
      }
      if (i >= 2 and S[i - 2] == 'A' and S[i - 1] == 'B' and S[i] == 'C') {
        REP(tp, 0, 3) {
          REP(xx, 0, marg + K + marg - 1) {
            tbl[xx][tp] = tbl[xx + 1][tp];
          }
          tbl[marg + K + marg - 1][tp] = big;
        }
      }
    }
    ll ans = big;
    REP(tp, 0, 3) ans = min(ans, tbl[marg + K][tp]);
    if (ans == big) ans = -1;
    return ans;
  };


  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

