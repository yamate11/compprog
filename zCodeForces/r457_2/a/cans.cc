#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto isLucky = [&](ll s) -> bool {
    return s % 10 == 7;
  };

  auto lucky = [&](ll t) -> bool {
    return isLucky(t / 60) || isLucky(t % 60);
  };

  ll x; cin >> x;
  ll h, m; cin >> h >> m;
  ll cnt = 0;
  ll t = h * 60 + m;
  while (!lucky(t)) {
    cnt++;
    t -= x;
    if (t < 0) t += 24*60;
  }
  cout << cnt << endl;

  return 0;
}

