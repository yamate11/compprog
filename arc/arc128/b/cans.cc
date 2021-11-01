#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto f = [&](ll r, ll g, ll b) -> ll {
    if (r < g) return LLONG_MAX;
    if ((r - g) % 3 != 0) return LLONG_MAX;
    if ((2 * r + g) % 3 != 0) return LLONG_MAX;
    ll alpha = (r - g) / 3;
    ll beta = (2 * r + g) / 3;
    // if (b < alpha) return LLONG_MAX;
    return alpha + beta;
  };

  auto solve = [&]() -> ll {
    ll r, g, b; cin >> r >> g >> b;
    auto t = LLONG_MAX;
    t = min(t, f(r, g, b));
    t = min(t, f(r, b, g));
    t = min(t, f(g, b, r));
    t = min(t, f(g, r, b));
    t = min(t, f(b, r, g));
    t = min(t, f(b, g, r));
    if (t == LLONG_MAX) return -1;
    return t;
  };


  ll T; cin >> T;
  while (T-- > 0) cout << solve() << "\n";

  return 0;
}

