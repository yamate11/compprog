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

  auto solve = [&]() -> ll {
    ll a, b, x, y; cin >> a >> b >> x >> y;
    if (a == b || a == b + 1) {
      return x;
    }else if (a < b) {
      ll k = b - a;
      return min(x + k * y, 2 * k * x + x);
    }else if (a > b) {
      ll k = a - (b + 1);
      return min(x + k * y, 2 * k * x + x);
    }else assert(0);
  };

  cout << solve() << endl;
  return 0;
}

