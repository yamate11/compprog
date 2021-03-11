#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll x, y, z; cin >> x >> y >> z;
  ll ans = 1e10;
  for (ll i = 1; i <= 100; i++) {
    ans = min(ans, abs(i - x) + abs(i - y) + abs(i - z));
  }
  cout << ans << endl;

  return 0;
}

