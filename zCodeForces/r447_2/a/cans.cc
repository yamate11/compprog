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
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    if (s[i] != 'Q') continue;
    for (ll j = i + 1; j < n; j++) {
      if (s[j] != 'A') continue;
      for (ll k = j + 1; k < n; k++) {
        if (s[k] != 'Q') continue;
        ans++;
      }
    }
  }
  cout << ans << endl;

  return 0;
}

