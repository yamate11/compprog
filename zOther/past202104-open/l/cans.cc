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

// @@ !! LIM(ipoint geometry UnionFind)

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

  bool parallel(const IPoint o) const { return x * o.y == y * o.x; }

  // For "argument sort".  The origin is treated as the maximum.
  static bool lt_arg(const IPoint& p1, const IPoint& p2) {
    bool b1 = p1.y > 0 or (p1.y == 0 and p1.x > 0);
    bool b2 = p2.y > 0 or (p2.y == 0 and p2.x > 0);
    if (b1 != b2) return b1;
    else return p1.x * p2.y > p1.y * p2.x;
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
      static const uint64_t frand = chrono::steady_clock::now().time_since_epoch().count();
      static const uint64_t a = (frand ^ 0x9e3779b97f4a7c15) | 1;
      static const uint64_t b = (frand ^ 0xbf58476d1ce4e5b9) | 1;
      return a * (uint64_t)p.x + b * (uint64_t)p.y;
    }
  };
}


// ---- end ipoint.cc

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

// ---- inserted library file UnionFind.cc

struct UFDummyAlg {
  static UFDummyAlg zero;
  UFDummyAlg(int x = 0) {}
  UFDummyAlg operator -() const { return *this; }
  UFDummyAlg operator +(const UFDummyAlg& o) const { return *this; }
};
UFDummyAlg UFDummyAlg::zero;

template<typename T = UFDummyAlg, typename oplus_t = decltype(plus<T>()), typename onegate_t = decltype(negate<T>())>
struct UnionFind {

  struct GroupInfo {
    UnionFind& uf;
    vector<vector<int>> _groups;
    GroupInfo(UnionFind& uf_) : uf(uf_), _groups(uf.size) {
      for (int j = 0; j < uf.size; j++) {
        if (uf.leader(j) == j) {
          _groups[j].resize(uf.group_size(j));
          _groups[j].resize(0);
        }
      }
      for (int j = 0; j < uf.size; j++) _groups[uf.leader(j)].push_back(j);
    }
    const vector<int>& group(int i) { return _groups[uf.leader(i)]; }
  };

  int size;
  T zero;
  oplus_t oplus;
  onegate_t onegate;
  vector<int> _leader;
  vector<optional<T>> _pot;
  vector<int> _gsize;
  int _num_groups;
  static constexpr bool _with_pot = not is_same_v<T, UFDummyAlg>;
  
  UnionFind() : size(0), zero((T)0), oplus(plus<T>()), onegate(negate<T>()),
                _leader(0), _pot(0), _gsize(0), _num_groups(0) {}

  UnionFind(int size_, T zero_ = (T)0, oplus_t oplus_ = plus<T>(), onegate_t onegate_ = negate<T>())
    : size(size_), zero(zero_), oplus(oplus_), onegate(onegate_),
      _leader(size, -1), _pot(0), _gsize(size, 1), _num_groups(size) {
    if constexpr (_with_pot) _pot.resize(size, zero);
  }

  void set_size(int size_) {
    size = size_;
    _leader.resize(size, -1);
    if constexpr (_with_pot) _pot.resize(size, zero);
    _gsize.resize(size, 1);
  }

  int merge(int i, int j, T p) {
    int li = leader(i);
    int lj = leader(j);
    optional<T> ld_p;
    if constexpr (_with_pot) {
      if (_pot[i] and _pot[j]) ld_p = oplus(p, oplus(*_pot[j], onegate(*_pot[i])));
      else                     ld_p = nullopt;
    }
    if (li == lj) {
      if constexpr (_with_pot) { if (not (ld_p and *ld_p == zero)) _pot[li] = nullopt; }
      return lj;
    }
    _num_groups--;
    if (_gsize[lj] < _gsize[li]) {
      swap(li, lj);
      if constexpr (_with_pot) if (ld_p) ld_p = onegate(*ld_p);
    }
    // lj is the newleader
    _gsize[lj] += _gsize[li];
    _leader[li] = lj;
    if constexpr (_with_pot) {
      if (_pot[lj] and _pot[li]) _pot[li] = ld_p;
      else _pot[lj] = nullopt;
    }
    return lj;
  }

  template<typename U = T>
  enable_if_t<is_same_v<U, UFDummyAlg>, int> merge(int i, int j) { return merge(i, j, zero); }

  void _leaderpot(int i) {
    int oj = _leader[i];
    if (oj < 0) return;
    int nj = _leader[i] = leader(oj);
    if constexpr (_with_pot) {
      if (_pot[nj]) _pot[i] = oplus(*_pot[i], *_pot[oj]);
      else _pot[i] = nullopt;
    }
  }
  int leader(int i) {
    _leaderpot(i);
    return _leader[i] < 0 ? i : _leader[i];
  }
  optional<T> pot(int i)  { _leaderpot(i); return _pot[i]; }

  int group_size(int i) { return _gsize[leader(i)]; }

  int num_groups() { return _num_groups; }

  GroupInfo group_info() { return GroupInfo(*this); }

};

template<typename T = UFDummyAlg>
auto makeUnionFind(int size, T zero, auto oplus, auto onegate) {
  return UnionFind<T, decltype(oplus), decltype(onegate)>(size, zero, oplus, onegate);
}

// ---- end UnionFind.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<Point> P(N);
  vector<Point> C(M);
  vector<Real> R(M);
  REP(i, 0, N) cin >> P[i];
  REP(i, 0, M) {
    cin >> C[i];
    cin >> R[i];
  }
  Real ans = 1e18;
  REP(x, 0, 1LL << M) {
    using sta = tuple<Real, ll, ll>;
    vector<sta> vec;
    REP(i, 0, N) REP(j, i + 1, N) {
      vec.emplace_back((P[i] - P[j]).len(), i, j);
    }
    REP(i, 0, M) REP(j, i + 1, M) {
      if ((x >> i & 1) and (x >> j & 1)) {
        Real d = (C[i] - C[j]).len();
        Real r1 = R[i], r2 = R[j];
        if (r1 < r2) swap(r1, r2);
        if (r1 + r2 < d) vec.emplace_back(d - (r1 + r2), N + i, N + j);
        else if (d + r2 < r1) vec.emplace_back(r1 - (d + r2), N + i, N + j);
        else vec.emplace_back(0, N + i, N + j);
      }
    }
    REP(i, 0, N) REP(j, 0, M) {
      if (x >> j & 1) {
        vec.emplace_back(abs((P[i] - C[j]).len() - R[j]), i, N + j);
      }
    }
    sort(ALL(vec));
    UnionFind uf(N + M);
    Real cur = 0.0;
    for (auto [d, i, j] : vec) {
      if (uf.leader(i) != uf.leader(j)) {
        cur += d;
        uf.merge(i, j);
      }
    }
    ans = min(ans, cur);
  }
  cout << ans << endl;
  return 0;
}

