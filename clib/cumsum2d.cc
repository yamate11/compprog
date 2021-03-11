#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  cumsum2d.cc -- Cumulative Sum in 2-D plane
    Implementation is a bit unusual.  
    Considering n * m plane, we keep sentinels on zeros.  
    The size of the underlying vector is (n+1) * (m+1).
    Values are on [1..n] * [1..m].  
    Intervals are half-open, but left-open and right-closed.
    Thus, tuple (x1, y1, x2, y2) designates [x1 + 1 .. x2] x [y1 + 1 .. y2].

  struct CumSum2D;

  csi_t : the type of values kept in the vector.  
          Usually this is long long.  If you need int, use:
          #define CUM_SUM_INT 1

  CumSum2D cs(n, m);
  cs.nX ... the size of the first dimension
  cs.nY ... the size of the second dimension
  cs.vec ... the underlying vector
                initialized as vector(nX+1, vector(nY+1, csi_t(0)))
             also accessable by overloaded [] operator.

  // Methods

  CumSum2D cumed = cs.cum();  // take cumulative sum
  cs.cum_inplace();           // take cumulative sum in place
  s = cumed.partial(x1, y1, x2, y2); // sum of (x1, x2] x (y1, y2]
  s = cumed.partial(ip1, ip2);       // same.  IPoint ip1, ip2;
  v = cumed.orig(int x, int y);   // the original value
  v = cumed.orig(ip);
  cs.put_rect(x1, y1, x2, y2, v); 
          // Changes four values in the underlying vector
          // so that the values in the rectangle in cs.cum() increase by v.
          // For so called Imos Method.
  cs.put_rect(ip1, ip2);

 */

// @@ !! LIM(ipoint)
// --> ipoint
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
  IPoint operator +(const IPoint& o) const { return IPoint(x, y) += o; }
  IPoint operator -(const IPoint& o) const { return IPoint(x, y) -= o; }
  IPoint operator *(ll k) const { return IPoint(x, y) *= k; }
  IPoint operator -() const { return IPoint(-x, -y); }

  bool operator <(const IPoint& o) const {
    // This seems awkward, but is needed for storing objects in maps.
    if (x != o.x) return x < o.x;
    else return y < o.y;
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
      return p.x * 37 + p.y * 41;
    }
  };
}

// ---- end ipoint.cc
// @@ !! LIM  -- end mark --

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN(ipoint)

// #define CUM_SUM_INT 1
#if CUM_SUM_INT
using csi_t = int;
#else
using csi_t = long long int;
#endif

struct CumSum2D {
  int nX;
  int nY;
  vector<vector<csi_t>> vec;

  CumSum2D(int nX_ = 0, int nY_ = 0)
    : nX(nX_), nY(nY_), vec(nX + 1, vector(nY + 1, csi_t(0))) {}

  CumSum2D(const CumSum2D& o) : nX(o.nX), nY(o.nY), vec(o.vec) {}

  CumSum2D(CumSum2D&& o) : nX(o.nX), nY(o.nY), vec(move(o.vec)) {}

  CumSum2D& operator =(const CumSum2D& o) {
    nX = o.nX;
    nY = o.nY;
    vec = o.vec;
    return *this;
  }

  CumSum2D& operator =(CumSum2D&& o) {
    nX = o.nX;
    nY = o.nY;
    vec = move(o.vec);
    return *this;
  }

  const vector<csi_t>& operator[](size_t i) const { return vec[i]; }
  vector<csi_t>& operator[](size_t i) { return vec[i]; }

  void cum_inplace() {
    for (int x = 1; x <= nX; x++) {
      for (int y = 1; y <= nY; y++) {
	vec[x][y] += vec[x-1][y] + vec[x][y-1] - vec[x-1][y-1];
      }
    }
  }

  CumSum2D cum() const {
    CumSum2D ret(*this);
    ret.cum_inplace();
    return ret;
  }

