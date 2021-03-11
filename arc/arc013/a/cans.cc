#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> x(3), y(3);
  vector<vector<ll>> t({{0,1,2}, {0,2,1}, {1,2,0}, {1,0,2}, {2,0,1}, {2,1,0}});
  for (ll i = 0; i < 3; i++) cin >> x.at(i);
  for (ll i = 0; i < 3; i++) cin >> y.at(i);
  ll ans = 0;
  for (auto v : t) {
    ll z = 1;
    for (ll i = 0; i < 3; i++) z *= x.at(i) / y.at(v.at(i));
    ans = max(ans, z);
  }
  cout << ans << endl;

  return 0;
}

