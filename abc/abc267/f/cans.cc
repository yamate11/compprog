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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM(debug tree forall cmpNaive)

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

// ---- inserted library file tree.cc

using TreeEdge = pair<int, int>;

struct Tree {

  int numNodes;
  int root;
  int numEdges = 0;
  bool good_nbr = false;
  vector<vector<int>> _nbr;
      // if (u, v) is the idx-th edge, then _nbr[u] has v and _nbr[v] has u.
      // when good_nbr is true, then _nbr[u][0] is the parent.  (_nbr[root][0] is -1)
  vector<int> _depth;
  unordered_map<int, map<int, int>> _node2edgeIdx;
  vector<vector<int>> pPnt;   
          // pPnt[0][n] == parent of n (or root if n is root)
          // pPnt[t][n] == parent^{2^t}[n]

  Tree(int numNodes_, int root_ = 0) : numNodes(numNodes_), root(root_), _nbr(numNodes_) {}

  Tree(int numNodes_, const auto& edge_, int root_ = 0) : numNodes(numNodes_), root(root_), _nbr(numNodes_) {
    for (size_t i = 0; i < edge_.size(); i++) add_edge(edge_[i].first, edge_[i].second);
  }

  void set_parent_child() {
    if (good_nbr) return;
    if (numNodes != numEdges + 1) throw range_error("numNodes and numEdges");
    good_nbr = true;
    _depth.resize(numNodes);
    auto dfs = [&](auto rF, int nd, int pt, int d) -> void {
      _depth[nd] = d;
      int sz = _nbr[nd].size();
      int ip = -1;
      for (int i = 0; i < sz; i++) {
        if (_nbr[nd][i] == pt) ip = i;
        else                  rF(rF, _nbr[nd][i], nd, d + 1);
      }
      if (nd == root) {
        ip = _nbr[nd].size();
        _nbr[nd].push_back(-1);
      }
      if (ip > 0) swap(_nbr[nd][0], _nbr[nd][ip]);
    };
    dfs(dfs, root, -1, 0);
  }

  void preparePPnt() {
    set_parent_child();
    if (not pPnt.empty()) return;
    vector<int> vec_parent(numNodes);
    for (int i = 0; i < numNodes; i++) vec_parent[i] = i == root ? i : _nbr[i][0];
    pPnt.push_back(move(vec_parent));
    for (int t = 0; true; t++) {
      bool done = true;
      vector<int> vec(numNodes);
      for (int n = 0; n < numNodes; n++) {
	int m = pPnt[t][n];
	vec[n] = pPnt[t][m];
	if (vec[n] != m) done = false;
      }
      pPnt.push_back(move(vec));
      if (done) break;
    }
  }

  int add_edge(int x, int y) {
    _nbr[x].push_back(y);
    _nbr[y].push_back(x);
    _node2edgeIdx[x][y] = _node2edgeIdx[y][x] = numEdges;
    return numEdges++;
  }

  // parent(root) == -1
  int parent(int x) {
    set_parent_child();
    return _nbr[x][0];
  }

  vector<int> child(int x) { 
    set_parent_child();
    vector<int> ret(_nbr[x].size() - 1);
    copy(_nbr[x].begin() + 1, _nbr[x].end(), ret.begin());
    return ret;
  }

  int depth(int x) {
    set_parent_child();
    return _depth[x];
  }

  // Lowest Common Ancestor
  int lca(int x, int y) {
    set_parent_child();
    if (_depth[x] > _depth[y]) swap(x, y);
    int dep = _depth[x];
    int yy = ancestorDep(y, dep);
    if (x == yy) return x;
    int t = 0;
    for (int q = 1; q < dep; q *= 2) t++;
    for ( ; t >= 0; t--) {
      if (pPnt[t][x] != pPnt[t][yy]) {
	x = pPnt[t][x];
	yy = pPnt[t][yy];
      }
    }
    return parent(x);
  }

  // the path between two nodes (list of nodes, including x and y)
  vector<int> nnpath(int x, int y) {
    vector<int> ret;
    int c = lca(x, y);
    for ( ; x != c; x = parent(x)) ret.push_back(x);
    ret.push_back(c);
    int len = (int)ret.size();
    for ( ; y != c; y = parent(y)) ret.push_back(y);
    reverse(ret.begin() + len, ret.end());
    return ret;
  }

  // the ancestor of n whose depth is dep
  int ancestorDep(int x, int dep) {
    preparePPnt();
    int diff = depth(x) - dep;
    if (diff < 0) throw range_error("ancestorDep");
    for (int t = 0; diff >> t; t++) if (diff >> t & 1) x = pPnt[t][x];
    return x;
  }