  // [x1 + 1 .. x2] * [y1 + 1 .. y2]
  csi_t partial(int x1, int y1, int x2, int y2) const {
    return vec[x2][y2] - vec[x1][y2] - vec[x2][y1] + vec[x1][y1];
  }
  csi_t partial(IPoint ip1, IPoint ip2) const {
    return partial(ip1.x, ip1.y, ip2.x, ip2.y);
  }

  csi_t orig(int x, int y) const { return partial(x-1, y-1, x, y); }
  csi_t orig(IPoint ip)    const { return orig(ip.x, ip.y); }

  void put_rect(int x1, int y1, int x2, int y2, csi_t v) {
    if (true)           vec[x1 + 1][y1 + 1] += v;
    if (x2 + 1 <= nX)   vec[x2 + 1][y1 + 1] -= v;
    if (y2 + 1 <= nY) {
      if (true)         vec[x1 + 1][y2 + 1] -= v;
      if (x2 + 1 <= nX) vec[x2 + 1][y2 + 1] += v;
    }
  }
  void put_rect(IPoint ip1, IPoint ip2, csi_t v) {
    put_rect(ip1.x, ip1.y, ip2.x, ip2.y, v);
  }

};

ostream& operator <<(ostream& os, const CumSum2D& s) {
  ll w = os.width();
  for (ll i = 1; i <= s.nX; i++) {
    for (ll j = 1; j <= s.nY; j++) {
      if (j > 1) os << " ";
      os << setw(w) << s.vec[i][j];
    }
    if (i < s.nX) os << "\n";
  }
  return os;
}

// @@ !! END ---- cumsum2d.cc

int main() {

  random_device rd;
  mt19937 rng(rd());
  uniform_int_distribution<int> dist1(-100, 100);

  {
    ll n = 5, m = 10;
    CumSum2D cs(n, m);
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= m; j++) cs[i][j] = dist1(rng);
    }
    CumSum2D cum_cs = cs.cum();
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= m; j++) {
	ll s = 0;
	for (ll ii = 1; ii <= i; ii++) {
	  for (ll jj = 1; jj <= j; jj++) s += cs[ii][jj];
	}
	assert(cum_cs[i][j] == s);
	assert(cum_cs.orig(i, j) == cs[i][j]);
	assert(cum_cs.orig(i, j) == cum_cs.orig(IPoint(i, j)));
      }
    }

    uniform_int_distribution<int> dist_n(1, n);
    uniform_int_distribution<int> dist_m(1, m);
    for (ll q = 0; q < 1000; q++) {
      ll x1, y1, x2, y2;
      while (true) {
	x1 = dist_n(rng) - 1;
	y1 = dist_m(rng) - 1;
	x2 = dist_n(rng);
	y2 = dist_m(rng);
	if (x1 < x2 && y1 < y2) break;
      }
      ll s = 0;
      for (ll i = x1 + 1; i <= x2; i++) {
	for (ll j = y1 + 1; j <= y2; j++) s += cs[i][j];
      }
      assert(cum_cs.partial(x1, y1, x2, y2) == s);
      assert(cum_cs.partial(IPoint(x1, y1), IPoint(x2, y2)) == s);
    }

    CumSum2D cs2(n, m);
    CumSum2D or2(n, m);
    for (ll q = 0; q < 1000; q++) {
      ll x1, y1, x2, y2;
      while (true) {
	x1 = dist_n(rng) - 1;
	y1 = dist_m(rng) - 1;
	x2 = dist_n(rng);
	y2 = dist_m(rng);
	if (x1 < x2 && y1 < y2) break;
      }
      ll v = dist1(rng);
      if (q % 2 == 0) {
	cs2.put_rect(x1, y1, x2, y2, v);
      }else {
	cs2.put_rect(IPoint(x1, y1), IPoint(x2, y2), v);
      }
      for (ll i = x1 + 1; i <= x2; i++) {
	for (ll j = y1 + 1; j <= y2; j++) or2[i][j] += v;
      }
    }
    cs2.cum_inplace();
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= m; j++) {
	// DLOG("ij", i, j, cs2[i][j], or2[i][j]);
	assert(cs2[i][j] == or2[i][j]);
      }
    }


  }

  cout << "ok\n";
  return 0;
}
