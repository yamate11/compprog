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

  ll N, X, Y; cin >> N >> X >> Y;
  // @InpVec(N, A) [mn7Mpqko]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [mn7Mpqko]

  using sta = pair<bool, ll>;
  auto func = [&](ll goal, ll start) -> sta {
    ll m1, m2;
    if (N % 2 == 0 or start == 1) {
      m1 = (N / 2) / 2;
      m2 = (N / 2) - m1;
    }else {
      ll tt = N - (N / 2);
      m1 = tt / 2;
      m2 = tt - m1;
    }
    map<ll, ll> mp1;
    REP(x, 0, 1LL << m1) {
      ll v = 0;
      REP(i, 0, m1) {
        if (x >> i & 1) v -= A[start + 2 * i];
        else            v += A[start + 2 * i];
      }
      mp1[v] = x;
    }
    REP(x, 0, 1LL << m2) {
      ll v = 0;
      REP(i, 0, m2) {
        if (x >> i & 1) v -= A[start + 2 * (m1 + i)];
        else            v += A[start + 2 * (m1 + i)];
      }
      auto it = mp1.find(goal - v);
      if (it != mp1.end()) {
        return sta(true, (it->second) | (x << m1));
      }
    }
    return sta(false, 0LL);
  };

  auto [rca, a] = func(Y, 0);
  auto [rcb, b] = func(X, 1);
  string ans;
  IPoint dir(1, 0);
  if (rca and rcb) {
    cout << "Yes\n";
    REP(i, 0, N) {
      ll j = i / 2;
      if (i % 2 == 0) {
        IPoint newdir;
        if (a >> j & 1) newdir = IPoint(0, -1);
        else            newdir = IPoint(0, 1);
        if (dir.rotate() == newdir) ans.push_back('L');
        else ans.push_back('R');
        dir = newdir;
      }else {
        IPoint newdir;
        if (b >> j & 1) newdir = IPoint(-1, 0);
        else            newdir = IPoint(1, 0);
        if (dir.rotate() == newdir) ans.push_back('L');
        else ans.push_back('R');
        dir = newdir;
      }
    }
    cout << ans << endl;
  }else {
    cout << "No\n";
  }

  return 0;
}

