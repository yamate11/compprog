#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll x, y, z; cin >> x >> y >> z;
  ll t = x + z - 2 * y;
  ll ans = -1;
  if (t >= 0) {
    if (t % 2 == 0) ans = t / 2;
    else ans = 1 + (t + 1) / 2;
  }else {
    ans = -t;
  }
  cout << ans << endl;

  return 0;
}

