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
    vector<ll> A(n);
    ll vmax = 0;
    for (ll i = 0; i < n; i++) {
      cin >> A[i];
      vmax = max(vmax, A[i]);
    }
    ll ans = -1;
    for (ll i = 0; i < n - 1; i++) {
      if (A[i] == vmax && A[i+1] != vmax) {
	ans = i + 1;
	break;
      }
      if (A[i] != vmax && A[i+1] == vmax) {
	ans = i + 2;
	break;
      }
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

