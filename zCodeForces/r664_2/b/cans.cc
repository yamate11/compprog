#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto p = [&](ll x, ll y) -> void {
    cout << x << " " << y << "\n";
  };

  ll n, m, sx, sy; cin >> n >> m >> sx >> sy;
  p(sx, sy);
  for (ll i = 1; i <= m; i++) {
    if (i == sy) continue;
    p(sx, i);
  }
  ll last = m;
  for (ll i = 1; i <= n; i++) {
    if (i == sx) continue;
    if (last == 1) {
      for (ll j = 1; j <= m; j++) {
	p(i, j);
      }
      last = m;
    }else {
      for (ll j = m; j >= 1; j--) {
	p(i, j);
      }
      last = 1;
    }
  }


  return 0;
}

