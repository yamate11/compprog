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

struct MyExc : exception {};

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  using sta = tuple<ll, ll, ll, ll>;
  vector<vector<sta>> nbr(n);
  vector<ll> X(n-1), Y(n-1), W(n-1), P(n-1);
  for (ll i = 0; i < n - 1; i++) {
    ll x, y, w, p; cin >> x >> y >> w >> p; x--; y--;
    X[i] = x;
    Y[i] = y;
    W[i] = w;
    P[i] = p;
    nbr[x].emplace_back(y, w, p, i);
    nbr[y].emplace_back(x, w, p, i);
  }
  vector<ll> reduce_may(n), reduce_must(n), pidx(n, -1);
  auto dfs1 = [&](auto rF, ll nd, ll pt) -> ll {
    ll w0 = -1, p0 = -1;
    ll tw = 0, tr_may = 0, tr_must = 0;
    for (auto [m, w, p, i] : nbr[nd]) {
      if (m == pt) {
	pidx[nd] = i;
	w0 = w;
	p0 = p;
	continue;
      }
      auto ww = rF(rF, m, nd);
      tw += ww;
      tr_may += reduce_may[m];
      tr_must += reduce_must[m];
    }
    if (nd != 0) {
      if (tw - tr_may > p0) throw MyExc();
      ll r0_may = min(w0 - 1, p0 - (tw - tr_may));
      reduce_may[nd] = tr_may + r0_may;
      reduce_must[nd] = max(tw - tr_must - p0, 0LL);
    }
    return tw + w0;
  };
  auto dfs2 = [&](auto rF, ll nd, ll red) -> void {
    DLOG("dfs2 called, nd=", nd, "red=", red);
    for (auto [m, w, p, i] : nbr[nd]) {
      if (i == pidx[nd]) continue;
      red -= reduce_must[m];
    }
    for (auto [m, w, p, i] : nbr[nd]) {
      if (i == pidx[nd]) continue;
      ll rr = min(reduce_may[m] - reduce_must[m], max(0LL, red));
      ll r = rr + reduce_must[m];
      rF(rF, m, r);
      red -= r;
    }
    if (red < 0) red = 0;
    if (nd != 0) {
      W[pidx[nd]] -= red;
      P[pidx[nd]] -= red;
    }
  };

  try {
    dfs1(dfs1, 0, -1);
    DLOG("reduce_may=", reduce_may);
    DLOG("reduce_must=", reduce_must);
    dfs2(dfs2, 0, 0);
    cout << n << endl;
    for (ll i = 0; i < n - 1; i++) {
      cout << X[i] + 1 << " " << Y[i] + 1 << " " << W[i] << " " << P[i] << endl;
    }
  }catch(MyExc& e) {
    cout << -1 << endl;
  }


  return 0;
}

