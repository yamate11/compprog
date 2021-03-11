#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll n) -> ll {
    return n / 2 + 1;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n; cin >> n;
    cout << solve(n) << "\n";
  }

  return 0;
}

