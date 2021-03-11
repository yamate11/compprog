#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto lcm = [&](ll x, ll y) -> ll {
    return x / gcd(x, y) * y;
  };

  ll n; cin >> n;
  vector<ll> C(n);
  vector<bool> seen(n);
  bool ok = true;
  vector<bool> chk(n);
  for (ll i = 0; i < n; i++) {
    ll c; cin >> c; c--;
    C[i] = c;
    if (chk[c]) ok = false;
    chk[c] = true;
  }
  if (!ok) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 1;
  for (ll i = 0; i < n; i++) {
    if (seen[i]) continue;
    seen[i] = true;
    ll cnt = 1;
    while (true) {
      i = C[i];
      if (seen[i]) break;
      seen[i] = true;
      cnt++;
    }
    if (cnt % 2 == 0) ans = lcm(ans, cnt / 2);
    else              ans = lcm(ans, cnt);
  }
  cout << ans << endl;


  return 0;
}

