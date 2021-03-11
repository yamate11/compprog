#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto exists = [&](const string& s, ll x, ll y, char c) -> bool {
    for (ll i = x; i < y; i++) {
      if (s[i] == c) return true;
    }
    return false;
  };

  auto solve = [&]() -> void {
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    for (ll i = 0; i < q; i++) {
      ll l, r; cin >> l >> r; l--; r--;
      if (exists(s, 0, l, s[l]) || exists(s, r + 1, n, s[r])) {
	cout << "YES\n";
      }else {
	cout << "NO\n";
      }
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

