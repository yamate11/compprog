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

  ll N, P, K; cin >> N >> P >> K;
  ll lim = (ll)(1e18) + 1;
  vector tbl_init(K + 1, 0LL);
  auto tbl = tbl_init;
  tbl[0] = P;
  REP(i, 0, N) {
    auto prev = tbl;
    ll T, B; cin >> T >> B;
    if (T == 1) {
      REP(k, 0, K) {
        updMax(tbl[k + 1], min(lim, prev[k] + B));
      }
    }else if (T == 2) {
      REP(k, 0, K) {
        updMax(tbl[k + 1], min(lim, prev[k] * 2));
      }
    }else assert(0);
  }
  ll ans = tbl[K] == lim ? -1 : tbl[K];
  cout << ans << endl;

  return 0;
}

