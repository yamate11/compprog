#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug geometry)
// --> f:<< debug rerror geometry
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
Real g_err = 1e-12;

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
    return intersect(Line(dir.rotate(M_PI/2), p));
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
    Line l(v.rotate(M_PI/2), c + t * v);
    return intersect(l);
  }

};

ostream& operator <<(ostream& os, const Circle& circ) {
  return os << "[c " << circ.c << ", " << circ.r << "]";
}

// 外心
Point circumcenter(const Point& z1, const Point& z2, const Point& z3) {
  Line l12((z2 - z1).rotate(M_PI/2), (z1 + z2) / 2);
  Line l23((z3 - z2).rotate(M_PI/2), (z2 + z3) / 2);
  return l12.intersect(l23);
}


// ---- end geometry.cc
// @@ !! LIM  -- end mark --


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  if (K == 1) {
    cout << 0 << endl;
    return 0;
  }
  vector<Point> P(N);
  vector<double> C(N);
  for (ll i = 0; i < N; i++) {
    double x, y;
    cin >> x >> y >> C.at(i);
    P.at(i) = Point(x, y);
  }
  vector<pair<Point, ll>> cand;
  for (ll i = 0; i < N; i++) {
    for (ll j = i+1; j < N; j++) {
      Point pt =
	(C.at(i) * P.at(i) + C.at(j) * P.at(j)) / (C.at(i) + C.at(j));
      cand.emplace_back(pt, i);
    }
  }
  auto apol = [&](ll i, ll j) -> tuple<bool, Line, Circle> {
    Line lij;
    Circle cij;
    bool b = C.at(i) == C.at(j);
    if (b) {
      Point mid = (P.at(i) + P.at(j)) / 2;
      Point dir = (P.at(j) - P.at(i)).rotateQ();
      lij = Line(dir, mid);
    }else {
      ll ii = i;
      ll jj = j;
      if (C.at(i) > C.at(j)) swap(ii, jj);
      Point p1 =
      (C.at(ii) * P.at(ii) + C.at(jj) * P.at(jj)) / (C.at(ii) + C.at(jj));
      Point p2 = 
      (C.at(jj) * P.at(jj) - C.at(ii) * P.at(ii)) / (C.at(jj) - C.at(ii));
      cij = Circle((p1 + p2) / 2, (p1 - p2).len() / 2);
    }
    return make_tuple(b, lij, cij);
  };

  for (ll i = 0; i < N; i++) {
    for (ll j = i+1; j < N; j++) {
      bool bij; Line lij; Circle cij; tie(bij, lij, cij) = apol(i, j);
      Point pt;
      for (ll k = j+1; k < N; k++) {
	bool bjk; Line ljk; Circle cjk; tie(bjk, ljk, cjk) = apol(j, k);
	bool b; Point p1, p2;
	if (bij) {
	  if (bjk) {
	    pt = lij.intersect(ljk);
	    cand.emplace_back(pt, i);
	  }else {
	    tie(b, p1, p2) = cjk.intersect(lij);
	    if (!b) continue;
	    cand.emplace_back(p1, i);
	    cand.emplace_back(p2, i);
	  }
	}else {
	  if (bjk) {
	    tie(b, p1, p2) = cij.intersect(ljk);
	    if (!b) continue;
	    cand.emplace_back(p1, i);
	    cand.emplace_back(p2, i);
	  }else {
	    tie(b, p1, p2) = cij.intersect(cjk);
	    if (!b) continue;
	    cand.emplace_back(p1, i);
	    cand.emplace_back(p2, i);
	  }
	}
      }
    }
  }
  double ans = DBL_MAX;
  for (auto q : cand) {
    Point p = q.first;
    ll i0 = q.second;
    double tm = (P.at(i0) - p).len() * C.at(i0);
    ll cnt = 0;
    for (ll i = 0; i < N; i++) {
      if (r_le((P.at(i) - p).len() * C.at(i), tm)) cnt++;
    }
    if (cnt >= K) ans = min(ans, tm);
  }
  cout << ans << endl;
  return 0;
}

