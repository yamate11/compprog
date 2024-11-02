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

  string narek = "narek";

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    // @InpVec(N, S, type=string) [ekOQHy1t]
    auto S = vector(N, string());
    for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
    // @End [ekOQHy1t]

    ll big = 1e18;
    vector tbl_init(5, -big);
    auto tbl = tbl_init;
    tbl[0] = 0;
    REP(i, 0, N) {
      auto prev = tbl;
      REP(j, 0, 5) {
        ll e = j;
        if (prev[j] <= -big) continue;
        ll diff = 0;
        REP(m, 0, M) {
          char c = S[i][m];
          if (c == narek[e]) {
            e++;
            if (e == 5) {
              diff += 5;
              e = 0;
            }
          }else if (c == 'n' or c == 'a' or c == 'r' or c == 'e' or c == 'k') {
            diff -= 1;
          }
        }
        updMax(tbl[e], prev[j] + diff);
      }
    }
    ll ans = *max_element(ALL(tbl));
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

