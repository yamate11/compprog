#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  string s, t; cin >> s >> t;
  ll ans = 1e9;
  ll arg = -1;
  for (ll i = 0; i < m - n + 1; i++) {
    ll cnt = 0;
    for (ll j = 0; j < n; j++) {
      if (s[j] != t[i + j]) cnt++;
    }
    if (cnt < ans) {
      ans = cnt;
      arg = i;
    }
  }
  cout << ans << endl;
  bool first = true;
  for (ll j = 0; j < n; j++) {
    if (s[j] == t[arg + j]) continue;
    if (first) first = false;
    else cout << " ";
    cout << j + 1;
  }
  cout << endl;

  return 0;
}

