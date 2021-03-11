#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll x0, x1, x2; cin >> x0 >> x1 >> x2;
    ll y0, y1, y2; cin >> y0 >> y1 >> y2;

    ll mark = 0;
    if (x2 >= y1) {
      mark = 2 * y1;
      y2 -= (x2 - y1);
      y2 -= x0;
      if (y2 > 0) mark -= 2 * y2;
    }else {
      mark = 2 * x2;
      x1 -= (y1 - x2);
      x1 -= y0;
      if (x1 > 0) mark -= 2 * x1;
    }
    return mark;



    
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << endl;

  return 0;
}

