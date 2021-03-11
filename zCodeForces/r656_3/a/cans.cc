#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&](ll x, ll y, ll z) -> void {
    vector v(3, 0LL);
    v.at(0) = x;
    v.at(1) = y;
    v.at(2) = z;
    sort(v.begin(), v.end());
    if (v.at(1) != v.at(2)) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
    cout << v.at(0) << " " << v.at(0) << " " << v.at(2) << endl;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll x, y, z; cin >> x >> y >> z;
    solve(x, y, z);
  }

  return 0;
}

