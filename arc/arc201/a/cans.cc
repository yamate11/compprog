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

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    ll g1 = 0, g2 = 0, g3 = 0;
    REP(i, 0, N) {
      ll a, b, c; cin >> a >> b >> c;
      if (a < b) {
        ll x = min(b - a, c);
        g2 += x;
        b -= x;
        c -= x;
      }
      if (b > c) {
        ll x = min(b - c, a);
        g1 += x;
        b -= x;
        a -= x;
      }
      g3 += min(a, min(b, c));
    }
    if (g1 > g2) swap(g1, g2);
    ll y = min(g2 - g1, g3);
    g1 += y;
    g3 -= y;
    ll ans = g1 + g3 / 2;
    return ans;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

