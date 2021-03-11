#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:updMaxMin geometry)
// --> f:updMaxMin rerror geometry
// ---- inserted function updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end updMaxMin
// ---- inserted library file rerror.cc

#if RERROR_LONGDOUBLE
using Real = long double;
#else
using Real = double;
#endif

// Default Error Value.
Real g_err = 1e-9;    // Too small value is not good.

bool r_eq(Real x, Real y, Real err = g_err) {
  return abs(x - y) <= err || abs(x - y) <= abs(x) * err;
}
bool r_le(Real x, Real y, Real err = g_err) {
  return x - y <= err || x - y <= abs(x) * err;
}
bool r_ge(Real x, Real y, Real err = g_err) { return r_le(y, x, err); }
bool r_gt(Real x, Real y, Real err = g_err) { return !r_le(x, y, err); }
bool r_lt(Real x, Real y, Real err = g_err) { return !r_le(y, x, err); }
bool r_ne(Real x, Real y, Real err = g_err) { return !r_eq(x, y, err); }

bool rp_eq(Real x, Real y, Real err = g_err) { return abs(x - y) <= err; }
bool rp_le(Real x, Real y, Real err = g_err) { return x - y <= err; }
bool rp_ge(Real x, Real y, Real err = g_err) { return rp_le(y, x, err); }
bool rp_gt(Real x, Real y, Real err = g_err) { return !rp_le(x, y, err); }
bool rp_lt(Real x, Real y, Real err = g_err) { return !rp_le(y, x, err); }
bool rp_ne(Real x, Real y, Real err = g_err) { return !rp_eq(x, y, err); }

// ---- end rerror.cc
// ---- inserted library file geometry.cc

#if RERROR_LONGDOUBLE
#define G_PI M_PIl
#else
#define G_PI M_PI
#endif

struct Point {
  Real x;
  Real y;

  Point() : x(0), y(0) {}
  Point(Real x_, Real y_) : x(x_), y(y_) {}

  bool operator ==(const Point& p) const { return x == p.x && y == p.y; }
  bool operator !=(const Point& p) const { return ! (*this == p); }
  bool sim(const Point& p, Real err = g_err) const {
    return r_eq(x, p.x, err) && r_eq(y, p.y, err);
  }
  static bool sim(const Point& p1, const Point& p2,
		      Real err = g_err) { return p1.sim(p2, err); }

  Point& operator +=(const Point& p) { x += p.x; y += p.y; return *this; }
  Point& operator -=(const Point& p) { x -= p.x; y -= p.y; return *this; }
  Point& operator *=(Real k) { x *= k; y *= k; return *this; }
  Point& operator /=(Real k) { x /= k; y /= k; return *this; }
  Point operator +(const Point& p) const { return Point(*this) += p; }
  Point operator -(const Point& p) const { return Point(*this) -= p; }
  Point operator *(Real k) const { return Point(*this) *= k; }
  Point operator /(Real k) const { return Point(*this) /= k; }
  Point operator -() const { return (*this) * (-1); }

  Real len() const { return hypot(x, y); }

  static Point polar(Real r, Real th) {
    return Point(r * cos(th), r * sin(th));
  }

  Point rotate(Real th) const { return polar(len(), atan2(y, x) + th); }
  Point rotateQ() const { return Point(-y, x); }

  bool parallel(const Point& p, Real err = g_err) const {
    return r_eq(x * p.y, y * p.x, err);
  }

  Real innerProd(const Point& p) const { return x * p.x + y * p.y; }
  Real outerProd(const Point& p) const { return x * p.y - y * p.x; }
  Real angle(const Point& p) const {
    Real th = atan2(p.y, p.x) - atan2(y, x);
    return th > G_PI ? th - 2 * G_PI : th <= -G_PI ? th + 2 * G_PI : th;
  }

};

Point operator *(Real k, const Point& p) { return p * k; }
ostream& operator <<(ostream& os, const Point& p) {
  return os << "(" << p.x << ", " << p.y << ")";
}

struct Line {
  Point dir;
  Point base;

  Line() : dir(0,0), base(0,0) {}
  Line(const Point& d, const Point& b) : dir(d), base(b) {}
  
  bool operator ==(const Line& l) const {
    return dir == l.dir && base == l.base;
  }
  bool operator !=(const Line& l) const { return ! (*this == l); }
  bool sim(const Line& l1, Real err = g_err) const {
    return dir.sim(l1.dir, err) && dir.sim(l1.base - base, err);
  }
  static bool sim(const Line& l1, const Line& l2, Real err = g_err) {
    return l1.sim(l2, err);
  }
  
  static Line connect(const Point& p1, const Point& p2) {
    return Line(p2 - p1, p1);
  }

  bool parallel(const Line& l, Real err = g_err) const {
    return dir.parallel(l.dir, err);
  }

  bool ptOn(const Point& p, Real err = g_err) const {
    return dir.parallel(p - base, err);
  }

  Point intersect(const Line& l) const {
    Real d = dir.x * (-l.dir.y) - (-l.dir.x) * dir.y;
    Point z = l.base - base;
    Real t = ((-l.dir.y) * z.x + l.dir.x * z.y) / d;
    return t * dir + base;
  }
  static Point intersect(const Line& l1, const Line& l2) {
    return l1.intersect(l2);
  }
  
