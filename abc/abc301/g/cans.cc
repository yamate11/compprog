#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(geometry UnionFind input)

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

// ---- end geometry.cc

// ---- inserted library file UnionFind.cc

template<typename T = ll, typename oplus_t = decltype(plus<T>()), typename onegate_t = decltype(negate<T>())>
struct UnionFind {
  int size;
  T zero;
  oplus_t oplus;
  onegate_t onegate;
  vector<pair<int, optional<T>>> _leader;
  vector<int> _gsize;
  bool built_groups;
  vector<vector<int>> _groups;
  
  UnionFind(int size_, T zero_ = (T)0, oplus_t oplus_ = plus<T>(), onegate_t onegate_ = negate<T>())
    : size(size_), zero(zero_), oplus(oplus_), onegate(onegate_), _gsize(size, 1), built_groups(false) {
    for (int i = 0; i < size; i++) _leader.emplace_back(i, zero);
  }

  int merge(int i, int j, optional<T> p = nullopt) {
    built_groups = false;
    auto [li, pi] = leaderpot(i);
    auto [lj, pj] = leaderpot(j);
    if (li == lj) {
      if (not p.has_value()) _leader[li].second = nullopt;
      else if (pi.has_value() and oplus(*p, *pj) != *pi) _leader[li].second = nullopt;
      return li;
    }
    int new_leader, obs_leader; bool chg_sign;
    if (_gsize[li] < _gsize[lj]) {
      new_leader = lj;
      obs_leader = li;
      chg_sign = false;
    }else {
      new_leader = li;
      obs_leader = lj;
      chg_sign = true;
    }
    _gsize[new_leader] += _gsize[obs_leader];
    _leader[obs_leader].first = new_leader;
    if (p.has_value() and pi.has_value() and pj.has_value()) {
      T new_pot = oplus(*p, oplus(*pj, onegate(*pi)));
      if (chg_sign) new_pot = onegate(new_pot);
      _leader[obs_leader].second = new_pot;
    }else {
      _leader[new_leader].second = nullopt;  // Note this is for new_leader
    }
    return new_leader;
  }

  pair<int, optional<T>> leaderpot(int i) {
    int cur = i;
    vector<pair<int, optional<T>>> seen;
    optional<T> pp;
    {
      auto [nxt, p] = _leader[cur];
      while (cur != nxt) {
        seen.emplace_back(cur, p);
        cur = nxt;
        tie(nxt, p) = _leader[cur];
      }
      pp = p;
    }
    while (not seen.empty()) {
      auto [j, p] = seen.back(); seen.pop_back();
      if (pp.has_value()) pp = oplus(pp.value(), p.value());
      _leader[j] = {cur, pp};
    }
    return {cur, pp};
  }

  int leader(int i) { return leaderpot(i).first; }
  optional<T> pot(int i) { return leaderpot(i).second; }

  int groupSize(int i) { return _gsize[leader(i)]; }

  const vector<int>& group(int i) {
    if (not built_groups) {
      _groups.resize(size);
      for (int j = 0; j < size; j++) _groups[j].resize(0);
      for (int j = 0; j < size; j++) _groups[leader(j)].push_back(j);
      built_groups = true;
    }
    return _groups[leader(i)];
  }

};

template<typename T = ll>
auto makeUnionFind(int size, T zero, auto oplus, auto onegate) {
  return UnionFind<T, decltype(oplus), decltype(onegate)>(size, zero, oplus, onegate);
}

// ---- end UnionFind.cc

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

/*
struct Rat {
  ll num;
  ll den;
  
  Rat(ll num_ = 0, ll den_ = 1) : num(num_), den(den_) { normalize(); }

  void normalize() {
    if (den == 0) throw runtime_error("Rat: division by zero");
    if (den < 0) { num *= -1; den *= -1; }
    ll g = gcd(abs(num), den);
    num /= g;
    den /= g;
  }

  Rat operator +(const Rat& o) const {
    ll g = gcd(den, o.den);
    ll x_t = den / g;
    ll x_o = o.den / g;
    ll ret_d = den * x_o;
    ll ret_n = num * x_o + o.num * x_t;
    return Rat(ret_n, ret_d);
  }
  Rat operator -() const { return Rat(-num, den); }
  Rat operator -(const Rat& o) const { return *this + (-o); }
  Rat operator *(const Rat& o) const {
    ll x = gcd(num, o.den);
    ll y = gcd(den, o.num);
    return Rat(num / x * o.num / y, den / y * o.den / x);
  }
  Rat inverse() const { return Rat(den, num); }
  Rat operator /(const Rat& o) const { return *this * o.inverse(); }

};
*/

// @DefStruct(P3, ((x, Real), (y, Real), (z, Real))) [abwlz0Zk]
struct P3_t {
  Real x;
  Real y;
  Real z;
  P3_t() {}
  P3_t(Real x_, Real y_, Real z_) : x(x_), y(y_), z(z_) {}
  friend istream& operator>>(istream& istr, P3_t& t) {
    istr >> t.x >> t.y >> t.z;
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const P3_t& t) {
    ostr << "(" << t.x << ", " << t.y << ", " << t.z << ")";
    return ostr;
  }
};
// @End [abwlz0Zk]

