#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

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

ll md(IPoint& ip1, IPoint& ip2) { return abs(ip1.x - ip2.x) + abs(ip1.y - ip2.y); }

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector UR(2, vector<IPoint>());
  IPoint sft(1, 1);
  REP(i, N - 1) {
    IPoint ip1, ip2; cin >> ip1 >> ip2;
    UR[0][i] = ip1 - sft;
    UR[1][i] = ip2 - sft;
  }
  vector<IPoint> out = {IPoint(1, 0), IPoint(0, 1)};
  ll K = 64 - __builtin_clz(N);
  vector tbl(K, vector(2, vector(2, vector(N - 1, 0LL))));
  REP(i, N - 1) REP(p, 2) REP(q, 2) tbl[0][p][q][i] = 1 + md(UR[p][i] + out[p], UR[q][i + 1]);
  REP (k, K - 1) {
    ll d = 1LL << k;
    REP(i, N - 1 - d) REP(p, 2) REP(q, 2) {
      tbl[k + 1][p][q][i] = min(tbl[k][p][0][i] + tbl[k][0][q][i + d], tbl[k][p][1][i] + tbl[k][1][q][i + d]);
    }
  }
  ll M; cin >> M;
  REP(i, M) {
    IPoint s, e; cin >> s >> e;
    s -= sft;
    e -= sft;
    ll is = s.x + s.y;
    ll ie = e.x + e.y;
    if (is == ie) cout << md(s, e) << "\n";
    else {
      if (is > ie) { swap(s, e); swap(is, ie); }
      vector x(2, vector(2, ll));
      ll df = ie - is;
      ll k = 0;
      ll ii = is;
      while (df > 0) {
        if (df & 1) {
          vector y(2, vector(2, ll));
          REP(p, 2) REP(q, 2) y[p][q] = min(x[p][0] + tbl[k][0][q][ii], x[p][1] + tbl[k][1][q][ii]);
          x = move(y);
          ii += (1 << k);
          df >>= 1;
          k++;
        }
      }
      ll ans = (ll)1e18;
      REP(p, 2) REP(q, 2) ans = min(ans, md(s, UR[p][is]) + md(e, UR[q][ie - 1] + out[q]) + 1 + x[p][q]);
      cout << ans << "\n";
    }
  }
  return 0;
}

