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
    vector<ll> a(n);
    for (ll i = 0; i < n; i++) cin >> a[i];

    if (n == 1) return 0;
    ll vmin = a[n-1];
    ll ret = 0;
    for (ll i = n-2; i >= 0; i--) {
      if (a[i] > vmin) ret++;
      vmin = min(vmin, a[i]);
    }
    return ret;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << "\n";

  return 0;
}

