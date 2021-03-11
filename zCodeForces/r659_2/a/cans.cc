#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = []() -> void {
    ll n; cin >> n;
    string s;
    for (ll p = 0; p < 60; p++) s += 'a';
    cout << s << "\n";
    for (ll i = 1; i <= n; i++) {
      ll a; cin >> a;
      string t = s;
      t.at(a) = s.at(a) == 'a' ? 'b' : 'a';
      cout << t << "\n";
      s = t;
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

