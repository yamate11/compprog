#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<ll> A(n);
  vector<vector<ll>> pos(n + 1);
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    A[i] = a;
    pos[a].push_back(i);
  }
  ll l2r = -1;
  ll r2l = n;
  for (ll k = 1; k <= n; k++) {
    ll m = pos[k].size();
    if (m == 0) {
      cout << k + 1 << endl;
      return 0;
    }
    if (r2l < pos[k][0] && pos[k][m - 1] < l2r) {
      cout << k << endl;
      return 0;
    }
    if (l2r < pos[k][0]) l2r = pos[k][0];
    if (pos[k][m - 1] < r2l) r2l = pos[k][m - 1];
  }
  cout << n + 2 << endl;

  return 0;
}

