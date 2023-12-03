#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(ipoint)

// ---- inserted library file ipoint.cc
#line 30 "/home/y-tanabe/proj/compprog/clib/ipoint.cc"

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

  static bool lt_arg(const IPoint& p1, const IPoint& p2) {
    if ((p1.x == 0 and p1.y == 0) or (p2.x == 0 and p2.y == 0)) return false;
    if (p2.y == 0 and p2.x > 0) return false;
    if (p1.y == 0 and p1.x > 0) return true;
    if (p2.y == 0) return p1.y > 0;
    if (p1.y == 0) return p2.y < 0;
    if ((p1.y > 0) != (p2.y > 0)) return p1.y > 0;
    return p1.x * p2.y > p1.y * p2.x;
  };

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
      static const uint64_t frand = chrono::steady_clock::now().time_since_epoch().count();
      static const uint64_t a = (frand ^ 0x9e3779b97f4a7c15) | 1;
      static const uint64_t b = (frand ^ 0xbf58476d1ce4e5b9) | 1;
      return a * (uint64_t)p.x + b * (uint64_t)p.y;
    }
  };
}

// ---- end ipoint.cc

// @@ !! LIM -- end mark --
#line 7 "ipoint_skel.cc"

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

  {
    IPoint p00(0, 0), p0p(0, 2), p0n(0, -3), pp0(1, 0), pn0(-2, 0), p1(2, 3), p2(-3, 1), p3(-2, -5), p4(1, -4);
    vector<IPoint> vec{p0p, p0n, pp0, pn0, p1,   p2,   p3,   p4};
    vector<double> arg{0.5, 1.5, 0,   1,   0.25, 0.75, 1.25, 1.75};

    assert(not IPoint::lt_arg(p00, p00));
    for (const auto& p : vec) assert(not IPoint::lt_arg(p00, p));
    for (const auto& p : vec) assert(not IPoint::lt_arg(p, p00));
    for (size_t i = 0; i < vec.size(); i++) {
      for (size_t j = 0; j < vec.size(); j++) {
        assert(IPoint::lt_arg(vec[i], vec[j]) == (arg[i] < arg[j]));
      }
    }
  }

  cerr << "ok" << endl;
}
