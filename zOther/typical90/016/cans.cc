#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, a, b, c; cin >> n >> a >> b >> c;
  ll ans = 1e10;
  for (ll x = 0; x <= 9999; x++) {
    for (ll y = 0; y <= 9999 - x; y++) {
      ll rem = n - (x * a + y * b);
      if (rem < 0) break;
      if (rem % c != 0) continue;
      ll z = rem / c;
      ans = min(ans, x + y + z);
    }
  }
  cout << ans << endl;

  return 0;
}

