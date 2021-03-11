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
  vector a(n, 0LL);
  for (ll i = 0; i < n; i++) cin >> a[i];
  sort(a.begin(), a.end());
  ll sum1 = 0;
  for (ll i = 0; i < n; i++) {
    sum1 += abs(a[i] - 1);
  }
  for (ll p = 2; true; p++) {
    ll pp = 1;
    ll sump = 0;
  
    for (ll i = 0; i < n; i++) {
      sump += abs(a[i] - pp);
      if (sump > sum1) {
	cout << sum1 << endl;
	return 0;
      }
      pp *= p;
    }
    sum1 = sump;
  }

  return 0;
}

