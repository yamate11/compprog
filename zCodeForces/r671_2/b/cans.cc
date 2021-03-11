#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll n; cin >> n;
    ll ans = 0;
    ll sum = 0;
    for (ll t = 2; true; t *= 2) {
      ll s = t - 1;
      ll k = s * (s + 1) / 2;
      sum += k;
      if (sum > n) break;
      ans++;
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

