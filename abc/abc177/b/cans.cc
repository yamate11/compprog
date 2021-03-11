#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  string s, t; cin >> s >> t;
  ll ns = s.size();
  ll nt = t.size();
  ll ans = ns * 2;
  for (ll i = 0; i < ns; i++) {
    if (i + nt > ns) break;
    ll cnt = 0;
    for (ll j = 0; j < nt; j++) {
      if (s[i + j] != t[j]) cnt++;
    }
    ans = min(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}

