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
    ll a, b, x, y; cin >> a >> b >> x >> y;
    if (x < 0) x = abs(x);
    if (y < 0) y = abs(y);
    if (x < y) {
      swap(x, y);
      swap(a, b);
    }
    assert(x >= y);
    if (a > 3 * b) a = 3 * b;
    if (b > 3 * a) b = 3 * a;
    ll cost = min(a, b) * 2 * y;
    ll d = x - y;
    ll e = d / 2;
    ll f = d % 2;
    cost += e * (a + b);
    if (f != 0) cost += a;
    return cost;
  };


  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

