#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll rmin1 = 1e10, rmin2 = 1e10;
  ll lmax1 = 0, lmax2 = 0;
  ll n; cin >> n;
  for (ll i = 0; i < n; i++) {
    ll l, r; cin >> l >> r;
    rmin1 = min(rmin1, r);
    lmax1 = max(lmax1, l);
  }
  ll m; cin >> m;
  for (ll i = 0; i < m; i++) {
    ll l, r; cin >> l >> r;
    rmin2 = min(rmin2, r);
    lmax2 = max(lmax2, l);
  }
  ll a = max(lmax1 - rmin2, lmax2 - rmin1);
  if (a < 0) a = 0;
  cout << a << endl;

  return 0;
}

