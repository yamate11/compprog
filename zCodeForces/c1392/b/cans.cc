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
    vector<ll> v_a(n);
    ll vmax = LLONG_MIN;
    for (ll i = 0; i < n; i++) {
      ll a; cin >> a;
      v_a[i] = a;
      vmax = max(vmax, a);
    }
    ll vmax2 = LLONG_MIN;
    for (ll i = 0; i < n; i++) {
      v_a[i] = vmax - v_a[i];
      vmax2 = max(vmax2, v_a[i]);
    }
    if (k % 2 == 0) {
      for (ll i = 0; i < n; i++) {
	v_a[i] = vmax2 - v_a[i];
      }
    }
    for (ll i = 0; i < n; i++) {
      if (i > 0) cout << " ";
      cout << v_a[i];
    }
    cout << endl;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

