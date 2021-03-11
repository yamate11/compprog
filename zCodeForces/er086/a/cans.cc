#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll t; cin >> t;
  for (ll _z = 0; _z < t; _z++) {
    ll x, y, a, b; cin >> x >> y >> a >> b;
    ll s = 0;
    if (b < 2*a) {
      ll k = min(x, y);
      s += k * b;
      x -= k;
      y -= k;
    }
    ll m = x + y;
    s += m * a;
    cout << s << "\n";
  }


  return 0;
}

