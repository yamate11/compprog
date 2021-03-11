#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto func = [&](ll x) -> ll {
    ll y = x;
    ll z = 0;
    while (y > 0) {
      z += y % 10;
      y /= 10;
    }
    return z + x;
  };

  ll n; cin >> n;
  vector<ll> ans;
  for (ll x = max(0LL, n - 100); x <= n; x++) {
    if (func(x) == n) ans.push_back(x);
  }
  cout << ans.size() << endl;
  for (ll a : ans) {
    cout << a << "\n";
  }


  return 0;
}

