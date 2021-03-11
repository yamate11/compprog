#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    ll n, m; cin >> n >> m;
    vector<ll> a(n), b(n), c(n), d(n);
    bool has1 = false;
    for (ll i = 0; i < n; i++) {
      cin >> a[i] >> b[i] >> c[i] >> d[i];
      if (b[i] == c[i]) has1 = true;
    }
    if (m % 2 == 1) return false;
    if (!has1) return false;
    if (m == 2) return true;
    for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < n; j++) {
	if (a[i] == a[j] && b[i] == c[j] && c[i] == b[j] && d[i] == d[j]) {
	  return true;
	}
      }
    }
    return false;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    cout << (solve() ? "YES\n" : "NO\n");
  }

  return 0;
}

