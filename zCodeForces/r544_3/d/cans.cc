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
  vector<ll> A(n), B(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  for (ll i = 0; i < n; i++) cin >> B[i];
  ll vmax = 0;
  // using sta = pair<ll, ll>;
  map<ll, map<ll, ll>> rec;
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    if (A[i] == 0) {
      if (B[i] == 0) ans++;
    }else {
      ll a = -1, b = -1;
      if (B[i] == 0) {
	a = 1;
	b = 0;
      }else {
	a = A[i];
	b = B[i];
	if (a < 0) {
	  a = -a;
	  b = -b;
	}
	ll g = gcd(a, abs(b));
	a /= g;
	b /= g;
      }
      rec[a][b]++;
      vmax = max(vmax, rec[a][b]);
    }
  }
  ans += vmax;
  cout << ans << endl;

  return 0;
}

