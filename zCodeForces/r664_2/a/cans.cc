#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll r, ll g, ll b, ll w) -> bool {
    ll cnt = (r % 2) + (g % 2) + (b % 2) + (w % 2);
    if (cnt <= 1) return true;
    if (r == 0 || g == 0 || b == 0) return false;
    if (cnt >= 3) return true;
    return false;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll r, g, b, w; cin >> r >> g >> b >> w;
    cout << (solve(r, g, b, w)? "Yes" : "No") << "\n";
  }

  return 0;
}

