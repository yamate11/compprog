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

  auto solve = [&]() -> ll {
    ll x, y, z; cin >> x >> y >> z;
    if ((x - y) % 2 != 0 or (y - z) % 2 != 0 or (z - x) % 2 != 0) return -1;
    ll ss = x + y + z;
    if (ss % 3 != 0) return -1;
    ll g = ss / 3;
    if ((x - g) % 2 != 0 or (y - g) % 2 != 0 or (z - g) % 2 != 0) return -1;
    ll t = abs(x - g) / 2 + abs(y - g) / 2 + abs(z - g) / 2;
    if (t % 2 != 0) return -1;
    return t / 2;
  };

  ll T; cin >> T;
  REP(i, 0, T) cout << solve() << endl;

  return 0;
}

