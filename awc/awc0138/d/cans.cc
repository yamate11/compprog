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

  ll N, W, B; cin >> N >> W >> B;
  vector tbl_init(3, vector(W + 1, -1LL));
  auto tbl = tbl_init;
  tbl[0][0] = 0;
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    ll d, c; cin >> d >> c;
    REP(tp, 0, 3) {
      REP(w, 0, W + 1) {
        ll pv = prev[tp][w];
        if (pv < 0) continue;
        if (tp == 0) {
          updMax(tbl[0][w], pv);
          if (w + c < W + 1) updMax(tbl[1][w + c], pv + d);
        }else if (tp == 1) {
          updMax(tbl[0][w], pv);
          if (w + c < W + 1) updMax(tbl[2][w + c], pv + d + 2 * B);
        }else if (tp == 2) {
          updMax(tbl[0][w], pv);
          if (w + c < W + 1) updMax(tbl[2][w + c], pv + d + B);
        }else assert(0);
      }
    }
  }
  ll ans = 0;
  REP(tp, 0, 3) REP(w, 0, W + 1) ans = max(ans, tbl[tp][w]);
  cout << ans << "\n";

  return 0;
}

