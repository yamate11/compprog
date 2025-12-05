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
  ll N; cin >> N;
  // @InpMVec(N, (T, H)) [TqTkE6BS]
  auto T = vector(N, ll());
  auto H = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; H[i] = v2;
  }
  // @End [TqTkE6BS]
  vector tbl_init(X + 1, vector(Y + 1, -1LL));
  auto tbl = tbl_init;
  tbl[X][Y] = 0;
  REP(i, 0, N) {
    auto prev = tbl;
    REP(x, 0, X + 1) REP(y, 0, Y + 1) {
      if (prev[x][y] >= 0) {
        if (x >= 1 and x + y >= T[i]) {
          ll q = min(T[i] - 1, y);
          ll p = T[i] - q;
          updMax(tbl[x - p][y - q], prev[x][y] + H[i]);
        }
      }
    }
  }
  ll ans = 0;
  REP(x, 0, X + 1) REP(y, 0, Y + 1) ans = max(ans, tbl[x][y]);
  cout << ans << endl;

  return 0;
}

