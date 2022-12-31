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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    IPoint P1, P2;
    cin >> P1 >> P2;
    IPoint P = P1 - P2;

    if (P.x == 0 and P.y == 0) return 0;
    if (P.x + P.y == 0 or P.x == P.y or abs(P.x) + abs(P.y) <= 3) return 1;
    if ((P.x + P.y) % 2 == 0) return 2;
    if (abs(P.x) + abs(P.y) <= 6) return 2;
    REP(i, P.x - 3, P.x + 4) REP(j, P.y - 3, P.y + 4) {
      if (abs(P.x - i) + abs(P.y - j) <= 3) {
        if (i == j or i + j == 0) return 2;
      }
    }
    return 3;
    
  };

  cout << solve() << endl;

  return 0;
}

