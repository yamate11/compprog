#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(debug ipoint)
// --> f:<< debug ipoint
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

using Ku = pair<IPoint, ll>;

Ku buildKu(IPoint a, IPoint b, IPoint c) {
  ll x0 = a.x == b.x ? a.x : b.x == c.x ? b.x : c.x;
  ll y0 = a.y == b.y ? a.y : b.y == c.y ? b.y : c.y;
  ll x1 = a.x != x0 ? a.x : b.x != x0 ? b.x : c.x;
  ll y1 = a.y != y0 ? a.y : b.y != y0 ? b.y : c.y;
  ll x2 = x1 - x0;
  ll y2 = y1 - y0;
  ll r = y2 == 1 ? (x2 == 1 ? 0 : 1) : (x2 == -1 ? 2 : 3);
  return make_pair(IPoint(x0, y0), r);
}

const vector<Ku> nbr_b({{{0,0},1}, {{0,0},3}, {{1,0},1}, {{1,0},2},
		        {{0,1},2}, {{0,1},3}, {{1,1},2}});

vector<Ku> nbr(Ku ku) {
  auto [co, r] = ku;
  vector<Ku> vec;
  for (auto [co_b, r_b] : nbr_b) {
    // DLOG("co=", co, "r=", r, "co_b=", co_b, "r_b=", r_b);
    vec.emplace_back(co + co_b.rotate(r), (r + r_b) % 4);
  }
  return vec;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  Ku start({0, 0}, 0);

  using st_a = pair<ll, Ku>;
  queue<st_a> que;
  map<Ku, ll> dist;
  que.emplace(0, start);
  dist[start] = 0;
  while (true) {
    auto [d, ku] = que.front(); que.pop();
    if (d > 20) break;
    for (Ku nxt_ku : nbr(ku)) {
      auto it = dist.find(nxt_ku);
      if (it != dist.end()) continue;
      dist[nxt_ku] = d + 1;
      que.emplace(d + 1, nxt_ku);
    }
  }
#if DEBUG
  for (ll r = 0; r < 4; r++) {
    cerr << "r=" << r << endl;
    for (ll y = 4; y >= -4; y--) {
      for (ll x = -4; x <= 4; x++) {
	Ku ku(IPoint(x, y), r);
	cerr << setw(2) << dist[ku] - (2 * max(abs(x), abs(y))) << " ";
      }
      cerr << endl;
    }
  }
#endif

  auto shift = [&](ll x, ll y, ll r) -> ll {
    for (ll i = -3; i <= 3; i++) {
      for (ll j = -3; j <= 3; j++) {
	if (!(abs(i) == 3 || abs(j) == 3)) continue;
	if ((x == 0) != (i == 0)) continue;
	if ((y == 0) != (j == 0)) continue;
	if ((x > 0) != (i > 0)) continue;
	if ((y > 0) != (j > 0)) continue;
	if ((x == y) != (i == j)) continue;
	if ((x > y) != (i > j)) continue;
	if ((x == -y) != (i == -j)) continue;
	if ((x > -y) != (i > -j)) continue;
	Ku ku(IPoint(i, j), r);
	return dist[ku] - (2 * max(abs(i), abs(j)));
      }
    }
    assert(0);
  };

  auto solve = [&]() -> void {
    IPoint a, b, c; cin >> a >> b >> c;
    Ku ku = buildKu(a, b, c);
    auto [ip, r] = ku;
    if (abs(ip.x) <= 3 && abs(ip.y) <= 3) {
      cout << dist[ku] << "\n";
    }else {
      cout << 2 * max(abs(ip.x), abs(ip.y)) + shift(ip.x, ip.y, r) << "\n";
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();


  return 0;
}

