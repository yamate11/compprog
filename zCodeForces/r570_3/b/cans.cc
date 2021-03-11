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
    ll n, k; cin >> n >> k;
    ll vmin = 1e10, vmax = 0;
    for (ll i = 0; i < n; i++) {
      ll a; cin >> a;
      vmin = min(vmin, a);
      vmax = max(vmax, a);
    }
    ll b = vmin + k;
    if (b + k >= vmax) {
      cout << b << "\n";
    }else {
      cout << -1 << "\n";
    }

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

