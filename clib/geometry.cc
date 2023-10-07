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
    cin >> p;
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
    Real th = p.arg();    // angle of p (atan2(p.y, p.x)), -G_PI <= th <= G_PI
    Real th = p.angle(q); // angle from vector p to vector q; 
                          // -G_PI < th <= G_PI

  Line
    Line l(d, b);       // direction vector and a point on it
    cout << l.dir << l.base;
    cout << l;
    if (l1.sim(l2)) ...
    Line l = Line::connect(p1, p2)  // line both p1 and o2 on it
    if (l1.parallel(l2)) ....
    if (l.ptOn(p)) ...  // Point p is on Line l
    int code = l.ptSide(p);
      // Judges if Point p is on Line l.
      // Return Value: Line::SIDE_ON ... on
      //               Line::SIDE_P ... angle from vector dir to 
      //                                vector (base->p) is in [0, pi]
      //               Line::SIDE_N ... angle from vector dir to 
      //                                vector (base->p) is in (-pi, 0]
    // Line Intersection:
    int code; Real r1, r2; tie(code, r1, r2) = l1.intersect_coeff(l2)
      // code == Line::IST_NONE ... no intersection
      // code == Line::IST_ALL  ... coincide
      // code == Line::IST_ONE  ... one intersection,
      //   in this case, l1.base + r1 * l1.dir == l2.base + r2 * l2.dir is the
      //   intersection.
      //   In particular, if 0 < r1 < 1, then the intersection internally 
      //   divides l1 at r1 : 1 - r1.
    Point p = l1.unsafe_intersect(l2);
    Real  r1 = l1.perpend_foot_coeff(p1);
    Point p2 = l1.perpend_foot(p1);  // p2 == l1.base + r1 * l1.dir
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

    Point p = circumcenter(p1, p2, p3);   // 外心
      // NOTE: You must confirm (p2 - p1).parallel(p3 - p2) is false.
      //       (In that case p would be an infinitely far point.)
    vector<Point> pts({...});
    vector<Point> ch = convex_hull(pts);
      // a point can occur repeatedly in pts
    auto [dist, i, j] = convex_diameter(ch); 
      // ch.at(i) and ch.at(j) are the farest two points in ch.  
      // dist is the distance between the two.
      // ch must be convex, and sorted counter-clockwise.
      // I.e., ch must be what is returned from convex_hull.
    int code = in_polygon(q, ps);  
      // Judges if Point q is in polygon ps.  The points in ps should be listed counter-clockwise.
      // The polygon should be CONVEX and has POSITIVE area.
      // Return Value: Line::SIDE_N ... outside
      //               Line::SIDE_P ... inside
      //               LINE::SIDE_ON ... boundary
    int code = in_triangle(q, p1, p2, p3);
      // Judges if Point q is in triangle p1-p2-p3.
      // The order of p1-p2-p3 is arbitrary (not necessary counter-clockwise), but should have POSITIVE area.
 */


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN(rerror f:updMaxMin) ---- geometry.cc

#if RERROR_LONGDOUBLE
#define G_PI 3.141592653589793238462643383279502884L
#else
#define G_PI 3.14159265358979323846
#endif

struct Point {
  Real x;
  Real y;

  Point() : x(0), y(0) {}
  Point(Real x_, Real y_) : x(x_), y(y_) {}

