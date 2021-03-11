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
  ll g = A[0];
  for (ll i = 1; i < n; i++) g = gcd(g, A[i]);
  if (g > 1) {
    cout << "YES\n0\n";
    return 0;
  }
  ll ans = 0;
  ll seq = 0;
  for (ll i = 0; i <= n; i++) {
    if (i < n && A[i] % 2 != 0) {
      seq++;
    }else {
      if (seq % 2 == 0) {
	ans += seq / 2;
      }else {
	ans += seq / 2 + 2;
      }
      seq = 0;
    }
  }
  cout << "YES\n" << ans << endl;


  return 0;
}

