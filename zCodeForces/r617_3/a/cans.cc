#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    ll n; cin >> n;
    ll s = 0;
    bool has_odd = false, has_even = false;
    for (ll i = 0; i < n; i++) {
      ll a; cin >> a;
      s += a;
      if (a % 2 == 0) has_even = true;
      else            has_odd = true;
    }
    if (s % 2 == 1) return true;
    if (has_even && has_odd) return true;
    return false;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