P3_t operator +(const P3_t& a, const P3_t& b) { return P3_t(a.x + b.x, a.y + b.y, a.z + b.z); };
P3_t operator -(const P3_t& a, const P3_t& b) { return P3_t(a.x - b.x, a.y - b.y, a.z - b.z); };
P3_t operator *(Real r, const P3_t& b) { return P3_t(r * b.x, r * b.y, r * b.z); };
bool sim3(const P3_t& a, const P3_t& b) { return may_eq(a.x, b.x) and may_eq(a.y, b.y) and may_eq(a.z, b.z); };

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, P3, type=P3_t) [Qf8MERE0]
  auto P3 = vector(N, P3_t());
  for (int i = 0; i < N; i++) { P3_t v; cin >> v; P3[i] = v; }
  // @End [Qf8MERE0]

  /*
  vector<Point> PP;
  REP(i, 0, N) PP.emplace_back(X[i], Y[i]);
  */

  auto enc = [&](ll i, ll j) -> ll { return i * N + j; };
  auto dec = [&](ll e) -> pair<ll, ll> { return {e / N, e % N}; };
  UnionFind uf1(N*N);
  REP(i, 0, N) REP(j, i + 1, N) REP(k, j + 1, N) {
    auto d1 = P3[j] - P3[i];
    auto d2 = P3[k] - P3[i];
    if (sim3(d1, d2)) {
      uf1.merge(enc(i, j), enc(i, k));
      uf1.merge(enc(i, j), enc(j, k));
    }
  }
  ll dup = 0;
  using stc = tuple<P3_t, P3_t, vector<bool>>;
  vector<stc> lines;
  REP(i, 0, N) REP(j, i + 1, N) {
    ll e = enc(i, j);
    if (uf1.leader(e) == e) {
      vector<bool> ss(N);
      ss[i] = ss[j] = true;
      for (ll f : uf1.group(e)) {
        auto [k, l] = dec(f);
        ss[k] = ss[l] = true;
      }
      if (not may_eq(P3[j].x, P3[i].x)) dup = max(dup, SIZE(ss));
      lines.emplace_back(P3[j] - P3[i], P3[i], move(ss));
    }
  }

  auto chk = [&](const P3_t& d1, const P3_t& p1, const P3_t& d2, const P3_t& p2) -> optional<P3_t> {
    auto sub = [&](Point e1, Point q1, Point e2, Point q2) -> tuple<int, Point> {
      Point origin(0, 0);
      if (e1.sim(origin)) { swap(e1, e2); swap(q1, q2); }
      Line l1(e1, q1);
      if (e2.sim(origin)) {
        if (l1.ptOn(q2)) { return {Line::IST_ONE, q2}; }
        else { return {Line::IST_NONE, origin}; }
      }
      Line l2(e2, q2);
      auto [code, r1, r2] = l1.intersect_coeff(l2);
      if (code == Line::IST_ONE) return {code, q1 + r1 * e1};
      else return {code, origin};
    };

    auto [rca, pa] = sub(Point(d1.x, d1.y), Point(p1.x, p1.y), Point(d2.x, d2.y), Point(p2.x, p2.y));
    auto [rcb, pb] = sub(Point(d1.x, d1.z), Point(p1.x, p1.z), Point(d2.x, d2.z), Point(p2.x, p2.z));
    if (rca == Line::IST_NONE or rcb == Line::IST_NONE) return nullopt;
    else if (rca == IST_ONE) 
      P3_t u = p1 + r1 * d1;
      P3_t v = p2 + r2 * d2;
      return sim3(u, v) ? u : nullopt;
    }else if (rca == IST_ALL) {
      auto [rcb, s1, s2] = sub(Point(d1.x, d1.z), Point(p1.x, p1.z), Point(d2.x, d2.z), Point(p2.x, p2.z));
      if (rcb == IST_NONE) return nullopt;
      assert (rcb == IST_ONE);
      return p1 + s1 * d1;
    }else assert(0);
  };


  using sta = pair<P3_t, vector<bool>>;
  vector<sta> iss; // intersection points
  REP(i, 0, SIZE(lines)) REP(j, i + 1, SIZE(lines)) {
    const auto& [d1, p1, vec1] = lines[i];
    const auto& [d2, p2, vec2] = lines[j];
    auto op0 = chk(d1, p1, d2, p2);
    if (op0 and not may_ge(0, (*op0).x)) {
      auto v = vec1;
      REP(k, 0, N) if (vec2[k]) v[k] = true;
      iss.emplace_back(*op0, v);
    }
  }
  auto comp1 = [&](const P3_t& p1, const P3_t& p2) -> bool {
    if (not may_eq(p1.x, p2.x)) return p1.x < p2.x;
    if (not may_eq(p1.y, p2.y)) return p1.y < p2.y;
    if (not may_eq(p1.z, p2.z)) return p1.z < p2.z;
    return false;
  };
  auto comp = [&](const sta& p1, const sta& p2) -> bool { return comp1(p1.first, p2.first); };
  sort(ALL(iss), comp);
  for (ll i = 0; i < SIZE(iss); ) {
    vector<bool> on(N);
    while (true) {
      const auto& [_p, vec] = iss[i];
      REP(j, 0, N) if (vec[j]) on[j] = true;
      i++;
      if (i == SIZE(iss) or comp(iss[i - 1], iss[i])) break;
    }
    ll d = 0;
    REP(j, 0, N) if (on[j]) d++;
    dup = max(dup, d);
  }
  cout << N - dup + 1 << endl;
    



  return 0;
}

