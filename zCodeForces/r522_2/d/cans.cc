#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto func = [&](double x, double y, double p, double q) -> double {
    double xx = p - x;
    double yy = q - y;
    return sqrt(xx * xx + yy * yy);
  };

  auto solve = [&]() -> double {
    ll a, b, c; cin >> a >> b >> c;
    ll x0, y0, p0, q0; cin >> x0 >> y0 >> p0 >> q0;
    double mhd = abs(p0 - x0) + abs(q0 - y0);
    if (p0 == x0 || q0 == y0 || a == 0 || b == 0) return mhd;
    double x1 = -double(b * y0 + c) / a;
    double y1 = -double(a * x0 + c) / b;
    double p1 = -double(b * q0 + c) / a;
    double q1 = -double(a * p0 + c) / b;
    double d1 = abs(x0 - x1) + abs(p0 - p1) + func(x1, y0, p1, q0);
    double d2 = abs(x0 - x1) + abs(q0 - q1) + func(x1, y0, p0, q1);
    double d3 = abs(y0 - y1) + abs(p0 - p1) + func(x0, y1, p1, q0);
    double d4 = abs(y0 - y1) + abs(q0 - q1) + func(x0, y1, p0, q1);
    double ans = min(mhd, min(d1, min(d2, min(d3, d4))));
    return ans;
  };

  cout << solve() << endl;

  return 0;
}

