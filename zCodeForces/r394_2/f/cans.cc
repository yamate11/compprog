#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(ipoint debug)
// --> ipoint f:<< debug
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

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig) {
  queue<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig) {
  deque<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop_front();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
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

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st) {
  stack<T> tmp(st);
  os << '[';
  bool first = true;
  while (!tmp.empty()) {
    T& t = tmp.top();
    if (first) first = false;
    else os << ", ";
    os << t;
    tmp.pop();
  }
  os << ']';
  return os;
}

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t) {
  if (t.has_value()) os << "v(" << t.value() << ")";
  else               os << "nullopt";
  return os;
}
#endif

ostream& operator<< (ostream& os, int8_t x) {
  os << (int32_t)x;
  return os;
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

#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(__VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif

// ---- end debug.cc
// @@ !! LIM  -- end mark --

// #define SUMPLANE_INT 1

// #define SUMPLANE_INT 1
#if SUMPLANE_ARRAY_INT
using spi_t = int;
#else
using spi_t = long long int;
#endif

// always with sentinel on both sides
struct SumPlane {
  int nX;
  int nY;
  vector<vector<spi_t>> vec;
  SumPlane(int nX_ = 0, int nY_ = 0)
    : nX(nX_), nY(nY_), vec(nX + 1, vector(nY + 1, spi_t(0))) {}

  /*
  SumPlane accum() const {
    SumPlane ret(nX, nY);
    for (int x = 1; x <= nX; x++) {
      for (int y = 1; y <= nY; y++) {
	ret.vec[x][y] =
	  vec[x][y] + ret.vec[x-1][y] + ret.vec[x][y-1] - ret.vec[x-1][y-1];
      }
    }
    return ret;
  }
  */

  void accum_inplace() {
    for (int x = 1; x <= nX; x++) {
      for (int y = 1; y <= nY; y++) {
	vec[x][y] += vec[x-1][y] + vec[x][y-1] - vec[x-1][y-1];
      }
    }
  }

  SumPlane accum() const {
    SumPlane ret;
    ret.nX = nX;
    ret.nY = nY;
    ret.vec = vec;
    ret.accum_inplace();
    return ret;
  }

  // [x1 + 1 .. x2] * [y1 + 1 .. y2]
  spi_t partial(int x1, int y1, int x2, int y2) const {
    return vec[x2][y2] - vec[x1][y2] - vec[x2][y1] + vec[x1][y1];
  }
  spi_t partial(IPoint ip1, IPoint ip2) const {
    return partial(ip1.x, ip1.y, ip2.x, ip2.y);
  }

  spi_t orig(int x, int y) const { return partial(x-1, y-1, x, y); }
  spi_t orig(IPoint ip)    const { return orig(ip.x, ip.y); }

  void put_rect(int x1, int y1, int x2, int y2, spi_t v) {
    if (true)           vec[x1 + 1][y1 + 1] += v;
    if (x2 + 1 <= nX)   vec[x2 + 1][y1 + 1] -= v;
    if (y2 + 1 <= nY) {
      if (true)         vec[x1 + 1][y2 + 1] -= v;
      if (x2 + 1 <= nX) vec[x2 + 1][y2 + 1] += v;
    }
  }
  void put_rect(IPoint ip1, IPoint ip2, spi_t v) {
    put_rect(ip1.x, ip1.y, ip2.x, ip2.y, v);
  }

};

ostream& operator <<(ostream& os, const SumPlane& s) {
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


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if DEBUG
  const int szAlph = 9;
#else
  const int szAlph = 26;
#endif

  ll n, m, k; cin >> n >> m >> k;
  vector T(n + 1, vector(m + 1, (char)0));
  for (ll i = 1; i <= n; i++) {
    for (ll j = 1; j <= m; j++) {
      char c; cin >> c;
      T[i][j] = c - 'a';
    }
  }
  vector<IPoint> AB(k), CD(k);
  vector<char> E(k);
  for (ll i = 0; i < k; i++) {
    ll a, b, c, d;
    char e;
    cin >> a >> b >> c >> d >> e; 
    AB[i] = IPoint(a - 1, b - 1);
    CD[i] = IPoint(c, d);
    E[i] = e - 'a';
  }

  SumPlane acc_da;
  vector<SumPlane> both(szAlph);
  {
    vector chgd(szAlph, SumPlane(n, m));
    for (ll i = 0; i < k; i++) {
      chgd[E[i]].put_rect(AB[i], CD[i], 1);
    }
    // vector<SumPlane> chgd(szAlph);
    for (ll e = 0; e < szAlph; e++) {
      chgd[e].accum_inplace();
    }
    SumPlane dist_a(n, m);
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= m; j++) {
	ll sum = 0;
	for (ll e = 0; e < szAlph; e++) {
	  sum += abs(e - T[i][j]) * chgd[e].vec[i][j];
	}
	dist_a.vec[i][j] = sum;
      }
    }

    DLOG("dist_a");
    cerr << setw(2);
    DLOG(dist_a);

    acc_da = dist_a.accum();

    for (ll e = 0; e < szAlph; e++) both[e] = chgd[e];
    for (ll i = 1; i <= n; i++) {
      for (ll j = 1; j <= m; j++) {
	ll s = 0;
	for (ll e = 0; e < szAlph; e++) {
	  s += chgd[e].vec[i][j];
	}
	both[T[i][j]].vec[i][j] += k - s;
      }
    }
    /*
    chgd.resize(0);
    chgd.shrink_to_fit();
    */
    
    for (ll e = 0; e < szAlph; e++) {
      both[e].accum_inplace();
    }
  }

  ll ans = 1e18;
  for (ll p = 0; p < k; p++) {
    DLOG("p=", p);
    ll cnt = 0;
    for (ll e = 0; e < szAlph; e++) {
      ll cd = abs(E[p] - e);
      ll x = both[e].partial(AB[p], CD[p]);
      ll u = cd * x;
      DLOG("e=", e, "cd=", cd, "x=", x, "u=", u);
      cnt += cd * x;
    }
    ll u1 = acc_da.partial(0, 0, AB[p].x, CD[p].y);
    ll u2 = acc_da.partial(AB[p].x, 0, n, AB[p].y);
    ll u3 = acc_da.partial(CD[p].x, AB[p].y, n, m);
    DLOG("for u4", 0, CD[p].y, CD[p].x, m);
    ll u4 = acc_da.partial(0, CD[p].y, CD[p].x, m);
    cnt += u1 + u2 + u3 + u4;
    DLOG("cnt=", cnt, "u1=", u1, "u2=", u2, "u3=", u3, "u4=", u4);
    ans = min(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}

