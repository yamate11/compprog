#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(geometry debug)
// --> rerror f:updMaxMin geometry f:<< debug
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

#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(__VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif

// ---- end debug.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> XL(N), XR(N), Y(N);
  vector<Point> points;
  for (ll i = 0; i < N; i++) {
    cin >> XL.at(i) >> XR.at(i) >> Y.at(i);
    points.emplace_back(XL.at(i), Y.at(i));
    points.emplace_back(XR.at(i), Y.at(i));
  }
  if (N == 1) {
    cout << XR.at(0) - XL.at(0) << endl;
    return 0;
  }

  using StA = pair<double, double>;
  vector<StA> cov;
  for (ll i= 0; i < N; i++) {
    for (ll j = i+1; j < N; j++) {
      if (Y.at(i) == Y.at(j)) continue;
      ll dy = Y.at(i) - Y.at(j);
      double u1 = double(XL.at(i) - XR.at(j)) / dy;
      double u2 = double(XR.at(i) - XL.at(j)) / dy;
      if (u1 < u2) cov.emplace_back(u1, u2);
      else         cov.emplace_back(u2, u1);
    }
  }
  sort(cov.begin(), cov.end());
  DLOG("cov=", cov);
  vector<double> cand;
  ll szc = cov.size();
  double lim = 0;
  for (ll i = 0; i < szc; i++) {
    auto [l, r] = cov.at(i);
    if (i == 0) {
      cand.push_back(l);
      lim = r;
    }else {
      if (lim <= l) {
	cand.push_back(lim);
	cand.push_back(l);
	lim = r;
      }else {
	lim = max(lim, r);
      }
    }
    if (i == szc - 1) {
      cand.push_back(lim);
    }
  }
  DLOG("cand=", cand);
  
  if (cand.empty()) {
    ll xmax = XR.at(0);
    ll xmin = XL.at(0);
    for (ll i = 1; i < N; i++) {
      xmax = max(xmax, XR.at(i));
      xmin = min(xmin, XL.at(i));
    }
    cout << xmax - xmin << endl;
    return 0;
  }

  Line xaxis(Point(1,0), Point(0,0));
  vector<Point> chull = convex_hull(points);
  DLOG("chull=", chull);
  ll szhull = chull.size();
  ll imin = 0;
  ll imax = 0;
  ll ymin = chull.at(0).y;
  ll ymax = chull.at(0).y;
  for (ll i = 1; i < (ll)chull.size(); i++) {
    ll yy = chull.at(i).y;
    if (yy < ymin) {
      imin = i;
      ymin = yy;
    }
    if (ymax < yy) {
      imax = i;
      ymax = yy;
    }
  }
  ll iL = imin;
  ll iR = imax;
  double ans = DBL_MAX;
  auto prev = [&](ll i) -> ll { return (i - 1 + szhull) % szhull; };
  auto next = [&](ll i) -> ll { return (i + 1) % szhull; };
  auto suit = [&](ll i, double t) -> bool {
    ll ip = prev(i);
    ll in = next(i);
    Point dir1 = chull.at(i) - chull.at(ip);
    Point dir2 = chull.at(in) - chull.at(i);
    Point dirA = Point(t, 1);
    Point dirB = -dirA;
    Real th1A = dir1.angle(dirA);
    Real th2A = dirA.angle(dir2);
    Real th1B = dir1.angle(dirB);
    Real th2B = dirB.angle(dir2);
    bool b = ((th1A >= 0) == (th2A >= 0)) || ((th1B >= 0) == (th2B >= 0));
    DLOG("suit; hullpt=", chull.at(i), "b=", b);
    return b;
  };

  for (double t : cand) {
    while (!suit(iL, t)) iL = prev(iL);
    while (!suit(iR, t)) iR = prev(iR);
    DLOG("suited: t=", t, "left=", chull.at(iL), "right=", chull.at(iR));
    Point dir(t, 1);
    Line lnL(dir, chull.at(iL));
    double xL = lnL.unsafe_intersect(xaxis).x;
    Line lnR(dir, chull.at(iR));
    double xR = lnR.unsafe_intersect(xaxis).x;
    assert(xR >= xL);
    ans = min(ans, xR - xL);
  }
  cout << ans << endl;

		 
  return 0;
}

