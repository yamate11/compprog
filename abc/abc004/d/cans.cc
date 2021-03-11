#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll f(ll p, ll q) {
  if (p < q) swap(p, q);
  if (q >= 0) return (p*(p+1) + q*(q+1)) / 2;
  else        return (p*(p+1) - q*(q+1)) / 2;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll R, G, B; cin >> R >> G >> B;
  ll ans = LLONG_MAX;
  for (ll p = min(0LL, 99 - B/2); p <= G + max(0LL, R/2 - 100); p++) {
    ll q = G - 1 - p;
    ll s = min(99 - p, (B-1)/2);
    ll r = B - 1 - s;
    ll t = min(99 - q, (R-1)/2);
    ll u = R - 1 - t;
    ll num = f(p, q) + f(r, s) + f(t, u);
    ans = min(ans, num);
  }
  cout << ans << endl;

  return 0;
}

