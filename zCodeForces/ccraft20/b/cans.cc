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
    string s; cin >> s;
    string sans = s;
    ll kans = 0;
    for (ll k = 0; k < n; k++) {
      string t = s.substr(k, n - k) + s.substr(0, k);
      if ((n + k) % 2 == 1) reverse(t.begin() + n - k, t.end());
      if (t < sans) {
	sans = t;
	kans = k;
      }
    }
    cout << sans << "\n" << kans + 1 << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

