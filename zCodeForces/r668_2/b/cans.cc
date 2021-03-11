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
    for (ll i = 0; i < n; i++) {
      ll a; cin >> a;
      sum += a;
      if (sum >= 0) {
      }else {
	ans -= sum;
	sum = 0;
      }
    }
    cout << ans << "\n";

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