  bool operator ==(const Point& p) const { return x == p.x && y == p.y; }
  bool operator !=(const Point& p) const { return ! (*this == p); }
  bool sim(const Point& p, Real err = g_err) const {
    return may_eq(x, p.x, err) && may_eq(y, p.y, err);
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
    return may_eq(x * p.y, y * p.x, err);
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
istream& operator >>(istream& is, Point& p) { is >> p.x >> p.y; return is; }
ostream& operator <<(ostream& os, const Point& p) { return os << "(" << p.x << ", " << p.y << ")"; }

struct Line;
ostream& operator <<(ostream& os, const Line& l);

struct Line {
  Point dir;
  Point base;

  static Line x_axis;
  static Line y_axis;

  static constexpr int SIDE_ON = 1;
  static constexpr int SIDE_P  = 2;
  static constexpr int SIDE_N  = 4;
  static constexpr int IST_NONE = -1;
  static constexpr int IST_ALL = -2;
  static constexpr int IST_ONE = 0;

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

  int ptSide(const Point& p, Real err = g_err) const {
    Real t1 = dir.y * (p.x - base.x);
    Real t2 = dir.x * (p.y - base.y);
    if (may_eq(t1, t2, err)) return SIDE_ON;
    if (may_le(t1, t2, err)) return SIDE_P;
    return SIDE_N;
  }

  bool ptOn(const Point& p, Real err = g_err) const {
    return ptSide(p, err) == SIDE_ON;
  }

  tuple<int, Real, Real> intersect_coeff(const Line& l) const {
    if (dir.parallel(l.dir)) {
      if (ptOn(l.base)) return make_tuple(IST_ALL, 0, 0);
      else              return make_tuple(IST_NONE, 0, 0);
    }else {
      Real d = dir.x * (-l.dir.y) - (-l.dir.x) * dir.y;
      Point z = l.base - base;
      Real t1 = ((-l.dir.y) * z.x + l.dir.x * z.y) / d;
      Real t2 = ((-dir.y) * z.x + dir.x * z.y) / d;
      return {IST_ONE, t1, t2};
    }
  }

  Point unsafe_intersect(const Line& l) const {
    auto [rc, t1, t2] = intersect_coeff(l);
    assert(rc == IST_ONE);
    return base + t1 * dir;
  }

  // 垂線の足
  Point perpend_foot(const Point& p) const {
    Real t1 = perpend_foot_coeff(p);
    return base + t1 * dir;
  }

  Real perpend_foot_coeff(const Point& p) const {
    auto [rc, t1, t2] = intersect_coeff(Line(dir.rotateQ(), p));
    return t1;
  }

  // distance between this line and a point
  Real len(const Point& p) const {
    return (p - perpend_foot(p)).len();
  }
  
  

};

ostream& operator <<(ostream& os, const Line& l) {
  return os << "[d " << l.dir << ", b " << l.base << "]";
}
Line Line::x_axis(Point(1,0), Point(0,0));
Line Line::y_axis(Point(0,1), Point(0,0));

struct Circle {
  Point c;
  Real r;

  Circle() : c(0, 0), r(0) {}
  Circle(const Point& c_, Real r_) : c(c_), r(r_) {}

  bool operator ==(const Circle& o) const { return c == o.c && r == o.r; }
  bool operator !=(const Circle& o) const { return ! (*this == o); }
  bool sim(const Circle& o, Real err = g_err) const {
    return c.sim(o.c, err) && may_eq(r, o.r, err);
  }
  static bool sim(const Circle& c1, const Circle& c2,
		  Real err = g_err) { return c1.sim(c2, err); }

  bool ptOn(const Point& p, Real err = g_err) const {
    return may_eq((p - c).len(), r, err);
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
  return l12.unsafe_intersect(l23);
}

vector<Point> convex_hull(const vector<Point>& pts) {
  vector<Point> spts(pts);
  int n = pts.size();
  if (n == 0) return vector<Point>();

  auto sub = [&]() -> vector<Point> {
    vector<Point> ret;
    for (int i = 0; i < n; i++) {
      Point pt = spts.at(i);
      if (i > 0 && spts.at(i-1).sim(spts.at(i))) continue;
      while (true) {
	int rs = ret.size();
	if (rs - 2 < 0) break;
	Point q0 = ret.at(rs - 2);
	Point q1 = ret.at(rs - 1);
	if ((q0 - q1).outerProd(pt - q1) < 0) break;
	ret.pop_back();
      }
      ret.push_back(pt);
    }
    ret.pop_back();
    return ret;
  };

  sort(spts.begin(), spts.end(),
       [](const Point& a, const Point& b) -> bool {
	 if (a.x != b.x) return a.x < b.x;
	 return a.y < b.y;
       });
  auto vec1 = sub();
  // DLOG("vec1=", vec1);
  reverse(spts.begin(), spts.end());
  auto vec2 = sub();
  // DLOG("vec2=", vec2);
  vec1.insert(vec1.end(), vec2.begin(), vec2.end());
  if (vec1.empty()) return vector<Point>({pts.at(0)});
  return vec1;
}

// diameter (the distance between the farest two points)
// pts should be convex, and sorted counter-clockwise.
tuple<Real, int, int> convex_diameter(const vector<Point>& pts) {
  int n = pts.size();
  if (n <= 1) {
    cerr << "diameter is called with <=1 points.\n";
    exit(1);
  }

  auto conn = [&](ll i, ll j) -> Point {
    return pts.at(j % n) - pts.at(i % n);
  };
  auto edge = [&](ll i) -> Point { return conn(i, i+1); };

  if (n == 2) return make_tuple(conn(0,1).len(), 0, 1);

  int k = -1;
  int m = -1;
  for (int i = 0, cnt = 0; cnt < 2; i++) {
    if (edge(i).y <= 0 && edge(i+1).y > 0) { m = i+1; cnt++; }
    if (edge(i).y >= 0 && edge(i+1).y < 0) { k = i+1; cnt++; }
  }
  // DLOG("init.  k=", k, "m=", m);

  Real vmax = 0;
  int k0 = -1, m0 = -1;
  bool run_k = true;
  bool run_m = true;
  while (run_k || run_m) {
    if (!run_m || (run_k && edge(k).arg() - (-G_PI) <= edge(m).arg())) {
      // DLOG("check1 k+1=", (k+1) % n, "m=", m % n);
      if (updMax(vmax, conn(k+1, m).len())) { k0 = k+1, m0 = m; }
      k++;
      if (edge(k).y > 0) run_k = false;
    }else {
      // DLOG("check2 k=", k % n, "m+1=", (m+1) % n);
      if (updMax(vmax, conn(k, m+1).len())) { k0 = k, m0 = m+1; }
      m++;
      if (edge(m).y < 0) run_m = false;
    }
  }
  return make_tuple(vmax, k0 % n, m0 % n);
}

// The polygon should be convex.  Vector vs should be in counter-clockwise
int in_polygon(const Point& pt, const vector<Point>& vs) {
  int sz = vs.size();
  bool on_edge = false;
  for (int i = 0; i < sz; i++) {
    int c = Line::connect(vs[i], vs[(i + 1) % sz]).ptSide(pt);
    if (c == Line::SIDE_N) return Line::SIDE_N;
    if (c == Line::SIDE_ON) on_edge = true;
  }
  return on_edge ? Line::SIDE_ON : Line::SIDE_P;
}

int in_triangle(const Point& pt, const Point& A, const Point& B, const Point& C) {
  if (Line::connect(A, B).ptSide(C) == Line::SIDE_P) return in_polygon(pt, vector<Point>{A, B, C});
  else return in_polygon(pt, vector<Point>{B, A, C});
}

/*
int in_triangle(const Point& pt, const Point& tr0,
		const Point& tr1, const Point& tr2) {
  auto chk = [&](const Point& b, const Point& e, const Point& p) -> bool {
    Point be = e - b;
    Point bp = p - b;
    Real r = may_eq(be.x, 0.0) ? bp.y / be.y : bp.x / be.x;
    return 0.0 <= r && r <= 1.0;
  };

  Line l01 = Line::connect(tr0, tr1);
  Line l12 = Line::connect(tr1, tr2);
  Line l20 = Line::connect(tr2, tr0);
  int side = l01.ptSide(tr2);
  if (side == Line::SIDE_ON) {
    if (!l01.ptOn(pt)) return Line::SIDE_N;
    return chk(tr0, tr1, pt) || chk(tr1, tr2, pt) || chk(tr2, tr0, pt) ?
      Line::SIDE_ON : Line::SIDE_N;
  }
  int other = side ^ (Line::SIDE_P | Line::SIDE_N);
  if (l01.ptSide(pt) == other || l12.ptSide(pt) == other ||
      l20.ptSide(pt) == other) return Line::SIDE_N;
  if (l01.ptSide(pt) == Line::SIDE_ON || l12.ptSide(pt) == Line::SIDE_ON ||
      l20.ptSide(pt) == Line::SIDE_ON) return Line::SIDE_ON;
  return Line::SIDE_P;
}
*/

// @@ !! END ---- geometry.cc
