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
  vector<ll> A(n), S(n + 1);
  for (ll i = 0; i < n; i++) cin >> A[i];
  for (ll i = 0; i < n; i++) S[i + 1] = S[i] + A[i];
  ll ans = 0;
  for (ll i = 0; i < m; i++) {
    ll l, r; cin >> l >> r; l--; r--;
    ll t = S[r + 1] - S[l];
    if (t > 0) ans += t;
  }
  cout << ans << endl;


  return 0;
}

