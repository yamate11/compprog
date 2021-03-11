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
    ll a, b; cin >> a >> b;
    ll ans;
    if (a == b) {
      ans = 0;
    }else if (a < b) {
      if ((b - a) % 2 == 1) {
	ans = 1;
      }else {
	ans = 2;
      }
    }else {
      if ((a - b) % 2 == 0) {
	ans = 1;
      }else {
	ans = 2;
      }
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

