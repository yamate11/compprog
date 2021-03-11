#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, a, b; cin >> n >> a >> b;
  vector<ll> v(n);
  for (ll i = 0; i < n; i++) cin >> v[i];
  ll ans = 0;
  if (n % 2 == 1 && v[n/2] == 2) ans += min(a, b);
  for (ll i = 0; i < n/2; i++) {
    ll x = v[i];
    ll y = v[n-1 - i];
    if (y == 2) swap(x, y);
    if (x == y) {
      if (x == 2) ans += 2 * min(a, b);
    }else if (x == 2) {
      if (y == 0) ans += a;
      else        ans += b;
    }else {
      cout << -1 << endl;
      return 0;
    }
  }
  cout << ans << endl;

  return 0;
}

