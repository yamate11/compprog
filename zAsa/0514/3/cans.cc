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
    ll x, y, z; cin >> x >> y >> z;
    y -= x;
    z -= x;
    x = 0;
    if (y % 2 != 0) return -1;
    if (z % 2 != 0) return -1;
    if ((y + z) % 3 != 0) return -1;
    ll m = (y + z) / 3;
    return (abs(x - m) + abs(y - m) + abs(z - m)) / 4;
    
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << endl;

  return 0;
}

