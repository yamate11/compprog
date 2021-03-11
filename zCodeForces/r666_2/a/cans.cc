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
    vector vec(128, 0LL);
    for (ll i = 0; i < n; i++) {
      string s; cin >> s;
      for (char c : s) vec[c]++;
    }
    for (char c = 'a'; c <= 'z'; c++) {
      if (vec[c] % n != 0) {
	cout << "NO\n";
	return;
      }
    }
    cout << "YES\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

