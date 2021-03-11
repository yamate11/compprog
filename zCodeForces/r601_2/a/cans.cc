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
    ll a, b; cin >> a >> b;
    ll x = abs(a - b);
    ll y = x / 5;
    if (x % 5 == 0) return y;
    if (x % 5 == 1) return y + 1;
    if (x % 5 == 2) return y + 1;
    if (x % 5 == 3) return y + 2;
    if (x % 5 == 4) return y + 2;
    assert(0);
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << "\n";

  return 0;
}

