#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s; cin >> s;
  ll n = s.size();
  vector<ll> vec(n + 1);
  for (ll i = 0; i < n; i++) {
    if (s[i] == 'a') vec[i + 1] = vec[i] + 1;
    else             vec[i + 1] = vec[i];
  }
  ll ans = 0;
  for (ll i = 0; i <= n; i++) {
    for (ll j = i; j <= n; j++) {
      ll a1 = vec[i];
      ll b2 = (j - i) - (vec[j] - vec[i]);
      ll a3 = vec[n] - vec[j];
      ans = max(ans, a1 + b2 + a3);
    }
  }
  cout << ans << endl;

  return 0;
}

