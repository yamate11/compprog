#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(ipoint f:updMaxMin)

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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<IPoint> P;
  REP(i, N) {
    ll x, y; cin >> x >> y;
    P.emplace_back(x, y);
  }
  auto nxt = [&](ll j) -> ll { return j == N - 1 ? 0 : j + 1; };
  auto prv = [&](ll j) -> ll { return j == 0 ? N - 1 : j - 1; };

  auto area8 = [&](ll i, ll j, ll k) -> ll {
    IPoint u = P[j] - P[i], v = P[k] - P[i];
    return 4 * abs(u.x * v.y - u.y * v.x);
  };
  ll A = 0;
  REP2(i, 1, N - 1) A += area8(0, i, nxt(i));
  A /= 4;
  ll j = 2;
  ll B = area8(0, 1, 2);
  ll ans = abs(A - B);
  while (B < A) {
    B += area8(0, j, nxt(j));
    updMin(ans, abs(A - B));
    j = nxt(j);
  }
  REP2(i, 1, N) {
    B -= area8(j, prv(i), i);
    updMin(ans, abs(A - B));
    if (B < A) {
      while (B < A) {
        B += area8(i, j, nxt(j));
        updMin(ans, abs(A - B));
        j = nxt(j);
      }
    }else {
      while (B > A) {
        B -= area8(i, j, prv(j));
        updMin(ans, abs(A - B));
        j = prv(j);
      }
    }
  }
  cout << ans << endl;
  return 0;
}

