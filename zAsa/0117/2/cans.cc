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

// @@ !! LIM(ipoint)

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

  static bool lt_arg(const IPoint& p1, const IPoint& p2) {
    if ((p1.x == 0 and p1.y == 0) or (p2.x == 0 and p2.y == 0)) return false;
    if (p2.y == 0 and p2.x > 0) return false;
    if (p1.y == 0 and p1.x > 0) return true;
    if (p2.y == 0) return p1.y > 0;
    if (p1.y == 0) return p2.y < 0;
    if ((p1.y > 0) != (p2.y > 0)) return p1.y > 0;
    return p1.x * p2.y > p1.y * p2.x;
  };

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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  string S; cin >> S;

  set<IPoint> ss;
  IPoint cur(0, 0);
  ss.insert(cur);
  REP(i, 0, N) {
    if (S[i] == 'R')      cur += IPoint( 1,  0);
    else if (S[i] == 'L') cur += IPoint(-1,  0);
    else if (S[i] == 'U') cur += IPoint( 0,  1);
    else if (S[i] == 'D') cur += IPoint( 0, -1);
    else assert(0);
    if (ss.contains(cur)) {
      cout << "Yes\n";
      return 0;
    }
    ss.insert(cur);
  }
  cout << "No\n";

  return 0;
}

