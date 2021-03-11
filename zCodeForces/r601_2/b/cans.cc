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
    ll n, m; cin >> n >> m;
    ll s = 0;
    for (ll i = 0; i < n; i++) {
      ll a; cin >> a;
      s += a;
    }
    if (n == 2 || m < n) {
      cout << -1 << "\n";
      return;
    }
    cout << s * 2 << "\n";
    for (ll i = 0; i < n - 1; i++) {
      cout << i + 1 << " " << i + 2 << "\n";
    }
    cout << 1 << " " << n << "\n";

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

