#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  vector<ll> vec(k);
  for (ll i = 0; i < n; i++) {
    ll x; cin >> x;
    vec[x % k]++;
  }
  ll ans = vec[0] / 2;
  for (ll i = 1; i < k; i++) {
    if (i > k - i) break;
    else if (i == k - i) ans += vec[i] / 2;
    else ans += min(vec[i], vec[k - i]);
  }
  ans *= 2;
  cout << ans << endl;


  return 0;
}

