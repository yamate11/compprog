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

  auto solve = [&]() -> bool {
    ll l, r, k; cin >> l >> r >> k;
    if (l == r) return l != 1;
    ll numOdd = -1;
    if (l % 2 != r % 2) numOdd = (r - l + 1) / 2;
    else if (l % 2 == 0) numOdd = (r - l) / 2;
    else if (l % 2 == 1) numOdd = (r - l) / 2 + 1;
    return numOdd <= k;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

