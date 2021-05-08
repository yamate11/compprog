#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(ipoint cumsum2d)


int main() {

  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> dist1(-100, 100);

  {
    ll n = 5, m = 10;
    CumSum2D cs(n, m);
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= m; j++) cs[i][j] = dist1(rng);
    }
    CumSum2D cum_cs = cs.cum();
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= m; j++) {
	ll s = 0;
	for (ll ii = 1; ii <= i; ii++) {
	  for (ll jj = 1; jj <= j; jj++) s += cs[ii][jj];
	}
	assert(cum_cs[i][j] == s);
	assert(cum_cs.orig(i, j) == cs[i][j]);
	assert(cum_cs.orig(i, j) == cum_cs.orig(IPoint(i, j)));
      }
    }

    uniform_int_distribution<int> dist_n(1, n);
    uniform_int_distribution<int> dist_m(1, m);
    for (ll q = 0; q < 1000; q++) {
      ll x1, y1, x2, y2;
      while (true) {
	x1 = dist_n(rng) - 1;
	y1 = dist_m(rng) - 1;
	x2 = dist_n(rng);
	y2 = dist_m(rng);
	if (x1 < x2 && y1 < y2) break;
      }
      ll s = 0;
      for (ll i = x1 + 1; i <= x2; i++) {
	for (ll j = y1 + 1; j <= y2; j++) s += cs[i][j];
      }
      assert(cum_cs.partial(x1, y1, x2, y2) == s);
      assert(cum_cs.partial(IPoint(x1, y1), IPoint(x2, y2)) == s);
    }

    CumSum2D cs2(n, m);
    CumSum2D or2(n, m);
    for (ll q = 0; q < 1000; q++) {
      ll x1, y1, x2, y2;
      while (true) {
	x1 = dist_n(rng) - 1;
	y1 = dist_m(rng) - 1;
	x2 = dist_n(rng);
	y2 = dist_m(rng);
	if (x1 < x2 && y1 < y2) break;
      }
      ll v = dist1(rng);
      if (q % 2 == 0) {
	cs2.put_rect(x1, y1, x2, y2, v);
      }else {
	cs2.put_rect(IPoint(x1, y1), IPoint(x2, y2), v);
      }
      for (ll i = x1 + 1; i <= x2; i++) {
	for (ll j = y1 + 1; j <= y2; j++) or2[i][j] += v;
      }
    }
    cs2.cum_inplace();
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= m; j++) {
	// DLOG("ij", i, j, cs2[i][j], or2[i][j]);
	assert(cs2[i][j] == or2[i][j]);
      }
    }


  }

  cout << "ok\n";
  return 0;
}
