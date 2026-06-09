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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto root = [&](ll x) -> void {
    cout << x + 1 << "\n";
  };

  auto pout = [&](ll x, ll y) -> void {
    cout << x + 1 << " " << y + 1 << "\n";
  };

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    M -= N;
    if (not (0 <= M and M <= N * (N - 1) / 2)) {
      cout << "-1\n";
      return;
    }
    ll rem = N * (N - 1) / 2 - M;
    if (rem == 0) {
      root(N - 1);
      REP(i, 0, N - 1) pout(N - 1, i);
      return;
    }
    ll t = N - 1;
    while (true) {
      if (rem == 0) {
        root(t);
        REP(i, 0, t) pout(t, i);
        REP(i, t + 1, N) pout(0, i);
        return;
      }
      if (rem < t) {
        root(t - 1);
        REP(i, 0, t - 1) pout(t - 1, i);
        REP(i, t + 1, N) pout(0, i);
        pout(t - rem, t);
        return;
      }
      if (rem >= t) {
        rem -= t;
        t--;
      }
    }


  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

