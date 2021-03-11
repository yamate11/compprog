#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

ll solve() {
  ll n, x, m; cin >> n >> x >> m;
  ll vmin = x;
  ll vmax = x;
  for (ll i = 0; i < m; i++) {
    ll l, r; cin >> l >> r;
    if (r < vmin || vmax < l) continue;
    vmin = min(vmin, l);
    vmax = max(vmax, r);
  }
  return vmax - vmin + 1;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll t; cin >> t;
  for (ll i = 0; i < t; i++) {
    cout << solve() << endl;
  }

  return 0;
}

