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
  vector<ll> A(n), B(m);
  for (ll i = 0; i < n; i++) cin >> A[i];
  for (ll i = 0; i < m; i++) cin >> B[i];

  ll tmax = LLONG_MIN;
  ll maxarg = -1;
  for (ll i = 0; i < n; i++) {
    ll vmax = A[i] * B[0];
    for (ll j = 1; j < m; j++) {
      vmax = max(vmax, A[i] * B[j]);
    }
    if (vmax > tmax) {
      tmax = vmax;
      maxarg = i;
    }
  }
  ll ans = LLONG_MIN;
  for (ll i = 0; i < n; i++) {
    if (i == maxarg) continue;
    for (ll j = 0; j < m; j++) {
      ans = max(ans, A[i] * B[j]);
    }
  }
  cout << ans << endl;

  return 0;
}


