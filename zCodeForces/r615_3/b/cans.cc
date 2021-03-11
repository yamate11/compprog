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
    using sta = pair<ll, ll>;
    vector<sta> XY;
    for (ll i = 0; i < n; i++) {
      ll x, y; cin >> x >> y;
      XY.emplace_back(x, y);
    }
    sort(XY.begin(), XY.end());
    ll px = 0, py = 0;
    string seq;
    for (ll i = 0; i < n; i++) {
      auto [x, y] = XY[i];
      if (x < px || y < py) {
	cout << "NO\n";
	return;
      }
      for (ll j = 0; j < x - px; j++) seq.push_back('R');
      for (ll j = 0; j < y - py; j++) seq.push_back('U');
      px = x;
      py = y;
    }
    cout << "YES\n";
    cout << seq << "\n";
    
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

