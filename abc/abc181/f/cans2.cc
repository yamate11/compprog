#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  using sta = pair<ll, ll>;
  vector<sta> xy;
  for (ll i = 0; i < N; i++) {
    ll x, y; cin >> x >> y;
    xy.emplace_back(x, y);
  }
  sort(xy.begin(), xy.end());
  vector<ll> xs;
  vector<vector<ll>> ys;
  xs.push_back(-1000);
  ys.push_back(vector<ll>({-100}));
  ll prev = -10000;
  for (ll i = 0; i < N; i++) {
    auto [x, y] = xy[i];
    if (x != prev) {
      prev = x;
      xs.push_back(x);
      ys.push_back(vector<ll>({-100}));
    }
    ys.back().push_back(y);
  }
  xs.push_back(1000);
  ys.push_back(vector<ll>({-100}));
  for (auto& v: ys) v.push_back(100);

  DLOG("xy=", xy);
  DLOG("xs=", xs);
  DLOG("ys=", ys);

  ll m = xs.size();
  ll idx = 1;
  using stb = pair<ll, double>;
  vector<vector<stb>> nbr;
  vector<ll> prevarea({0});;

  auto dist = [&](ll x0, ll y0, ll x1, ll y1) -> double {
    ll x = x1 - x0;
    ll y = y1 - y0;
    return sqrt(x * x + y * y);
  };
  auto border = [&](ll i, ll j, double d) -> void {
    ll k = nbr.size();
    for (ll p = 0; p < max(i, j) + 1 - k; p++) {
      nbr.push_back(vector<stb>());
    }
    nbr[i].emplace_back(j, d);
    nbr[j].emplace_back(i, d);
  };

  for (ll i = 0; i < m-1; i++) {
    ll x0 = xs[i];
    ll x1 = xs[i + 1];
    vector<ll>& ys0 = ys[i];
    vector<ll>& ys1 = ys[i + 1];
    ll sz0 = ys0.size();
    ll sz1 = ys1.size();
    ll p0 = 0;
    ll p1= 1;
    vector<ll> nextarea({idx});
    idx++;
    DLOG("i=", i, "prevarea=", prevarea);
    while (true) {
      for ( ; p0 < sz0 && ys0[p0] <= ys1[p1]; p0++) {
	if (p0 == sz0 - 1 && p1 == sz1 - 1) break;
	border(idx - 1, idx, dist(x0, ys0[p0], x1, ys1[p1]));
	border(prevarea[p0], idx, ys0[p0 + 1] - ys0[p0]);
	idx++;
      }
      DLOG("  place1, i=", i, "p0=", p0, "p1=", p1, "idx=", idx);
      for (; p1 < sz1 && ys0[p0] >= ys1[p1]; p1++) {
	if (p0 == sz0 - 1 && p1 == sz1 - 1) break;
	border(idx - 1, idx, dist(x0, ys0[p0], x1, ys1[p1]));
	nextarea.push_back(idx);
	idx++;
      }
      DLOG("  place2, i=", i, "p0=", p0, "p1=", p1, "idx=", idx);
      if (p0 == sz0 - 1 && p1 == sz1 - 1) break;
    }
    prevarea = move(nextarea);
  }
  
  vector<double> avail(idx);
  auto dfs = [&](auto rF, ll i, double cur) -> void {
    if (cur <= avail[i]) return;
    avail[i] = cur;
    for (auto [j, w] : nbr[i]) rF(rF, j, min(w, cur));
  };
  dfs(dfs, 0, 1000);

#if DEBUG
  for (ll i = 0; i < (ll)nbr.size(); i++) {
    DLOG("  ", i, nbr[i]);
  }
  for (ll i = 0; i < idx; i++) {
    DLOG("    ", i, avail[i]);
  }
#endif

  cout << avail[idx - 1] / 2.0 << endl;


  return 0;
}

