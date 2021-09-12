#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll lim = 1e6;
  auto enc = [&](ll x, ll y) -> ll {
    return (y + lim) * 10 * lim + (x + lim);
  };

  auto solve = [&]() -> void {
    unordered_map<ll, ll> mp;
    ll x = 0;
    ll y = 0;
    mp[enc(0, 0)] = 0;
    ll n; cin >> n;
    string s; cin >> s;
    ll imax = lim;
    ll ist = -1;
    ll ien = -1;
    for (ll i = 0; i < n; i++) {
      if (s[i] == 'L') x--;
      else if (s[i] == 'R') x++;
      else if (s[i] == 'U') y++;
      else if (s[i] == 'D') y--;
      ll e = enc(x, y);
      auto it = mp.find(e);
      if (it != mp.end()) {
        ll interval = (i + 1) - it->second;
        if (interval < imax) {
          imax = interval;
          ist = it->second + 1;
          ien = i + 1;
        }
        it->second = i + 1;
      }else {
        mp[e] = i + 1;
      }
    }
    if (ist < 0) cout << -1 << "\n";
    else cout << ist << " " << ien << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

