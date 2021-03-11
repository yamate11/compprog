#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll l, ll r) -> void {
    if (r < 2 * l) {
      cout << "-1 -1\n";
    }else {
      cout << l << " " << 2 * l << endl;
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll x, y; cin >> x >> y;
    solve(x, y);
  }

  return 0;
}

