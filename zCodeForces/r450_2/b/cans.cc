#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll a, b, c; cin >> a >> b >> c;
  ll x = a % b;
  for (ll ans = 1; true; ans++) {
    ll y = (10 * x) / b;
    x = 10 * x % b;
    if (y == c) {
      cout << ans << endl;
      return 0;
    }
    if (ans > b + 10) {
      cout << -1 << endl;
      return 0;
    }
  }


  return 0;
}

