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
  // @InpVec(N, XY, type=IPoint) [riuIU7WV]
  auto XY = vector(N, IPoint());
  for (int i = 0; i < N; i++) { IPoint v; cin >> v; XY[i] = v; }
  // @End [riuIU7WV]
  ll Q; cin >> Q;
  // @InpVec(Q, AB, type=IPoint) [gIv88bZs]
  auto AB = vector(Q, IPoint());
  for (int i = 0; i < Q; i++) { IPoint v; cin >> v; AB[i] = v; }
  // @End [gIv88bZs]

  ll imin = -1, imax = -1, vmin = LLONG_MAX, vmax = LLONG_MIN;
  REP(i, 0, N) {
    if (updMin(vmin, XY[i].x)) imin = i;
    if (updMax(vmax, XY[i].x)) imax = i;
  }
  bool min2 = false, max2 = false;
  if (XY[(imin + 1) % N].x == vmin) min2 = true;
  if (XY[(imax + 1) % N].x == vmax) max2 = true;


  enum en_t { PolU, PolD, Tes };
  using ev_t = tuple<ll, ll, ll>;
  vector<ev_t> event;
  {
    ll i = min2 ? (imin + 1) % N : imin;
    while (true) {
      event.emplace_back(XY[i].x, PolD, i);
      if (i == imax) break;
      i++;
      if (i == N) i = 0;
    }
    i = max2 ? (imax + 1) % N : imax;
    while (true) {
      event.emplace_back(XY[i].x, PolU, i);
      if (i == imin) break;
      i++;
      if (i == N) i = 0;
    }
  }
  REP(i, 0, Q) event.emplace_back(AB[i].x, Tes, i);
  sort(ALL(event));

  vector<string> ans(Q);
  ll phase = 0;
  IPoint up0, up1, down0, down1;
  for (auto [xx, en, i] : event) {
    if (en == PolU) {
      up0 = XY[i]; up1 = XY[(i + N - 1) % N];
    }else if (en == PolD) {
      down0 = XY[i]; down1 = XY[(i + 1) % N];
      if (XY[i].x == vmin) phase = 1;
      if (XY[i].x == vmax) phase = 2;
    }else if (en == Tes) {
      if (phase == 0 or phase == 3) ans[i] = "OUT";
      else if (phase == 2) {
        if (AB[i].x == vmax) {
          if (down0.y <= AB[i].y and AB[i].y <= up0.y) ans[i] = "ON";
          else ans[i] = "OUT";
        }else {
          ans[i] = "OUT";
          phase = 3;
        }
      }else {
        ll t_up = (up1.x - up0.x) * (AB[i].y - up0.y) - (up1.y - up0.y) * (AB[i].x - up0.x);
        ll t_down = (down1.x - down0.x) * (AB[i].y - down0.y) - (down1.y - down0.y) * (AB[i].x - down0.x);
        if (t_up == 0 or t_down == 0) ans[i] = "ON";
        else if (t_up > 0 or t_down < 0) ans[i] = "OUT";
        else if (AB[i].x == vmin or AB[i].x == vmax) ans[i] = "ON";
        else ans[i] = "IN";
      }
    }else assert(0);
  }
  REPOUT(i, 0, Q, ans[i], "\n");

  return 0;
}

