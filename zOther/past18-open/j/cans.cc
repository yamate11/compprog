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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W; cin >> H >> W;
  vector<string> S(H);
  REP(i, 0, H) cin >> S[i];

  ll numst = (1LL << (H * W)) * (H * W);
  vector<IPoint> dirs{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  ll big = 1e18;
  vector<ll> dist(numst, big);
  queue<ll> que;
  
  auto flip = [&](ll x, IPoint p) -> ll {
    ll z = p.x * W + p.y;
    return (x ^ (1LL << z));
  };
  auto encSt = [&](ll x, IPoint p) -> ll {
    ll z = p.x * W + p.y;
    return z * (1LL << (H * W)) + x;
  };
  auto decSt = [&](ll e) -> pair<ll, IPoint> {
    ll m = (1LL << (H * W));
    ll z = e / m;
    ll x = e % m;
    IPoint p(z / W, z % W);
    return {x, p};
  };
  auto onboard = [&](IPoint p) -> bool {
    return 0 <= p.x and p.x < H and 0 <= p.y and p.y < W;
  };


  ll x0 = 0;
  REP(i, 0, H) REP(j, 0, W) if (S[i][j] == '#') x0 = flip(x0, IPoint(i, j));
  ll e0 = encSt(x0, IPoint(0, 0));
  dist[e0] = 0;
  que.push(e0);
  while (not que.empty()) {
    ll e = que.front(); que.pop();
    auto [x, p] = decSt(e);
    if (x == 0) {
      cout << dist[e] << endl;
      return 0;
    }
    for (auto d : dirs) {
      auto q = p + d;
      if (onboard(q)) {
        ll y = flip(x, q);
        ll e2 = encSt(y, q);
        if (dist[e2] >= big) {
          dist[e2] = dist[e] + 1;
          que.push(e2);
        }
      }
    }
  }
  assert(0);

  return 0;
}

