#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll n, auto& v) -> ll {
    ll i = n-1;
    while (i-1 >= 0 && v.at(i-1) >= v.at(i)) i--;
    while (i-1 >= 0 && v.at(i-1) <= v.at(i)) i--;
    return i;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n; cin >> n;
    vector<ll> v(n);
    for (ll i = 0; i < n; i++) cin >> v.at(i);
    cout << solve(n, v) << endl;
  }

  return 0;
}

