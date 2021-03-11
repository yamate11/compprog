#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    auto func = [&](ll b, ll p) -> ll {
      ll y = b / p;
      if (y == 0) y = 1;
      ll q1 = p * y;
      ll q2 = p * (y + 1);
      ll qa1 = abs(q1 - b);
      ll qa2 = abs(q2 - b);
      if (qa1 < qa2) return q1;
      else return q2;
    };

    ll a, b, c; cin >> a >> b >> c;
    ll lim = c - a + 10;
    ll ans = 1e10;
    ll p0 = -1, q0 = -1, r0 = -1;
    for (ll p = 1; p <= a + lim; p++) {
      for (ll q = p; q <= b + lim; q += p) {
	ll r = func(c, q);
	ll d = abs(p - a) + abs(q - b) + abs(r - c);
	if (d < ans) {
	  ans = d;
	  p0 = p; q0 = q; r0 = r;
	}
      }
    }
    cout << ans << "\n";
    cout << p0 << " " << q0 << " " << r0 << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

