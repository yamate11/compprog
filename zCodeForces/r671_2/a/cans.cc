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
    if (n % 2 == 0) {
      for (ll i = 1; i < n; i += 2) {
	if ((s[i] - '0') % 2 == 0) {
	  cout << "2\n";
	  return;
	}
      }
      cout << "1\n";
      return;
    }else {
      for (ll i = 0; i < n; i += 2) {
	if ((s[i] - '0') % 2 == 1) {
	  cout << "1\n";
	  return;
	}
      }
      cout << "2\n";
      return;
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

