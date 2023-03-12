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

  /*
  using sta = pair<IPoint, ll>;
  
  vector<sta> bas = {{{1,1}, 2}, {{0,0}, 1}, {{0,1}, 2}, {{0,1}, 3}, {{0,0}, 3}, {{1,0}, 2}, {{1,0}, 1}};
  ll lim = 6;
  sta start{{0,0}, 0};
  map<sta, ll> mp;
  queue<sta> que;
  mp[start] = 0;
  que.push(start);
  while (not que.empty()) {
    auto y = que.front(); que.pop();
    auto [pt, ang] = y;
    for (const auto& [spt, sang] : bas) {
      IPoint new_pt = pt + spt.rotate(ang);
      ll new_ang = (ang + sang) % 4;
      sta x{new_pt, new_ang};
      if (abs(new_pt.x) < lim and abs(new_pt.y) < lim and mp.find(x) == mp.end()) {
        mp[x] = mp[y] + 1;
        que.push(x);
      }
    }
  }
  */

  auto f = [&](ll x, ll y, ll a) -> ll {
    if (a == 0) {
      if (x == 0 and y == 0) return 0;
      if (x - y == 0) return abs(x) * 2 + 1;
      return 2 * max(abs(x), abs(y));
    }else if (a == 2) {
      if (x == 0 and y == 0) return 2;
      if ((x == 1 and y == 0) or (x == 1 and -y == -1) or (x == 0 and -y == -1)) return 1; 
      if (x - y == 0) {
        if (x > 1) return x * 2;
        else return (-x + 1) * 2;
      }
      return max(abs(2 * x - 1), abs(2 * (-y) + 1));
    }else if (a == 1) {
      if ((x == 0 or x == 1) and y == 0) return 1;
      if (-(abs(y)) + 1 <= x and x <= abs(y)) return 2 * abs(y);
      return abs(2 * x - 1);
    }else if (a == 3) {
      if ((y == 0 or -y == -1) and x == 0) return 1;
      if (-(abs(x)) <= -y and -y <= abs(x) - 1) return 2 * abs(x);
      return abs(2 * (-y) + 1);
    }
    assert(0);
  };

  /*
  REP(a, 0, 4) {
    cout << a << endl;
    REP(j, -lim + 1, lim) {
      REP(i, -lim + 1, lim) {
        ll v = mp[{{i, j}, a}];
        cout << setw(3) << v << " ";
        if (f(i, j, a) != v) {
          cerr << endl << i << " " << j << " " << a << endl;
          cerr << f(i,j, a) << " " << v << endl;
          assert(f(i, j, a) == v);
        }
      }
      cout << "\n";
    }
    cout << "\n";
  }
  */

  auto solve = [&]() -> ll {
    IPoint px1, py1, pz1; cin >> px1 >> py1 >> pz1;
    IPoint px, py, pz;
    if (abs((px1 - py1).x) == 1 and abs((px1 - py1).y) == 1) { px = pz1; py = px1; pz = py1; }
    else if (abs((px1 - pz1).x) == 1 and abs((px1 - pz1).y) == 1) { px = py1; py = px1; pz = pz1; }
    else if (abs((pz1 - py1).x) == 1 and abs((pz1 - py1).y) == 1) { px = px1; py = py1; pz = pz1; }
    else assert(0);
    IPoint dir = (py - px) + (pz - px);
    IPoint bd{1, 1};
    ll arg = 0;
    for (; arg < 4; arg++) if (bd.rotate(arg) == dir) break;
    assert(bd.rotate(arg) == dir);
    return f(px.x, px.y, arg);
  };

  ll T; cin >> T;
  REP(_t, 0, T) cout << solve() << endl;

  return 0;
}

