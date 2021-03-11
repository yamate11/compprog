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
    vector<ll> ans;
    for (ll i = 0; i < n / 2; i++) {
      ll x, y; cin >> x >> y;
      if (x == y) { 
	ans.push_back(x);
	ans.push_back(y);
      }else if (x == 1) {
	ans.push_back(y);
      }else if (x == 0) {
	ans.push_back(x);
      }else assert(0);
    }
    cout << ans.size() << "\n";
    bool first = true;
    for (ll x : ans) {
      if (first) first = false;
      else cout << " ";
      cout << x;
    }
    cout << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

