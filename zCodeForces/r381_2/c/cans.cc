#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  ll vmin = 1e9;
  for (ll i = 0; i < m; i++) {
    ll l, r; cin >> l >> r;
    vmin = min(vmin, r - l + 1);
  }
  cout << vmin << endl;
  for (ll i = 0; i < n; i++) {
    if (i > 0) cout << " ";
    cout << i % vmin;
  }
  cout << endl;

  return 0;
}

