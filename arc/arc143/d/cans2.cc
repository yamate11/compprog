#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(input f:updMaxMin debug cmpNaive bridge)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

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

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

template <typename T1, typename T2, typename T3, typename T4, typename T5>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5>& t);

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t);

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

ostream& operator<< (ostream& os, const __int128& x);

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

template <typename T1, typename T2, typename T3, typename T4, typename T5>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ", " << get<4>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ", " << get<4>(t) << ", " << get<5>(t) << ")";
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

// for Enum type; just displays ordinals.
template <typename E>
typename std::enable_if<std::is_enum<E>::value, std::ostream&>::type
operator<<(std::ostream& os, E e) {
    return os << static_cast<typename std::underlying_type<E>::type>(e);
}

// This is a very ad-hoc implementation...
ostream& operator<<(ostream& os, const __int128& v) {
  unsigned __int128 a = v < 0 ? -v : v;
  ll i = 0;
  string s(64, ' ');
  if (v == 0) {
    s[i++] = '0';
  }else {
    while (a > 0) {
      s[i++] = '0' + (char)(a % 10);
      a /= 10;
    }
  }
  if (v < 0) {
    s[i++] = '-';
  }
  s.erase(s.begin() + i, s.end());
  reverse(s.begin(), s.end());
  os << s;
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

// ---- inserted library file cmpNaive.cc

const string end_mark("^__=end=__^");

int naive(istream& cin, ostream& cout);
int body(istream& cin, ostream& cout);

void cmpNaive() {
  while (true) {
    string s;
    getline(cin, s);
    bool run_body;
    if (s.at(0) == 'Q') {
      return;
    }else if (s.at(0) == 'B') {
      run_body = true;
    }else if (s.at(0) == 'N') {
      run_body = false;
    }else {
      cerr << "Unknown body/naive specifier.\n";
      exit(1);
    }
    string input_s;
    while (true) {
      getline(cin, s);
      if (s == end_mark) break;
      input_s += s;
      input_s += "\n";
    }
    stringstream ss_in(move(input_s));
    stringstream ss_out;
    ss_out << setprecision(20);
    if (run_body) {
      body(ss_in, ss_out);
    }else {
      naive(ss_in, ss_out);
    }
    cout << ss_out.str() << end_mark << endl;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if CMPNAIVE
  if (argc == 2) {
    if (strcmp(argv[1], "cmpNaive") == 0) {
      cmpNaive();
    }else if (strcmp(argv[1], "naive") == 0) {
      naive(cin, cout);
    }else if (strcmp(argv[1], "skip") == 0) {
      exit(0);
    }else {
      cerr << "Unknown argument.\n";
      exit(1);
    }
  }else {
#endif
    body(cin, cout);
#if CMPNAIVE
  }
#endif
  return 0;
}

/*
int naive(istream& cin, ostream& cout) {
  return 0;
}
int body(istream& cin, ostream& cout) {
  return 0;
}
*/

// ---- end cmpNaive.cc

// ---- inserted library file bridge.cc

struct lowlink {
  int size;
  vector<vector<int>> _nbr;
  vector<vector<int>> children;
  vector<int> parent;
  vector<vector<int>> back_edges_s;
  vector<vector<int>> back_edges_e;
  vector<int> _ord; // preorder
  vector<int> _low; // low[i] = min{ ord[k] | k is reachable from i using at most one back edge. }
  vector<int> roots;
  bool built;
  int _seq;

  lowlink(int size_) : size(size_), _nbr(size), children(size), parent(size, -1),
                       back_edges_s(size), back_edges_e(size), _ord(0), _low(size), roots(0), built(false), _seq(0) {}

  void add_edge(int u, int v) {
    if (built) throw runtime_error("lowlink.add_edge: already built");
    _nbr[u].push_back(v);
    _nbr[v].push_back(u);
  }

  void _dfs_build(int i, int pt) {
    bool found = false;
    _ord[i] = _low[i] = _seq++;
    for (int j : _nbr[i]) {
      if (j == pt and not found) found = true;
      else if (_ord[j] < 0) { // j has not been visited
        _dfs_build(j, i);
        if (_low[j] < _low[i]) _low[i] = _low[j];
        parent[j] = i;
        children[i].push_back(j);
      }else if (_ord[j] < _ord[i]) { // (i,j) is a newly found back edge
        if (_ord[j] < _low[i]) _low[i] = _ord[j];
        back_edges_s[i].push_back(j);
      }else if (i == j) { // self-loop
        back_edges_s[i].push_back(i);
        back_edges_e[i].push_back(i);
      }else { // already-found back edge
        back_edges_e[i].push_back(j);
      }
    }
  }

  void build() {
    if (built) return;
    built = true;
    _ord.resize(0);
    _ord.resize(size, -1);
    _seq = 0;
    roots.resize(0);
    for (int i = 0; i < size; i++) if (_ord[i] < 0) {
        roots.push_back(i);
        _dfs_build(i, -1);
      }
    _nbr.clear();
  }

  int ord(int i) {
    if (not built) build();
    return _ord[i];
  }

  int low(int i) {
    if (not built) build();
    return _low[i];
  }

};


/*
  An edge e is a bridge if the number of connected components increases when e is removed.
  A graph is two-edge connected if there is no bridge.
  A two-edge connected component (TECC) is a maximum two-edge connected subgraph.
 */
struct bridge {
  lowlink llk;
  vector<vector<int>> _tecc; // this.tecc(i) is the members of the i-th TECC
  vector<int> _node_teccidx; // i = this._node_teccidx(u) if u belongs to the i-th TECC
  bool built;
  
  bridge(int size) : llk(size), _tecc(0), _node_teccidx(size), built(false) {}
  void add_edge(int u, int v) { llk.add_edge(u, v); }

  bool is_bridge(int u, int v) {
    if (not built) build();
    if (u == v) return false;
    if (llk.ord(u) > llk.ord(v)) swap(u, v);
    bool b = llk.low(v) > llk.ord(u);
    // DLOGKL("  is_bridge", u, v, b, llk.ord(u), llk.ord(v), llk.low(v));
    return b;
  }

  void build() {
    if (built) return;
    built = true;
    llk.build();
    // auto visited = vector(llk.size, false);
    vector<int> yet = llk.roots;
    while (not yet.empty()) {
      int r = yet.back(); yet.pop_back();
      auto comp = vector<int>();
      auto dfs = [&](auto rF, int u) -> void {
        DLOGKL("dfs top", u);
        // if (visited[u]) return;
        // visited[u] = true;
        comp.push_back(u);
        for (int v : llk.children[u]) {
          DLOGK(u, v, is_bridge(u, v));
          if (is_bridge(u, v)) yet.push_back(v);
          else                 rF(rF, v);
        }
      };
      DLOGKL("dfs initialted", r);
      dfs(dfs, r);
      DLOGKL("dfs finishes", comp);
      for (int u : comp) _node_teccidx[u] = _tecc.size();
      _tecc.push_back(move(comp));
    }
  }

  int num_tecc() {
    if (not built) build();
    return _tecc.size();
  }

  const vector<int>& tecc(int ccid) {
    if (not built) build();
    return _tecc[ccid];
  }

  int node_tecc_idx(int u) {
    if (not built) build();
    return _node_teccidx[u];
  }

  vector<pair<int, int>> tecc_edges() {
    if (not built) build();
    vector<pair<int, int>> ret;
    for (int u = 0; u < llk.size; u++) {
      for (int v : llk.children[u]) if (is_bridge(u, v)) ret.emplace_back(node_tecc_idx(u), node_tecc_idx(v));
    }
    return ret;
  }

};


struct articulation {
  lowlink llk;
  vector<vector<int>> _bcc; // BiConnected Component
  vector<int> art_seq;  // art_seq[u] is the sequence number if u is an articulation point; -1, otherwise.
  int num_arts;
  bool built;

  articulation(int size) : llk(size), _bcc(), art_seq(size, -1), num_arts(0), built(false) {}

  void add_edge(int u, int v) { llk.add_edge(u, v); }

  void build() {
    if (built) return;
    built = true;
    llk.build();
    int seq = 0;
    // DLOGK(llk.roots);
    for (int rt : llk.roots) {
      // DLOGK(rt);
      vector<pair<int, int>> yet;
      if (llk.children[rt].size() == 0) {
        _bcc.push_back(vector<int>{rt});
      }else {
        if (llk.children[rt].size() >= 2) art_seq[rt] = seq++;
        for (int u : llk.children[rt]) yet.emplace_back(rt, u);
        while (not yet.empty()) {
          auto [pt, cld] = yet.back(); yet.pop_back();
          // DLOGK(pt, cld);
          vector<int> comp{pt};
          auto dfs = [&](auto rF, int u) -> void {
            comp.push_back(u);
            for (int v : llk.children[u]) {
              if (llk.low(v) >= llk.ord(u)) {
                if (art_seq[u] < 0) art_seq[u] = seq++;
                yet.emplace_back(u, v);
              }else rF(rF, v);
            }
          };
          dfs(dfs, cld);
          _bcc.push_back(move(comp));
        }
      }
    }
    num_arts = seq;
  }

  bool is_articulation(int u) {
    if (not built) build();
    return art_seq[u] >= 0;
  }

  int bcc_size() {
    if (not built) build();
    return _bcc.size();
  }

  const vector<int>& bcc(int idx) {
    if (not built) build();
    return _bcc[idx];
  }
  

  enum kind { BLOCK, CUT };

  struct bctree {
    const articulation* obj;
    int size_block;
    int size_cut;
    vector<int> arts;

    bctree(const articulation* obj_) : obj(obj_), size_block(obj->_bcc.size()), size_cut(obj->num_arts),
                                       arts(size_cut) {
      for (int i = 0; i < obj->llk.size; i++) if (obj->art_seq[i] >= 0) arts[obj->art_seq[i]] = i; 
    }

    int size() { return size_block + size_cut; }

    vector<pair<int, int>> edges() {
      vector<pair<int, int>> ret;
      for (int c = 0; c < size_block; c++) {
        for (int i : obj->_bcc[c]) {
          int a = obj->art_seq[i];
          if (a >= 0) ret.emplace_back(size_block + a, c);
        }
      }
      return ret;
    }

    pair<kind, int> what(int node) {
      if (node < size_block) return {BLOCK, node};
      else                   return {CUT, arts[node - size_block]};
    }

    int node(kind w, int i) {
      if (w == BLOCK) return i;
      else if (w == CUT) return size_block + obj->art_seq[i];
      else assert(0);
    }
  };

  bctree* make_bctree() {
    if (not built) build();
    bctree* p = new bctree(this);
    return p;
  }

};



// ---- end bridge.cc

// @@ !! LIM -- end mark --

// @DefStruct(a, (peer, edge, (rev, bool))) [o81eYjyS]
struct a_t {
  ll peer;
  ll edge;
  bool rev;
  a_t(ll peer_ = ll(), ll edge_ = ll(), bool rev_ = bool()) : peer(peer_), edge(edge_), rev(rev_) {}
  friend istream& operator>>(istream& istr, a_t& t) {
    istr >> t.peer >> t.edge >> t.rev;
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const a_t& t) {
    ostr << "(" << t.peer << ", " << t.edge << ", " << t.rev << ")";
    return ostr;
  }
};
// @End [o81eYjyS]

int naive(istream& cin, ostream& cout) {
  ll N, M; cin >> N >> M;
  // @InpVec(M, A, dec=1) [NZOoxtDz]
  auto A = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [NZOoxtDz]
  // @InpVec(M, B, dec=1) [DwxbN0iz]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; v -= 1; B[i] = v; }
  // @End [DwxbN0iz]

  auto solve = [&](ll x) {
    bridge br(2 * N);
    REP(i, 0, N) br.add_edge(i, N + i);
    REP(i, 0, M) {
      if (x >> i & 1) br.add_edge(B[i], N + A[i]);
      else            br.add_edge(A[i], N + B[i]);
    }
    ll cnt = 0;
    REP(i, 0, N) if (br.is_bridge(i, N + i)) cnt++;
    REP(i, 0, M) {
      if (x >> i & 1) {
        if (br.is_bridge(B[i], N + A[i])) cnt++;
      }else {
        if (br.is_bridge(A[i], N + B[i])) cnt++;
      }
    }
    return cnt;
  };

  string s; cin >> s;
  DLOGK(s);
  assert(ssize(s) == M);
  ll x0 = 0;
  REP(i, 0, M) if (s[i] == '1') x0 |= (1LL << i);
  ll nb0 = solve(x0);
  REP(x, 0, 1LL << M) {
    if (nb0 > solve(x)) {
      cout << "NG\n";
      return 0;
    }
  }
  cout << "OK\n";
  return 0;
}

int body(istream& cin, ostream& cout) {
  ll N, M; cin >> N >> M;
  // @InpVec(M, A, dec=1) [NZOoxtDz]
  auto A = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [NZOoxtDz]
  // @InpVec(M, B, dec=1) [DwxbN0iz]
  auto B = vector(M, ll());
  for (int i = 0; i < M; i++) { ll v; cin >> v; v -= 1; B[i] = v; }
  // @End [DwxbN0iz]

  vector nbr(N, vector<a_t>());
  REP(i, 0, M) {
    nbr[A[i]].emplace_back(B[i], i, false);
    nbr[B[i]].emplace_back(A[i], i, true );
  }

  DLOGK(nbr);

  string ans(M, ' ');
  vector ord(N, -1LL);
  vector low(N, -1LL);
  vector in_edge(N, -1LL);
  auto func = [&](ll top) -> void {
    ll seq = 0;
    auto dfs1 = [&](auto rF, ll nd) -> void {
      ord[nd] = low[nd] = seq++;
      for (auto [peer, edge, rev] : nbr[nd]) {
        if (edge == in_edge[nd]) {
          continue;
        }else if (ord[peer] < 0) {
          in_edge[peer] = edge;
          rF(rF, peer);
          updMin(low[nd], low[peer]);
        }else if (ord[peer] < ord[nd]) {
          updMin(low[nd], ord[peer]);
        }
      }
    };
    dfs1(dfs1, top);
    auto dfs2 = [&](auto rF, ll nd) -> void {
      for (auto [peer, edge, rev] : nbr[nd]) {
        if (edge == in_edge[nd]) {
          continue;
        }else if (nd == peer) {
          ans[edge] = '0';
        }else if (edge == in_edge[peer]) {
          DLOGKL('a', nd, peer, edge, rev);
          ans[edge] = rev ? '1' : '0';
          rF(rF, peer);
        }else if (ord[peer] < ord[nd]) {
          DLOGKL('b', nd, peer, edge, rev);
          ans[edge] = rev ? '1' : '0';
        }
      }
    };
    dfs2(dfs2, top);
  };
  REP(i, 0, N) if (ord[i] < 0) func(i);
  cout << ans << endl;

  return 0;
}

