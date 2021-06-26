#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(dinic debug)

// ---- inserted library file dinic.cc

struct Edge {
  int dst;  // destination
  ll cap;   // capacity
  int rev;  // index of reverse edge
  Edge(int d, ll c, int r) : dst(d), cap(c), rev(r) {}
};

struct Dinic {

  int vSize;
  int source;
  int sink;
  vector<int> level;  // from sink rather than source
  vector<size_t> iter;
  vector<vector<Edge>> edges;
  int eidx;
  vector<int> e_to_u;
  vector<int> e_to_uidx;

  ll dfs(int u, ll sCap) {
    if (u == sink) return sCap;
    ll f = 0;
    for (size_t& i = iter.at(u); i < edges.at(u).size(); i++) {
      Edge& e = edges.at(u).at(i);
      if (e.cap == 0 || level.at(e.dst) >= level.at(u)) continue;
      ll f0 = dfs(e.dst, min(sCap - f, e.cap));
      e.cap -= f0;
      edges.at(e.dst).at(e.rev).cap += f0;
      f += f0;
      if (f == sCap) break;
    }
    return f;
  }

  void set_level() {
    level.assign(vSize, -1);
    deque<pair<int,int>> deq;
    deq.emplace_back(sink, 0);
    while (!deq.empty()) {
      pair<int,int> p = deq.front(); deq.pop_front();
      int i = p.first;
      int lev = p.second;
      if (level.at(i) >= 0) continue;
      level.at(i) = lev;
      for (const Edge& erev : edges.at(i)) {
	const Edge& e = edges.at(erev.dst).at(erev.rev);
	if (e.cap == 0) continue;
	deq.emplace_back(erev.dst, lev + 1);
      }
    }
  }

public:

  Dinic(int sz, int src, int snk)
    : vSize(sz), source(src), sink(snk), edges(sz), eidx(0) {}

  ll add_edge(int u, int v, ll cap) {
    assert(0 <= u && u < vSize && 0 <= v && v < vSize);
    assert(cap >= 0);
    int nu = edges.at(u).size();
    int nv = edges.at(v).size();
    edges.at(u).emplace_back(v, cap, nv);
    edges.at(v).emplace_back(u, 0,   nu);
    assert(eidx == (ll)e_to_u.size() && eidx == (ll)e_to_uidx.size());
    e_to_u.push_back(u);
    e_to_uidx.push_back(nu);
    return eidx++;
  }

  ll run() {
    ll flow = 0;
    while(1) {
      set_level();
      if (level.at(source) == -1) break;
      iter.assign(vSize, 0);
      flow += dfs(source, LLONG_MAX);
    }
    return flow;
  }

  ll eflow(ll i) {
    Edge e = edges.at(e_to_u[i]).at(e_to_uidx[i]);
    return edges.at(e.dst).at(e.rev).cap;
  }

};
// ---- end dinic.cc

// ---- inserted function f:<< from util.cc
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

// ---- end f:<<

// ---- inserted library file debug.cc
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(bool with_nl, Head&& head) {
  cerr << head;
  if (with_nl) cerr << endl;
}

template <class Head, class... Tail>
void dbgLog(bool with_nl, Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(with_nl, forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DLOGNNL(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

/*
#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL_LIB(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif
*/

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)
#define DUP9(E1,...)   DUP1(E1), DUP8(__VA_ARGS__)
#define DUP10(E1,...)   DUP1(E1), DUP9(__VA_ARGS__)
#define DUP11(E1,...)   DUP1(E1), DUP10(__VA_ARGS__)
#define DUP12(E1,...)   DUP1(E1), DUP11(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP12, DUP11, DUP10, DUP9, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

#if DEBUG_LIB
  #define DLOG_LIB   DLOG
  #define DLOGK_LIB  DLOGK
  #define DLOGKL_LIB DLOGKL
#endif

// ---- end debug.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, N; cin >> H >> W >> N;
  vector<ll> A(N), B(N), C(N), D(N);
  for (ll i = 0; i < N; i++) {
    ll a, b, c, d; cin >> a >> b >> c >> d; a--; b--; c--; d--;
    A[i] = a;
    B[i] = b;
    C[i] = c;
    D[i] = d;
  }

  Dinic d(2 + H + N + W + N, 0, 1);
  DLOG("AA");
  for (ll i = 0; i < H; i++) {
    ll x = 0, y = 2 + i;
    DLOGK(x, y);
    d.add_edge(x, y, 1);
  }
  DLOG("BB");
  for (ll i = 0; i < W; i++) {
    ll x = 2 + H + N + i, y = 1;
    DLOGK(x, y);
    d.add_edge(x, y, 1);
  }
  DLOG("CC");
  for (ll i = 0; i < N; i++) {
    d.add_edge(2 + H + i, 2 + H + N + W + i, 1);
    DLOGK(i);
    for (ll j = A[i]; j <= C[i]; j++) {
      ll x = 2 + j, y = 2 + H + i;
      DLOGKL("  ", x, y);
      d.add_edge(x, y, 1);
    }
    DLOG("/");
    for (ll j = B[i]; j <= D[i]; j++) {
      ll x = 2 + H + N + W + i, y = 2 + H + N + j;
      DLOGKL("  ", x, y);
      d.add_edge(x, y, 1);
    }
  }
  ll flow = d.run();
  cout << flow << endl;

  return 0;
}

