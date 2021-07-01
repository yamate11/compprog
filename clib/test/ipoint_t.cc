#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

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

int main() {

  {
    IPoint p1(3, 5), p2(-2, 7);
    assert(p1 + p2 == IPoint(1, 12));
    assert(p1 - p2 == IPoint(5, -2));
    assert(3 * p1 == p1 * 3 && p1 * 3 == IPoint(9, 15));
    assert(p1.rotate() == p1.rotate(1) && p1.rotate(1) == IPoint(-5, 3));
    assert(p1.rotate(2) == p1.rotate(1).rotate(1) && p1.rotate(2) == IPoint(-3, -5));
    assert(p1.rotate(-1) == p1.rotate(3) && p1.rotate(-6) == p1.rotate(2));
    assert(p1.mirror_x() == IPoint(3, -5));
    assert(p1.mirror_y() == IPoint(-3, 5));
    assert(p1.mirror_x().mirror_y() == p1.rotate(2));
    assert(p1.parallel(IPoint(-6, -10)));
    assert(!p1.parallel(IPoint(6, 9)));
  }
  {
    stringstream ss1("5 -2 0 -9 1 80");
    IPoint p1, p2, p3; ss1 >> p1 >> p2 >> p3;
    assert(p1 == IPoint(5, -2));
    assert(p2 == IPoint(0, -9));
    assert(p3 == IPoint(1, 80));
    stringstream ss2;
    ss2 << p1 << " " << p2 << " " << p3;
    assert(ss2.str() == "(5, -2) (0, -9) (1, 80)");
  }
  {
    map<IPoint, ll> mp;
    mp[IPoint(2, -7)] = 99;
    auto it1 = mp.find(IPoint(2, -7));
    assert(it1 != mp.end() && it1->second == 99);
    auto it2 = mp.find(IPoint(5, 3));
    assert(it2 == mp.end());
    unordered_map<IPoint, ll> ump;
    ump[IPoint(4, -2)] = 50;
    auto it3 = ump.find(IPoint(4, -2));
    assert(it3 != ump.end() && it3->second == 50);
    auto it4 = ump.find(IPoint(5, 3));
    assert(it4 == ump.end());
  }

  cerr << "ok" << endl;
}
