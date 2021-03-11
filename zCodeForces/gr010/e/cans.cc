#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ll n; cin >> n;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      if (j > 0) cout << " ";
      ll x = (j % 2) << (i + j - 1);
      cout << x;
    }
    cout << endl;
  }
  ll q; cin >> q;
  auto myput = [&](ll i, ll j) -> void {
    cout << i + 1 << " " << j + 1 << endl;
  };
  for (ll _q = 0; _q < q; _q++) {
    ll k; cin >> k;
    ll i = 0;
    ll j = 0;
    ll cur = 0;
    myput(i, j);
    for (ll m = 0; m < 2 * (n - 1); m++) {
      ll prev = cur;
      cur = (k >> m) & 1;
      if (prev == cur) i += 1;
      else             j += 1;
      myput(i, j);
    }
  }
  return 0;
}

