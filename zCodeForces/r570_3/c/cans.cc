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
    ll k, n, a, b; cin >> k >> n >> a >> b;
    ll t = k - n * b;
    if (t <= 0) return -1;
    return min(n, (t - 1) / (a - b));
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    cout << solve() << "\n";
  }

  return 0;
}

