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
    ll x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
    if (x1 == x2) {
      cout << abs(y2 - y1) << "\n";
    }else if (y1 == y2) {
      cout << abs(x2 - x1) << "\n";
    }else {
      cout << abs(x2 - x1) + abs(y2 - y1) + 2 << "\n";
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

