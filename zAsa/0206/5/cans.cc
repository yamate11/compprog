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

  ll W; cin >> W;
  ll N, K; cin >> N >> K;
  vector tbl(W + 1, vector(K + 1, -1LL));
  tbl[0][0] = 0;
  REP(i, 0, N) {
    auto prev = tbl;
    ll a, b; cin >> a >> b;
    REP(w, 0, W + 1) REP(n, 0, K + 1) {
      if (prev[w][n] >= 0) {
        if (w + a <= W and n + 1 <= K) updMax(tbl[w + a][n + 1], prev[w][n] + b);
      }
    }
  }
  ll ans = 0;
  REP(w, 0, W + 1) REP(n, 0, K + 1) ans = max(ans, tbl[w][n]);
  cout << ans << endl;
  return 0;
}

