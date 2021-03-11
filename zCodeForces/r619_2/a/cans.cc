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
    string a, b, c; cin >> a >> b >> c;
    ll n = c.size();
    for (ll i = 0; i < n; i++) {
      if (c[i] == a[i] || c[i] == b[i]) continue;
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

