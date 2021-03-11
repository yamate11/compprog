#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll m, b; cin >> m >> b;
  ll ans = 0;
  for (ll p = 0; p <= b; p++) {
    ll q = m * (b - p);
    ans = max(ans, (p + 1) * (q + 1) * (p + q) / 2);
  }
  cout << ans << endl;

  return 0;
}