  int edgeIdx(int x, int y) {
    auto itx = _node2edgeIdx.find(x);
    if (itx == _node2edgeIdx.end()) return -1;
    auto ity = itx->second.find(y);
    if (ity == itx->second.end()) return -1;
    return ity->second;
  }

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"    
  tuple<int, int, int, int, int> diameter() {
    set_parent_child();
    if (numNodes == 1) return {0, 0, 0, 0, 0};
    if (numNodes == 2) return {1, 0, 1, 0, 1};
    int nd0 = max_element(_depth.begin(), _depth.end()) - _depth.begin();
    int nd1 = -1, ct0 = -1, ct1 = -1;
    int diam = 0;
    auto dfs2 = [&](auto rF, int nd, int dp, int pt) -> bool {
      DLOGKL("dfs2 in", nd, dp, pt);
      bool ret = false;
      ll numChildren = 0;
      DLOGK(nd, _nbr[nd]);
      for (ll cld : _nbr[nd]) {
        if (cld < 0 or cld == pt) continue;
        numChildren++;
        bool bbb = rF(rF, cld, dp + 1, nd);
        ret = ret || bbb;
      }
      if (numChildren > 0) {
        if (ret) {
          if (diam % 2 == 0) {
            if (dp == diam / 2) ct0 = ct1 = nd;
          }else {
            if (dp == diam / 2) ct0 = nd;
            else if (dp == diam / 2 + 1) ct1 = nd;
          }
        }
      }else {
        if (dp > diam) {
          diam = dp;
          nd1 = nd;
          ret = true;
        }
      }
      DLOGKL("dfs2 out", nd, nd1, ct0, ct1, diam);
      return ret;
    };
    dfs2(dfs2, nd0, 0, -1);
    return {diam, nd0, nd1, ct0, ct1};
  }
#pragma GCC diagnostic pop

  void change_root(int newRoot) {
    pPnt.resize(0);
    if (good_nbr) {
      size_t t = _nbr[root].size();
      swap(_nbr[root][0], _nbr[root][t - 1]);
      _nbr[root].pop_back();
      good_nbr = false;
    }
    root = newRoot;
  }

};

template <typename T>
vector<T> reroot(Tree& tree, const T& unit, auto add, auto mod) {
  vector<T> result(tree.numNodes);
  vector<T> sum(tree.numNodes);
  vector<vector<T>> sum_excl(tree.numNodes);
  
  auto dfs1 = [&](const auto& recF, int n) -> void {
    const auto cld = tree.child(n);
    int k = cld.size();
    vector<T> right(k+1), m(k+1);
    T g = right[k] = unit;
    for (int i = k-1; i >= 0; i--) {
      int c = cld[i];
      recF(recF, c);
      m[i] = mod(sum[c], n, c);
      right[i] = g = add(m[i], g);
    }
    sum[n] = g;
    T gp = unit;
    sum_excl[n].resize(k);
    for (int i = 0; i < k; i++) {
      sum_excl[n][i] = add(gp, right[i+1]);
      gp = add(gp, m[i]);
    }
  };
  dfs1(dfs1, tree.root);

  auto dfs2 = [&](const auto& recF, int n, T t) -> void {
    result[n] = add(sum[n], t);
    const auto cld = tree.child(n);
    int k = cld.size();
    for (int i = 0; i < k; i++) {
      int c = cld[i];
      recF(recF, c, mod(add(sum_excl[n][i], t), c, n));
    }
  };
  dfs2(dfs2, tree.root, unit);
  
  return result;
}

// ---- end tree.cc

// ---- inserted library file forall.cc

#define EX_REP_LL(i, from, to) for (ll i = from; i < to; i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

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

// @@ !! LIM -- end mark --

struct myexc : exception {};

int naive(istream& cin, ostream& cout) {
  ll N; cin >> N;
  vector<vector<ll>> nbr(N);
  REP(i, 0, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  ll Q; cin >> Q;
  vector<ll> U(Q), K(Q);
  vector<ll> ans(Q);
  REP(q, 0, Q) { cin >> U[q] >> K[q]; }
  REP(q, 0, Q) { cin >> ans[q]; }
  REP(q, 0, Q) {
    ll u = U[q], k = K[q]; u--;
    ll a = ans[q];
    if (a > 0) a--;
    bool result;
    auto dfs = [&](auto rF, ll nd, ll pt, ll dep) -> void {
      if (dep == k) {
        if (a < 0) { result = false; throw myexc(); }
        if (a == nd) { result = true; throw myexc(); }
      }else {
        if (a == nd) { result = false; throw myexc(); }
      }
      for (ll cld : nbr[nd]) {
        if (cld == pt) continue;
        rF(rF, cld, nd, dep + 1);
      }
    };
    try {
      dfs(dfs, u, -1, 0);
      if (a < 0) cout << "OK\n";
      else cout << "NG\n";
    }catch (myexc& e) {
      cout << (result ? "OK\n" : "NG\n");
      return 0;
    }
  }

  return 0;
}

int body(istream& cin, ostream& cout) {

  ll N; cin >> N;
  Tree tr(N);
  REP(i, 0, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    tr.add_edge(a, b);
  }
  auto [diam, ep0, ep1, ct0, ct1] = tr.diameter();
  DLOGK(diam, ep0, ep1, ct0, ct1);
  tr.change_root(ct0);
  ll nxtTop1 = tr.ancestorDep(ep1, 1);
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll u, k; cin >> u >> k; u--;
    DLOGK(u, k);
    ll dep = tr.depth(u);
    DLOGK(dep);
    if (k <= dep) cout << tr.ancestorDep(u, dep - k) + 1 << "\n";
    else {
      ll ep = (dep >= 1 and tr.ancestorDep(u, 1) == nxtTop1) ? ep0 : ep1;
      if (k - dep > tr.depth(ep)) cout << "-1\n";
      else cout << tr.ancestorDep(ep, k - dep) + 1 << "\n";
    }
  }

  return 0;
}

