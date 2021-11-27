#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
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

  auto bit = [&](ll x, ll i) -> ll { return ((x >> i) & 1); };

  auto solve = [&]() -> ll {
    ll n, m; cin >> n >> m;
    ll k = 0;
    REP2R(i, 32, 0) {
      if (bit(n, i) == 1 and bit(m + 1, i) == 0) return k;
      if (bit(n, i) == 0 and bit(m + 1, i) == 1) k += (1LL << i);
    }
    return k;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << "\n";

  return 0;
}

