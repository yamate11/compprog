#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(ipoint)

// ---- inserted library file ipoint.cc

struct IPoint {
  ll x;
  ll y;
  IPoint(ll x_ = 0, ll y_ = 0) : x(x_), y(y_) {}

  IPoint rotate(int r = 1) const {
    ll rd = r % 4;
    ll rr = r >= 0 ? rd : rd == 0 ? 0 : rd + 4;
    if      (rr == 0) return IPoint( x,  y);
    else if (rr == 1) return IPoint(-y,  x);
    else if (rr == 2) return IPoint(-x, -y);
    else if (rr == 3) return IPoint( y, -x);
    assert(0);
  }

  IPoint mirror_x() const { return IPoint(x, -y); }
  IPoint mirror_y() const { return IPoint(-x, y); }

  bool parallel(const IPoint o) const { return x * o.y == y * o.x; }

  IPoint& operator +=(const IPoint& o) {
    x += o.x;
    y += o.y;
    return *this;
  }

  IPoint& operator -=(const IPoint& o) {
    x -= o.x;
    y -= o.y;
    return *this;
  }

  IPoint& operator *=(ll k) {
    x *= k;
    y *= k;
    return *this;
  }

  bool operator ==(const IPoint& o) const { return x == o.x && y == o.y; }
  bool operator !=(const IPoint& o) const { return x != o.x || y != o.y; }
  IPoint operator +(const IPoint& o) const { return IPoint(x, y) += o; }
  IPoint operator -(const IPoint& o) const { return IPoint(x, y) -= o; }
  IPoint operator *(ll k) const { return IPoint(x, y) *= k; }
  IPoint operator -() const { return IPoint(-x, -y); }

  bool operator <(const IPoint& o) const {
    // This seems awkward, but is needed for storing objects in maps.
    if (x != o.x) return x < o.x;
    else return y < o.y;
  }

};
    
IPoint operator *(ll k, const IPoint& p) { return p * k; }
istream& operator >>(istream& is, IPoint& p) {
  ll x_, y_; is >> x_ >> y_;
  p.x = x_;
  p.y = y_;
  return is;
}
ostream& operator <<(ostream& os, const IPoint& p) {
  os << "(" << p.x << ", " << p.y << ")";
  return os;
}

namespace std {
  template<>
  struct hash<IPoint> {
    std::size_t operator()(const IPoint& p) const {
      return p.x * 37 + p.y * 41;
    }
  };
}

// ---- end ipoint.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  auto func = [&](auto& P) {
    sort(P.begin(), P.end(),
         [&](IPoint p, IPoint q) -> bool {
           if (p.y - p.x != q.y - q.x) return p.y - p.x < q.y - q.x;
           return p.x < q.x;
         });
    ll xmin = 1e18;
    ll vmax1 = 0;
    for (IPoint p : P) {
      if (p.x < xmin) xmin = p.x;
      else vmax1 = max(vmax1, p.x - xmin);
    }
    sort(P.begin(), P.end(),
         [&](IPoint p, IPoint q) -> bool {
           if (p.y + p.x != q.y + q.x) return p.y + p.x < q.y + q.x;
           return p.x < q.x;
         });
    ll xmax = -1e18;
    ll vmax2 = 0;
    for (IPoint p : P) {
      if (p.x > xmax) xmax = p.x;
      else vmax2 = max(vmax2, xmax - p.x);
    }
    return max(vmax1, vmax2);
  };

  vector<IPoint> P(N);
  for (ll i = 0; i < N; i++) cin >> P[i];
  vector<IPoint> P2(N);
  for (ll i = 0; i < N; i++) {
    P2[i].x = P[i].y;
    P2[i].y = P[i].x;
  }

  ll x1 = func(P);
  ll x2 = func(P2);
  cout << max(x1, x2) << endl;
  

  return 0;
}

