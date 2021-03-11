#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll n; cin >> n;
    if (n % 4 == 0) return n / 4;
    if (n == 6) return 1;
    if (n <= 7) return -1;
    if (n == 11) return -1;
    if (n % 4 == 2) return (n - 2) / 4;
    if (n % 4 == 1) return (n - 5) / 4;
    if (n % 4 == 3) return (n - 7) / 4;
    assert(0);
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << "\n";

  return 0;
}

