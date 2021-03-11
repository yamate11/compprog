#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

struct Point {
  double x;
  double y;
  Point(double x_ = 0.0, double y_ = 0.0) : x(x_), y(y_) {}
  Point operator -(const Point& o) const { return Point(x - o.x, y  - o.y); }
  double len() const { return hypot(x, y); }
};


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll start, goal; cin >> start >> goal;
  vector<double> left, right;
  for (ll i = 0; i <= N; i++) {
    ll a, b; cin >> a >> b;
    left.push_back(a);
    right.push_back(b);
  }
  left.at(N) = right.at(N) = goal;

  double ans = 0.0;
  vector<Point> vec(2*N+1);
  auto place = [&](int d, ll i, ll& iU, ll& iV, const auto& datU) -> void {
    while (d * (iU+d - iV) <= 0) {
      Point dir = vec.at(iU) - vec.at(iU + d);
      double x0 = vec.at(iU).x + dir.x / dir.y * (i - vec.at(iU).y);
      if (d * (datU.at(i) - x0) < 0) break;
      if (dir.y < 0) ans += dir.len();
      iU += d;
    }
    iU -= d;
    vec.at(iU) = Point(datU.at(i), i);
  };

  ll iL = N; ll iR = N+1;
  vec.at(iL--) = Point(start, 0);
  vec.at(iL) = Point(left.at(1), 1);
  vec.at(iR) = Point(right.at(1), 1);
  for (ll i = 2; i <= N; i++) {
    place(+1, i, iL, iR, left);
    place(-1, i, iR, iL, right);
  }
  cout << ans << endl;
  return 0;
}

OA
