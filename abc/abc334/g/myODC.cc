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

// @@ !! LIM(debug)

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig);

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig);

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st);

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t);
#endif

ostream& operator<< (ostream& os, int8_t x);

// definitions

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

struct UndoUnionFind {
  int size;
  vector<int> _parent;
  vector<int> _gsize;
  vector<pair<int, int>> _history;

  UndoUnionFind(int size_) : size(size_), _parent(size), _gsize(size, 1), _history() {
    iota(_parent.begin(), _parent.end(), 0);
  }

  int leader(int i) {
    for (; _parent[i] != i; i = _parent[i]);
    return i;
  }

  int gsize(int i) { return _gsize[i]; }

  int merge(int i, int j) {
    int x = leader(i);
    int y = leader(j);
    if (x == y) {
      _history.emplace_back(-1, -1);
      return x;
    }else {
      if (_gsize[x] < _gsize[y]) swap(x, y);
      _history.emplace_back(y, x);
      _parent[y] = x;
      _gsize[x] += _gsize[y];
      return x;
    }
  }

  void undo() {
    if (_history.empty()) { throw runtime_error("UndoUnionFInd: Fatal.  Empty history stack."); }
    auto [y, x] = _history.back(); _history.pop_back();
    if (y >= 0) {
      _parent[y] = y;
      _gsize[x] -= _gsize[y];
    }
  }
};

using u64 = unsigned long long;
using pii = pair<int, int>;

// Offilne Dynamic Connectivity
struct OffDynConn { 
  bool built;
  int size;
  int tlim; 
  int node_h_size;
  UndoUnionFind uuf;
  int seq_idx;
  map<pii, int> edge_idx;
  vector<pii> v_edge;
  vector<vector<pii>> ops;
  vector<vector<int>> nodes;

  OffDynConn(int size_, int tlim_)
    : built(false), size(size_), tlim(tlim_), node_h_size(bit_ceil((u64)tlim)), uuf(size), seq_idx(0), edge_idx(),
      v_edge(), ops(), nodes(2 * node_h_size) {}
  
  // calling edge_set(t, ...) must be done in the ascending order of t
  void edge_set(int t, int i, int j, bool conn) {
    if (i == j) return;
    if (i > j) swap(i, j);
    const pii p(i, j);
    int idx = -1;
    auto it = edge_idx.find(p);
    if (it == edge_idx.end()) {
      idx = seq_idx++;
      v_edge.resize(idx + 1);
      v_edge[idx] = p;
      edge_idx[p] = idx;
      ops.resize(idx + 1);
    }else {
      idx = it->second;
    }
    if (not ops[idx].empty()) {
      int prev = ops[idx].back().first;
      if (prev > t) throw runtime_error("OffDynConn: edge_set(): time reversed.");
      if (prev == t) ops[idx].pop_back();
    }
    ops[idx].emplace_back(t, conn);
    built = false;
  }

  void _range_set(int idx, int t1, int t2) {
    int l = node_h_size + t1;
    int r = node_h_size + t2 - 1;
    while (l <= r) {
      if (l % 2 != 0) nodes[l].push_back(idx);
      l = (l + 1) / 2;
      if (r % 2 == 0) nodes[r].push_back(idx);
      r = (r - 1) / 2;
    }
  }

  void build() {
    for (int idx = 0; idx < seq_idx; idx++) {
      int t_prev = -1;
      for (auto [t, b] : ops[idx]) {
        if (b) {
          if (t_prev >= 0) continue;
          t_prev = t;
        }else {
          if (t_prev < 0) continue;
          _range_set(idx, t_prev, t);
          t_prev = -1;
        }
      }
      if (t_prev >= 0) _range_set(idx, t_prev, node_h_size);
    }
    built = true;
  }

  void run(auto f) {
    if (not built) build();
    int cur = 1;
    for (; cur <= node_h_size; cur *= 2) {
      for (int i : nodes[cur]) {
        auto [a, b] = v_edge[i];
        uuf.merge(a, b);
      }
    }
    cur = node_h_size;
    int l = 0, r = 1;
    for (int t = 0; t < tlim; t++) {
      while (not (l == t and r == t + 1)) {
        if (r <= t) {
          for (int j = 0; j < (int)nodes[cur].size(); j++) uuf.undo();
          if (cur % 2 == 0) r += r - l;
          else l -= r - l;
          cur /= 2;
        }else {
          ll m = (l + r) / 2;
          if (t < m) {
            cur = cur * 2;
            r = m;
          }else {
            cur = cur * 2 + 1;
            l = m;
          }
          for (int j : nodes[cur]) {
            auto [a, b] = v_edge[j];
            uuf.merge(a, b);
          }
        }
      }
      f(t);
    }
  }
};


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpMVec(Q, (TP, X, Y)) [qBeJDtFF]
  auto TP = vector(Q, ll());
  auto X = vector(Q, ll());
  auto Y = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; TP[i] = v1;
    ll v2; cin >> v2; X[i] = v2;
    ll v3; cin >> v3; Y[i] = v3;
  }
  // @End [qBeJDtFF]
  ll M = 0;
  REP(t, 0, Q) if (TP[t] == 3) M++;
  OffDynConn odc(N, M);
  vector midx(M, ll());
  auto func = [&](ll m) -> void {
    ll t = midx[m];
    ll x = X[t], y = Y[t];
    if (odc.uuf.leader(x) == odc.uuf.leader(y)) cout << 1 << "\n";
    else cout << 0 << "\n";
  };
  ll m = 0;
  REP(t, 0, Q) {
    if (TP[t] == 1) {
      odc.edge_set(m, X[t], Y[t], true);
    }else if (TP[t] == 2) {
      odc.edge_set(m, X[t], Y[t], false);
    }else if (TP[t] == 3) {
      midx[m] = t;
      m++;
      if (m == M) break;
    }else assert(0);
  }
  odc.run(func);

  return 0;
}

