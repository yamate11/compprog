#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> acc(n+1);
    for (ll i = 0; i < n; i++) acc[i+1] = acc[i] + s[i] - '0';
    vector<ll> vval(10*n + 1);
    for (ll i = 0; i <= n; i++) {
      vval[acc[i] - i + n]++;
    }
    ll ans = 0;
    for (ll x = 0; x < 10 * n; x++) {
      ans += vval[x] * (vval[x] - 1) / 2;
    }
    return ans;

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << endl;

  return 0;
}