  // 垂線の足
  Point perpend_foot(const Point& p) const {
    return intersect(Line(dir.rotateQ(), p));
  }

  // distance between this line and a point
  Real len(const Point& p) const {
    return (p - perpend_foot(p)).len();
  }
  
  

};

ostream& operator <<(ostream& os, const Line& l) {
  return os << "[d " << l.dir << ", b " << l.base << ")";
}

struct Circle {
  Point c;
  Real r;

  Circle() : c(0, 0), r(0) {}
  Circle(const Point& c_, Real r_) : c(c_), r(r_) {}

  bool operator ==(const Circle& o) const { return c == o.c && r == o.r; }
  bool operator !=(const Circle& o) const { return ! (*this == o); }
  bool sim(const Circle& o, Real err = g_err) const {
    return c.sim(o.c, err) && r_eq(r, o.r, err);
  }
  static bool sim(const Circle& c1, const Circle& c2,
		  Real err = g_err) { return c1.sim(c2, err); }

  bool ptOn(const Point& p, Real err = g_err) const {
    return r_eq((p - c).len(), r, err);
  }

  tuple<bool, Point, Point> intersect(const Line& o) const {
    Point f = o.perpend_foot(c);
    Real d = (f - c).len();
    if (d > r) return make_tuple(false, Point(), Point());
    Real t = sqrt(r*r - d*d);
    Point e = o.dir / o.dir.len();
    return make_tuple(true, f + t * e, f - t * e);
  }

  tuple<bool, Point, Point> intersect(const Circle& o) const {
    Real d = (o.c - c).len();
    if (d + r < o.r || d + o.r < r || r + o.r < d) {
      return make_tuple(false, Point(), Point());
    }
    Point v = (o.c - c) / d;
    Real t = (r * r - o.r * o.r + d * d) / (2 * d);
    Line l(v.rotateQ(), c + t * v);
    return intersect(l);
  }

};

ostream& operator <<(ostream& os, const Circle& circ) {
  return os << "[c " << circ.c << ", " << circ.r << "]";
}

// 外心
Point circumcenter(const Point& z1, const Point& z2, const Point& z3) {
  Line l12((z2 - z1).rotateQ(), (z1 + z2) / 2);
  Line l23((z3 - z2).rotateQ(), (z2 + z3) / 2);
  return l12.intersect(l23);
}


// ---- end geometry.cc
// @@ !! LIM  -- end mark --

ll least(auto&& vec) {
  ll i;
  double x = DBL_MAX;
  for (ll j = 0; j < (ll)vec.size(); j++) if (updMin(x, vec.at(j))) i = j;
  return i;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<double> T(N+3), V(N+2);
  vector<double> inc(N+3, DBL_MAX);
  vector<double> dec(N+3, DBL_MAX);
  for (ll i = 2; i < N+2; i++) {
    double t;
    cin >> t;
    T.at(i) = T.at(i-1) + t;
  }
  T.at(0) = -1;
  T.at(N+2) = T.at(N+1) + 1;
  for (ll i = 1; i < N+1; i++) cin >> V.at(i);
  V.at(0) = V.at(N+1) = 0;
  for (ll i = 0; i < N+2; i++) {
    for (ll j = i+1; j < N+2; j++) {
      updMin(inc.at(j), V.at(i) + T.at(j) - T.at(i+1));
    }
    for (ll j = 1; j <= i; j++) {
      updMin(dec.at(j), V.at(i) + T.at(i) - T.at(j));
    }
  }
  double ans = 0;
  for (ll i = 1; i < N+1; i++) {
    double z;
    double tt = T.at(i+1) - T.at(i);
    double kL = least(vector<double>({V.at(i), dec.at(i), inc.at(i)}));
    double kR = least(vector<double>({V.at(i), dec.at(i+1), inc.at(i+1)}));
    if (kL == 1) {
      z = (dec.at(i) + dec.at(i) - tt) * tt / 2.0;
    }else if (kR == 2) {
      z = (inc.at(i) + inc.at(i) - tt) * tt / 2.0;
    }else if (kL == 0 && kR == 0) {
      z = V.at(i) * tt;
    }else if (kL == 2 && kR == 0) {
      double y = V.at(i) - inc.at(i);
      z = V.at(i) * tt - y * y / 2.0;
    }else if (kL == 0 && kR == 1) {
      double y = V.at(i) - dec.at(i+1);
      z = V.at(i) * tt - y * y / 2.0;
    }else if (kL == 2 && kR == 1) {
      Line lInc(Point(1,1), Point(T.at(i), inc.at(i)));
      Line lDec(Point(1,-1), Point(T.at(i+1), dec.at(i+1)));
      Point p = lInc.intersect(lDec);
      if (p.y <= V.at(i)) {
	z = (inc.at(i) + p.y) * (p.x - T.at(i)) / 2.0 +
	    (dec.at(i+1) + p.y) * (T.at(i+1) - p.x) / 2.0;
      }else {
	double y1 = V.at(i) - inc.at(i);
	double y2 = V.at(i) - dec.at(i+1);
	z = V.at(i) * tt - y1 * y1 / 2.0 - y2 * y2 / 2.0;
      }
    }else assert(0);
    ans += z;
  }
  cout << ans << endl;

  return 0;
}

