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
  for (ll i = 0; i < n; i++) cin >> A[i];
  ll ans = 360;
  for (ll i = 0; i < n; i++) {
    ll s = 0;
    for (ll j = i; j < n; j++) {
      s += A[j];
      ll t = 360 - s;
      ans = min(ans, abs(t - s));
    }
  }
  cout << ans << endl;


  return 0;
}

