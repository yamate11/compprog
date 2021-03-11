#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll big = 1e10;
  ll n; cin >> n;
  vector a(n, 0LL);
  for (ll i = 0; i < n; i++) cin >> a[i];
  auto fcnt = [&](auto rF, ll l, ll r, ll x) -> ll {
    ll vmin = big;
    for (ll i = l; i < r; i++) vmin = min(vmin, a[i]);
    ll acc = vmin - x;
    ll i = l;
    while (i < r) {
      while (i < r && a[i] == vmin) i++;
      if (i == r) break;
      ll pl = i;
      while (i < r && a[i] > vmin) i++;
      acc += rF(rF, pl, i, vmin);
    }
    return min(acc, r - l);
  };
  ll ans = fcnt(fcnt, 0, n, 0);
  cout << ans << endl;

  return 0;
}

