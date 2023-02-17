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

  ll a, b, c, x, y; cin >> a >> b >> c >> x >> y;
  ll z = max(x, y);
  ll ans = LLONG_MAX;
  REP(i, 0, z + 1) {
    ll e = a * max(x - i, 0LL) + b * max(y - i, 0LL) + 2 * c * i;
    ans = min(ans, e);
  }
  cout << ans << endl;

  return 0;
}

