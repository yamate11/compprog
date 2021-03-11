#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll r, d; cin >> r >> d;
  ll n; cin >> n;
  ll cnt = 0;
  for (ll i = 0; i < n; i++) {
    ll x, y, q; cin >> x >> y >> q;
    ll pp = x*x + y*y;
    ll t = r - d + q;
    ll s = r - q;
    if (s < 0) continue;
    if (t*t <= pp && pp <= s*s) cnt++;
  }
  cout << cnt << endl;


  return 0;
}

