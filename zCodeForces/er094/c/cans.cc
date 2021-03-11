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
    string s; cin >> s;
    ll x; cin >> x;
    ll n = s.size();
    vector t(n, 1);
    for (ll i = 0; i < n; i++) {
      if (s[i] == '0') {
	if (i - x >= 0) t[i - x] = 0;
	if (i + x < n)  t[i + x] = 0;
      }
    }
    for (ll i = 0; i < n; i++) {
      ll p = 0;
      if (i - x >= 0) p |= t[i - x];
      if (i + x < n)  p |= t[i + x];
      if (p != s[i] - '0') {
	cout << "-1\n";
	return;
      }
    }
    for (ll i = 0; i < n; i++) {
      cout << t[i];
    }
    cout << "\n";
    return ;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

