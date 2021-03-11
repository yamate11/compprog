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
    ll cnt = 0;
    ll m = n % 10;
    while (n > 0) {
      n = n / 10;
      cnt++;
    }
    ll x = 0;
    for (ll i = 1; i <= cnt; i++) x += i;
    ll ans = (m - 1) * 10 + x;
    return ans;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << "\n";

  return 0;
}

