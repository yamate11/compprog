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
    ll n, m, k; cin >> n >> m >> k;
    if (n == 1) {
      if (m > 0) return false;
      return 0 < k - 1;
    }
    if (m < n - 1) return false;
    if (m > n * (n - 1) / 2) return false;
    if (m == n * (n - 1) / 2) {
      return 1 < k - 1;
    }else {
      return 2 < k - 1;
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "YES" : "NO") << "\n";

  return 0;
}

