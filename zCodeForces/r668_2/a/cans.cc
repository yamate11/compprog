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
    vector<ll> p(n);
    for (ll i = 0; i < n; i++) cin >> p[i];
    reverse(p.begin(), p.end());
    for (ll i = 0; i < n; i++) {
      if (i > 0) cout << " ";
      cout << p[i];
    }
    cout << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

