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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main() {
  ll x, y; cin >> x >> y;
  ll ans = 1e18;
  for (ll x0 : {x, -x}) for (ll y0 : {y, -y}) {
      ll t = x0 <= y0 ? y0 - x0 : 1e18;
      ans = min(ans, t + (x0 == x ? 0 : 1) + (y0 == y ? 0 : 1));
    }
  cout << ans << endl;
  return 0;
}

