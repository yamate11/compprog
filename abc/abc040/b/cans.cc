#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;

  ll ans = 1000000;
  for (ll k = 1; k <= n; k++) {
    if (k * k > n) break;
    ll m = n / k;
    ll q = n % k;
    ans = min(ans, abs(k - m) + q);
  }
  cout << ans << endl;

  return 0;
}

