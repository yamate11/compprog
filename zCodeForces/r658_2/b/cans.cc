#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll n, auto& as) -> string {
    ll i = 0;
    for ( ; i < n; i++) {
      if (as.at(i) > 1) break;
    }
    ll win;
    win = (i == n) ? 1 : 0;
    if (i % 2 == 1) win = 1 - win;
    return win == 1 ? "Second" : "First";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n; cin >> n;
    vector<ll> as(n);
    for (ll i = 0; i < n; i++) cin >> as.at(i);
    cout << solve(n, as) << "\n";
  }

  return 0;
}

