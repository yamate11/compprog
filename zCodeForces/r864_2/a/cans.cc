#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
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

  auto solve = [&]() -> void {
    ll n, m, x1, y1, x2, y2; cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    auto f = [&](ll x, ll y) -> ll {
      if ((x == 1 or x == n) and (y == 1 or y == m)) return 2;
      if (x == 1 or x == n or y == 1 or y == m) return 3;
      return 4;
    };
    ll e1 = f(x1, y1);
    ll e2 = f(x2, y2);
    cout << min(e1, e2) << endl;

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

