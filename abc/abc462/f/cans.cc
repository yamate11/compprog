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
    REP(i, 0, N) if (S[i] >= 'D') S[i] = 'D';
    ll K; cin >> K;
    ll marg = 4;
    ll big = N + 1;
    vector tbl_init(K + 2, vector(3, big));
    auto tbl = tbl_init;
    tbl[0][0] = 0;
    REP(i, 0, N) {
      auto prev = move(tbl);
      tbl = tbl_init;
      char c = S[i];
      auto op = [&](ll n0, ll p0, ll n1, ll p1, string pat) -> void {
        ll add = EXISTS(i, 0, ssize(pat), c == pat[i]) ? 0 : 1;
        if (n1 < K + 2) updMin(tbl[n1][p1], prev[n0][p0] + add);
      };
      REP(n, 0, K + 2) {
        op(n, 0, n, 0, "BCD");
        op(n, 0, n, 1, "A");
        op(n, 1, n, 0, "CD");
        op(n, 1, n, 1, "A");
        op(n, 1, n, 2, "B");
        op(n, 2, n, 0, "BD");
        op(n, 2, n, 1, "A");
        op(n, 2, n + 1, 0, "C");
      }
      if (i >= 2 and S[i - 2] == 'A' and S[i - 1] == 'B' and S[i] == 'C') {
        REP(tp, 0, 3) {
          REP(n, 0, K + 2 - 1) tbl[n][tp] = tbl[n + 1][tp];
          tbl[K + 2 - 1][tp] = big;
        }
      }
    }
    ll ans = big;
    REP(tp, 0, 3) ans = min(ans, tbl[K][tp]);
    if (ans == big) ans = -1;
    return ans;
  };


  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

