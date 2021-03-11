#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll n) -> string {
    if (n == 1) return "8";
    if (n == 2) return "98";
    if (n == 3) return "998";
    // if (n == 4) return "9990";
    string ans;
    ll p = n / 4;
    ll q = n % 4;
    for (ll i = 0; i < n - p - 1; i++) ans += '9';
    if (q == 0) ans += '9';
    else ans += '8';
    for (ll i = 0; i < p; i++) ans += '8';
    return ans;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n; cin >> n;
    cout << solve(n) << "\n";
  }

  return 0;
}

