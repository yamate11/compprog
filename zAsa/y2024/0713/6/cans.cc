#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(geometry debug)

// ---- inserted library file rerror.cc

#if RERROR_LONGDOUBLE
using Real = long double;
#else
using Real = double;
#endif

// Default Error Value.
Real g_err = 1e-9;    // Too small value is not good.

bool may_eq(Real x, Real y, Real err = g_err, bool abs_only = false) {
  return abs(x - y) <= err or (not abs_only and abs(x - y) <= abs(x) * err);
}
bool may_le(Real x, Real y, Real err = g_err, bool abs_only = false) {
  return x - y <= err or (not abs_only and x - y <= abs(x) * err);
}
bool may_ge(Real x, Real y, Real err = g_err, bool abs_only = false) {
  return y - x <= err or (not abs_only and y - x <= abs(x) * err);
}

bool may_eq_abs_only(Real x, Real y, Real err = g_err) { return may_eq(x, y, err, true); }
bool may_le_abs_only(Real x, Real y, Real err = g_err) { return may_le(x, y, err, true); }
bool may_ge_abs_only(Real x, Real y, Real err = g_err) { return may_ge(x, y, err, true); }


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

// ---- end geometry.cc

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig);

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig);

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st);

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t);
#endif

ostream& operator<< (ostream& os, int8_t x);

ostream& operator<< (ostream& os, const __int128& x);

// definitions

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

// for Enum type; just displays ordinals.
template <typename E>
typename std::enable_if<std::is_enum<E>::value, std::ostream&>::type
operator<<(std::ostream& os, E e) {
    return os << static_cast<typename std::underlying_type<E>::type>(e);
}

// This is a very ad-hoc implementation...
ostream& operator<<(ostream& os, const __int128& v) {
  unsigned __int128 a = v < 0 ? -v : v;
  ll i = 0;
  string s(64, ' ');
  if (v == 0) {
    s[i++] = '0';
  }else {
    while (a > 0) {
      s[i++] = '0' + (char)(a % 10);
      a /= 10;
    }
  }
  if (v < 0) {
    s[i++] = '-';
  }
  s.erase(s.begin() + i, s.end());
  reverse(s.begin(), s.end());
  os << s;
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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpMVec(N, ((Pt, type=Point), (VT, type=double), (VR, type=double))) [bfQwHoPD]
  auto Pt = vector(N, Point());
  auto VT = vector(N, double());
  auto VR = vector(N, double());
  for (int i = 0; i < N; i++) {
    Point v1; cin >> v1; Pt[i] = v1;
    double v2; cin >> v2; VT[i] = v2;
    double v3; cin >> v3; VR[i] = v3;
  }
  // @End [bfQwHoPD]

  double big = 1e18;
  vector<double> time(N, big);
  using sta = pair<double, ll>;
  priority_queue<sta, vector<sta>, greater<sta>> pque;
  time[0] = 0.0;
  pque.emplace(0.0, 0);
  while (not pque.empty()) {
    auto [t, n] = pque.top(); pque.pop();
    if (may_eq(t, time[n])) {
      REP(p, 0, N) {
        if (p == n) continue;
        double vel = min(VT[n], VR[p]);
        double new_t = t + (Pt[n] - Pt[p]).len() / vel;
        // if (n != 0) new_t += 1.0;
        if (new_t < time[p]) {
          time[p] = new_t;
          pque.emplace(new_t, p);
        }
      }
    }
  }
  DLOGK(time);
  sort(ALL(time), greater<double>());
  double ans = 0;
  REP(i, 0, N - 1) {
    ans = max(ans, i + time[i]);
  }
  cout << ans << endl;
  return 0;
}

