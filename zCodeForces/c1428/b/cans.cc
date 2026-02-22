#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll n; cin >> n;
    string s; cin >> s;
    bool cw = false;
    bool ccw = false;
    for (ll i = 0; i < n; i++) {
      if (s[i] == '>') cw = true;
      if (s[i] == '<') ccw = true;
    }
    if (!cw || !ccw) {
      cout << n << "\n";
      return;
    }
    vector<bool> ok(n);
    for (ll i = 0; i < n; i++) {
      if (s[i] == '-') {
	ok[i] = true;
	ok[(i + 1) % n] = true;
      }
    }
    ll cnt = 0;
    for (ll i = 0; i < n; i++) if (ok[i]) cnt++;
    cout << cnt << "\n";
    return;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

