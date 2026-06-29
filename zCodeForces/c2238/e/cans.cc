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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    string S; cin >> S;
    vector tbl_init(N + 1, vector(N + 1, -1));
    auto tbl = tbl_init;
    tbl[0][0] = 0;
    REP(i, 0, N) {
      auto prev = move(tbl);
      tbl = tbl_init;
      REP(l, 0, N + 1) REP(c, 0, N + 1) if (ll r = prev[l][c]; r >= 0) {
        auto op = [&](ll new_l, ll new_c, ll new_r) -> void {
          updMin(new_c, new_l);
          updMin(new_r, new_c);
          updMax(tbl[new_l][new_c], (int)new_r);
        };
        if (S[i] == 'F' or S[i] == 'N') op(l + 1, c,     r + 1);
        if (S[i] == 'T' or S[i] == 'N') op(l,     c + 1, r);
      };
    }
    ll ans = 0;
    REP(l, 0, N + 1) REP(c, 0, N + 1) updMax(ans, (ll)tbl[l][c]);
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

