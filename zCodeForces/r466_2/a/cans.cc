#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, d; cin >> n >> d;
  vector<ll> X(n);
  for (ll i = 0; i < n; i++) cin >> X[i];
  ll ans = 1000;
  for (ll i = 1; i <= 100; i++) {
    ll cnt = 0;
    for (ll j = 0; j < n; j++) {
      if (X[j] < i || X[j] > i + d) cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}

