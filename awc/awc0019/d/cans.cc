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

  ll N, M, T; cin >> N >> M >> T;
  vector tbl(M + 1, -1LL);
  tbl[0] = 0;
  REP(i, 0, N) {
    ll a, b, c; cin >> a >> b >> c;
    if (b >= T) {
      REP(m, 0, M + 1) if (tbl[m] >= 0) { tbl[m] += a; }
    }else {
      REPrev(m, M, 0) {
        if (m + c <= M and tbl[m] >= 0) updMax(tbl[m + c], tbl[m] + a);
      }
    }
  }
  ll ans = 0;
  REP(m, 0, M + 1) if (tbl[m] >= 0) ans = max(ans, tbl[m]);
  cout << ans << endl;

  return 0;
}

