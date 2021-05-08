#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug rerror f:updMaxMin geometry)

// ---- inserted function f:<< from util.cc
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

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig) {
  queue<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig) {
  deque<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop_front();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
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

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st) {
  stack<T> tmp(st);
  os << '[';
  bool first = true;
  while (!tmp.empty()) {
    T& t = tmp.top();
    if (first) first = false;
    else os << ", ";
    os << t;
    tmp.pop();
  }
  os << ']';
  return os;
}

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t) {
  if (t.has_value()) os << "v(" << t.value() << ")";
  else               os << "nullopt";
  return os;
}
#endif

ostream& operator<< (ostream& os, int8_t x) {
  os << (int32_t)x;
  return os;
}

// ---- end f:<<

// ---- inserted library file debug.cc
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(bool with_nl, Head&& head) {
  cerr << head;
  if (with_nl) cerr << endl;
}

template <class Head, class... Tail>
void dbgLog(bool with_nl, Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(with_nl, forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DLOGNNL(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

/*
#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL_LIB(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif
*/

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)
#define DUP9(E1,...)   DUP1(E1), DUP8(__VA_ARGS__)
#define DUP10(E1,...)   DUP1(E1), DUP9(__VA_ARGS__)
#define DUP11(E1,...)   DUP1(E1), DUP10(__VA_ARGS__)
#define DUP12(E1,...)   DUP1(E1), DUP11(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP12, DUP11, DUP10, DUP9, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

#if DEBUG_LIB
  #define DLOG_LIB   DLOG
  #define DLOGK_LIB  DLOGK
  #define DLOGKL_LIB DLOGKL
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

// ---- inserted function f:updMaxMin from util.cc
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
// ---- end f:updMaxMin

// ---- inserted library file geometry.cc

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
    if (r_eq(t1, t2, err)) return SIDE_ON;
    if (r_lt(t1, t2, err)) return SIDE_P;
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
  return os << "[d " << l.dir << ", b " << l.base << ")";
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

int in_triangle(const Point& pt, const Point& tr0,
		const Point& tr1, const Point& tr2) {
  auto chk = [&](const Point& b, const Point& e, const Point& p) -> bool {
    Point be = e - b;
    Point bp = p - b;
    Real r = r_eq(be.x, 0.0) ? bp.y / be.y : bp.x / be.x;
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

// ---- end geometry.cc

// @@ !! LIM -- end mark --

bool pt_comp(const Point& a, const Point& b) {
  if (a.x != b.x) return a.x < b.x;
  return a.y < b.y;
}

vector<Point> naive_convex_hull(const vector<Point>& o_pts) {
  vector<Point> spts(o_pts);
  sort(spts.begin(), spts.end(), pt_comp);
  vector<Point> pts;
  for (int i = 0; i < (int)spts.size(); i++) {
    if (i == 0 || !spts.at(i-1).sim(spts.at(i))) pts.push_back(spts.at(i));
  }

  unordered_set<int> inner;
  int n = pts.size();

  auto check2 = [&](int m) -> void {
    if (inner.find(m) != inner.end()) return;
    for (int i = 0; i < n; i++) {
      if (m == i) continue;
      if (inner.find(i) != inner.end()) continue;
      for (int j = i+1; j < n; j++) {
	if (m == j) continue;
	if (inner.find(j) != inner.end()) continue;
	Point q1 = pts.at(i) - pts.at(m);
	Point q2 = pts.at(j) - pts.at(m);
	if (!q1.parallel(q2)) continue;
	if (!r_eq(q1.x, 0.0)) {
	  if (q2.x / q1.x < 0) { inner.insert(m); return; }
	}else {
	  if (q2.y / q1.y < 0) { inner.insert(m); return; }
	}
      }
    }
  };

  auto check3 = [&](int m) -> void {
    if (inner.find(m) != inner.end()) return;
    for (int i = 0; i < n; i++) {
      if (m == i) continue;
      if (inner.find(i) != inner.end()) continue;
      for (int j = i+1; j < n; j++) {
	if (m == j) continue;
	if (inner.find(j) != inner.end()) continue;
	for (int k = j+1; k < n; k++) {
	  if (m == k) continue;
	  if (inner.find(k) != inner.end()) continue;
	  if (in_triangle(pts.at(m), pts.at(i), pts.at(j), pts.at(k))
	      != Line::SIDE_N) {
	    inner.insert(m);
	    return;
	  }
	}
      }
    }
  };
  for (int m = 0; m < n; m++) check2(m);
  for (int m = 0; m < n; m++) check3(m);
  vector<Point> ret;
  for (int m = 0; m < n; m++) {
    if (inner.find(m) == inner.end()) ret.push_back(pts.at(m));
  }
  return ret;
}

tuple<Real, int, int> naive_diameter(const vector<Point>& pts) {
  int n = pts.size();
  Real vmax = 0.0;
  int i0 = -1;
  int j0 = -1;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (updMax(vmax, (pts.at(i) - pts.at(j)).len())) {
	i0 = i;
	j0 = j;
      }
    }
  }
  return make_tuple(vmax, i0, j0);
}

mt19937 rng;

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);
  
  {
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
    assert(l01.unsafe_intersect(l02).sim(Point(1,1)));
    assert(l03.unsafe_intersect(l04).sim(p01));
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
  }

  {
    Point pt1(1,1), pt2(-2,3), dir1(1,2), dir2(3,2), ptC(4,7);
    Line l1(dir1, pt1), l2(dir2, pt2);
    auto [rc1, t11, t21] = l1.intersect_coeff(l2);
    assert(rc1 == Line::IST_ONE && ptC.sim(pt1 + t11 * dir1)
	   && ptC.sim(pt2 + t21 * dir2));
    Line l3(-dir1, pt1 + 4.0 * dir1);
    auto [rc3, t13, t23] = l1.intersect_coeff(l3);
    assert(rc3 == Line::IST_ALL);
    Line l4(-dir1, pt2);
    auto [rc4, t14, t24] = l1.intersect_coeff(l4);
    assert(rc4 == Line::IST_NONE);
  }

  {
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
  }

  {
    Point orig(0, 0), pux(1, 0), puy(0, 1);
    Line l01(pux + puy, orig);
    assert(l01.ptOn(Point(2,2)));
    assert(l01.ptSide(Point(3,2)) == Line::SIDE_N);
    assert(l01.ptSide(Point(3,4)) == Line::SIDE_P);
    Line l07(-(pux + puy), orig);
    assert(l07.ptSide(Point(3,3)) == Line::SIDE_ON);
    assert(l07.ptSide(Point(3,2)) == Line::SIDE_P);
    assert(l07.ptSide(Point(3,4)) == Line::SIDE_N);

    Point p13(2,2), p14(6,4), p15(4,8), p16(3,3), p17(5,6), p18(5,9),
      p19(10,6), p20(8,5), p21(14,8), p22(0,1), p23(4,3);
    assert(in_triangle(p16, p13, p14, p15) == Line::SIDE_P);
    assert(in_triangle(p17, p13, p14, p15) == Line::SIDE_ON);
    assert(in_triangle(p18, p13, p14, p15) == Line::SIDE_N);
    assert(in_triangle(p15, p13, p14, p15) == Line::SIDE_ON);
    assert(in_triangle(p20, p13, p19, p14) == Line::SIDE_ON);
    assert(in_triangle(p23, p13, p19, p14) == Line::SIDE_ON);
    assert(in_triangle(p21, p13, p19, p14) == Line::SIDE_N);
    assert(in_triangle(p22, p13, p19, p14) == Line::SIDE_N);
    assert(in_triangle(p15, p13, p19, p14) == Line::SIDE_N);
  }

  {
    // testing convex_hull and convex_diameter
    vector<Point> pts1 = {{0,0}, {2,0}, {2,2}, {0,2}, {1,1}, {0,1}, {2,1}};
    auto ch1 = convex_hull(pts1);
    assert(ch1 == vector<Point>({{0,0}, {2,0}, {2,2}, {0,2}}));
    assert(r_eq(get<0>(convex_diameter(ch1)), 2.0*sqrt(2.0)));

    vector<Point> pts2 = {{0,0}, {3,0}, {5,0}, {1,2}, {4,2}};
    auto ch2 = convex_hull(pts2);
    assert(ch2 == vector<Point>({{0,0}, {5,0}, {4,2}, {1,2}}));
    assert(r_eq(get<0>(convex_diameter(ch2)), 5.0));
  
    vector<Point> pts3 = {{0,5}, {1,4}, {1,8}, {2,1}, {2,2}, {3,5}, {3,8}, {4,5}};
    auto ch3 = convex_hull(pts3);
    assert(ch3 == vector<Point>({{0,5}, {2,1}, {4,5}, {3,8}, {1,8}}));

    vector<Point> pts4 = {{2,2}, {1,1}, {2,2}, {1,1}, {2,2}};
    auto ch4 = convex_hull(pts4);
    assert(ch4 == vector<Point>({{1,1}, {2,2}}));

    vector<Point> pts5 = {{2,2}, {2,2}, {2,2}};
    auto ch5 = convex_hull(pts5);
    assert(ch5 == vector<Point>({{2,2}}));
  
    rng.seed(time(0));
    // rng.seed(0);
  
    int repeat = 10000;
    int size1 = 10;
    int num = 5;
    uniform_int_distribution<int> dist(0, size1);
    for (int t = 0; t < repeat; t++) {
      vector<Point> pts;
      for (int i = 0; i < num; i++) {
	double x = dist(rng);
	double y = dist(rng);
	pts.emplace_back(x, y);
      }
      auto ch = convex_hull(pts);
      auto nch = naive_convex_hull(pts);
      double d, nd; int i, j, ni, nj;
      tie(d, i, j) = convex_diameter(ch);
      tie(nd, ni, nj) = naive_diameter(pts);
      vector<Point> chx(ch);
      vector<Point> nchx(nch);
      sort(chx.begin(), chx.end(), pt_comp);
      sort(nchx.begin(), nchx.end(), pt_comp);
      if (chx != nchx) {
	// DLOG("pts=", pts);
	// DLOG("ch=", ch);
	// DLOG("nch=", nch);
      }
      assert(chx == nchx);
      if (!r_eq(d, nd)) {
	// DLOG("pts=", pts);
	// DLOG("ch=", ch);
	// DLOG("d=", d, ch.at(i), ch.at(j));
	// DLOG("nd=", nd, pts.at(ni), pts.at(nj));
      }
      assert(r_eq(d, nd));
    }

    // end  (convex_hull and convex_diameter)
  }

  cout << "Test done." << endl;

}
