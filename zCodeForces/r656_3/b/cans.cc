#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll n, vector<ll>& v) -> void {
    vector<ll> w;
    vector<bool> appear(51);
    for (ll i = 0; i < 2 * n; i++) {
      if (appear.at(v.at(i))) {
      }else {
	appear.at(v.at(i)) = true;
	w.push_back(v.at(i));
      }
    }
    bool first = true;
    for (ll x : w) {
      if (first) first = false;
      else cout << " ";
      cout << x;
    }
    cout << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n; cin >> n;
    vector<ll> v(2*n);
    for (ll i = 0; i < 2 * n; i++) cin >> v.at(i);
    solve(n, v);
  }

  return 0;
}

