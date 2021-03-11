#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug)
// --> f:<< debug
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

struct Cell {
  ll right;
  ll down;
  ll value;
};

ostream& operator<< (ostream& os, const Cell& c) {
  os << "{ r=" << c.right << ", d=" << c.down << ", v=" << c.value << "} ";
  return os;
}

const ll HORIZ = 1;
const ll VERT = 2;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m, q; cin >> n >> m >> q;

  vector<Cell> cells((n+1) * (m+1));
  vector<vector<ll>> orig;
  for (ll i = 0; i < n + 1; i++) {
    for (ll j = 0; j < m + 1; j++) {
      ll idx = (m + 1) * i + j;
      Cell& c = cells[idx];
      if (i >= 1 && j >= 1) cin >> c.value;
      c.right = j < m ? idx + 1 : -1;
      c.down = i < n ? idx + (m + 1) : -1;
    }
  }
  auto get = [&](ll r, ll c) -> ll {
    ll x = c;
    for (ll i = 0; i < r; i++) x = cells[x].down;
    return x;
  };
  auto change = [&] (ll x1, ll x2, ll dir, ll len) -> void {
    for (ll i = 0; i < len; i++)  {
      if (dir == HORIZ) {
	swap(cells[x1].down, cells[x2].down);
	x1 = cells[x1].right;
	x2 = cells[x2].right;
      }else if (dir == VERT) {
	swap(cells[x1].right, cells[x2].right);
	x1 = cells[x1].down;
	x2 = cells[x2].down;
      }
    }
  };

  auto disp = [&]() -> string {
    stringstream ss;
    for (ll i = 1; i <= n; i++) {
      ll x = i * (m + 1);
      for (ll j = 0; j < m; j++) {
	if (j > 0) ss << " ";
	x = cells[x].right;
	ss << cells[x].value;
      }
      ss << "\n";
    }
    return ss.str();
  };

  for (ll _q = 0; _q < q; _q++) {
    ll a, b, c, d, h, w; cin >> a >> b >> c >> d >> h >> w;
    ll p1 = get(a - 1, b);
    ll p2 = get(c - 1, d);
    ll q1 = get(a, b - 1);
    ll q2 = get(c, d - 1);
    ll r1 = get(a + h - 1, b);
    ll r2 = get(c + h - 1, d);
    ll s1 = get(a, b + w - 1);
    ll s2 = get(c, d + w - 1);
    DLOG("p1=", p1, "p2=", p2, "q1=", q1, "q2=", q2, "r1=", r1, "r2=", r2, "s1=", s1, "s2=", s2);
    DLOG("  1. cells=", cells);
    change(p1, p2, HORIZ, w);
    DLOG("  2. cells=", cells);
    change(q1, q2, VERT, h);
    DLOG("  3. cells=", cells);
    change(r1, r2, HORIZ, w);
    DLOG("  4. cells=", cells);
    change(s1, s2, VERT, h);
    DLOG("  5. cells=", cells);
    DLOG("cells=", cells);
    DLOG("q=", _q);
    DLOG(disp());
  }
  
  cout << disp();


  return 0;
}

