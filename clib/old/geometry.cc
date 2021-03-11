#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Utility functions for geometry

  Real means double unless RERROR_LONGDOUBLE is true, 
    in that case it is long double.

  Real g_err = 1e-9;
  bool r_sim(x, y[, err]); // x and y are nearlly equal.  relative or
                           //absolute error is less than err (default is g_err)

  G_PI is either M_PI or M_PIl.


  Point
    Point p(x, y);
    cout << p.x << p.y;
    cout << p;
    p.sim(q);  //  p and q are neally equal
    p = p1 + (p2 - (p3 * 4.0 / 5.0)) // etc...
    dist = (p1 - p2).len();   // length
    p = Point::polar(5, sin(M_PI/4));  // polar expression
    q = p.rotate(M_PI * 2.0/3.0);
    q = p.rotateQ();                 // similar to p.rotate(G_PI/2);
    if (p.parallel(q [, err])) ...
    Real ip = p.innerProd(q);
    Real op = p.outerProd(q);
    Real th = p.arg();
    Real th = p.angle(q);    // angle from vector p to vector q; 
                             // -G_PI < th <= G_PI

  Line
    Line l(d, b);       // direction vector and a point on it
    cout << l.dir << l.base;
    cout << l;
    if (l1.sim(l2)) ...
    Line l = Line::connect(p1, p2)  // line both p1 and o2 on it
    if (l1.parallel(l2)) ....
    if (l.ptOn(p)) ...  // Point p is on Line l
    Point p = l1.intersect(l2);
    Point p = l1.perpend_foot(p1); 
    Real r = l.len(p);    // distance between Line and Point

  Circle
    Circle circ(c_, r_)   // center and radius
    cout << circ.c << circ.r;
    cout << circ;
    if (c1.sim(c2)) ...
    if (circ.ptOn(p)) ...   // Point on Circle's boundary
    bool b; Point p1, p2; tie(b, p1, p2) = circ.intersect(l);
       // intersection between Circle and Line
    bool b; Point p1, p2; tie(b, p1, p2) = circ1.intersect(circ2);
       // intersection between two circles

  Others

  Point p = circumcenter(p1, p2, p3);   外心
 */


// @@ !! LIM(debug rerror rerror)
// --> f:<< debug rerror
// ---- inserted function << from util.cc
template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ")";
  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const set<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const multiset<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const map<T1, T2>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  bool first = true;
  os << '[';
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}
// ---- end <<
// ---- inserted library file debug.cc
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(Head&& head) {
  cerr << head << endl;
}

template <class Head, class... Tail>
void dbgLog(Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(__VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

// ---- end debug.cc
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
// @@ !! LIM  -- end mark --


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN(rerror) ---- geometry.cc

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
  Real arg() const { return atan2(y, x); }
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


// @@ !! END ---- geometry.cc

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  
  Point orig(0, 0), pux(1, 0), puy(0, 1);
  Point p01(3, 4), p02(-4, -3), p03(1, -2), p04(2, -1), p05(-1, 1);
  Point p06(0.0001, -0.0001), p07(-1e10, 1e10);

  assert(orig == orig);
  assert(pux != puy);
  assert(p01 + p02 == p05);
  assert(p02 - p03 == Point(-5, -1));
  assert(p04 * 3 == Point(6, -3));
  assert(2 * p04 == Point(4, -2));
  assert(Point(12, 16) / 4 == p01);
  assert(-p05 == Point(1, -1));
  assert(orig.sim(Point(1e-14, -1e-14)));
  assert(!orig.sim(pux));
  assert(orig.sim(Point(-0.01, 0.01), 0.1));
  assert(!orig.sim(p06));
  assert(p07.sim(p07+p06));
  assert(abs(p01.len() - 5) < g_err);
  assert(Point::polar(4, M_PI*2/3).sim(Point(-2, 2*sqrt(3))));
  assert(pux.rotate(M_PI/4).sim(Point(sqrt(2)/2, sqrt(2)/2)));
  assert(p03.rotate(-M_PI/2).sim(Point(-2, -1)));

  Line l01(pux + puy, orig), l02(p05, 2*puy);
  Line l03(p04, p01 + 4 * p04), l04(p02, p01 - 7 * p02);
  assert(!l01.parallel(l02));
  assert(l01.parallel(Line(l02.dir.rotateQ(), l02.base)));
  assert(l01.ptOn(Point(-3, -3)));
  assert(! l02.ptOn(p03));
  assert(l01.intersect(l02).sim(Point(1,1)));
  assert(l03.intersect(l04).sim(p01));
  assert(r_eq(l01.len(p01), sqrt(2)/2));
  assert(r_eq(Line(p01.rotateQ(), p01).len(orig), 5));

  Point p08(1, -2), p09(4, 2);
  Circle c01(p09, 2), c02(p08, 1), c03(p08, 4), c04(p08, 10);
  Line l05(p02, p09 + 3 * (p02/p02.len()).rotateQ());
  Line l06(p03, p09 + 1 * (p03/p03.len()).rotateQ());
  bool b; Point tmp_p1, tmp_p2;
  tie(b, tmp_p1, tmp_p2) = c01.intersect(l05);
  assert(!b);
  tie(b, tmp_p1, tmp_p2) = c01.intersect(l06);
  assert(b && l06.ptOn(tmp_p1) && c01.ptOn(tmp_p1)
	 && l06.ptOn(tmp_p2) && c01.ptOn(tmp_p2));
  tie(b, tmp_p1, tmp_p2) = c01.intersect(c02);
  assert(!b);
  tie(b, tmp_p1, tmp_p2) = c01.intersect(c04);
  assert(!b);
  tie(b, tmp_p1, tmp_p2) = c03.intersect(c01);
  assert(b && c01.ptOn(tmp_p1) && c03.ptOn(tmp_p1)
	 && c01.ptOn(tmp_p2) && c03.ptOn(tmp_p2));

  assert(circumcenter(Point(0,0), Point(2,0), Point(1,sqrt(3))
		      ).sim(Point(1, sqrt(3)/3)));
  assert(circumcenter(Point(4,5), Point(5,4), Point(-3,4)
		      ).sim(Point(1,1)));

  Point p10(7,2), p11(-3, 5);
  assert(r_eq(p10.innerProd(p11), -11));
  assert(r_eq(p11.innerProd(p10), -11));
  assert(r_eq(p10.outerProd(p11), 41));
  assert(r_eq(p11.outerProd(p10), -41));
  assert(r_eq(Point(1,1).angle(Point(-1,0)), G_PI*0.75));
  assert(r_eq(Point(-1,0).angle(Point(1,1)), -G_PI*0.75));
  for (ll i = 0; i < 20; i++) {
    Point p12 = p10.rotate(i*G_PI/10);
    assert(r_eq(p10.innerProd(p12),
		p10.len() * p12.len() * cos(p10.angle(p12))));
    assert(r_eq(p10.outerProd(p12),
		p10.len() * p12.len() * sin(p10.angle(p12))));
  }

  cout << "Test done." << endl;

}
