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

// @@ !! LIM(debug tree)

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

struct Tree {

  int numNodes;
  int root;
  int numEdges = 0;
  bool pc_built = false;
  vector<vector<int>> _nbr;
      // if (u, v) is an edge, then _nbr[u] has v and _nbr[v] has u.
  vector<int> _stsize;
  vector<int> _depth;
  vector<int> _parent;
  vector<vector<int>> _children;
  unordered_map<int, map<int, int>> _node2edgeIdx;
  vector<pair<int, int>> _edges;
  vector<vector<int>> pPnt;   
          // pPnt[0][n] == parent of n (or root if n is root)
          // pPnt[t][n] == parent^{2^t}[n]

  Tree(int numNodes_, int root_ = 0) : numNodes(numNodes_), root(root_), _nbr(numNodes_) {}

  // Implementation note:
  // Adding Tree(int, const vector<pair<int, int>>, int) is not a good idea.  If it were added,
  // Tree tr(n, x); would fail when x is long long.  You need to write Tree tr(n, (int)x), then.

  void set_parent_child() {
    if (pc_built) return;
    pc_built = true;
    if (numNodes != numEdges + 1) throw range_error("numNodes and numEdges");
    _stsize.resize(numNodes);
    _depth.resize(numNodes);
    _parent.resize(numNodes);
    _children.resize(numNodes);
    auto dfs = [&](auto rF, int nd, int pt, int d) -> void {
      _stsize[nd] = 1;
      _depth[nd] = d;
      _parent[nd] = pt;
      for (int c : _nbr[nd]) if (c != pt) {
          _children[nd].push_back(c);
          rF(rF, c, nd, d + 1);
          _stsize[nd] += _stsize[c];
        }
    };
    dfs(dfs, root, -1, 0);
  }

  void preparePPnt() {
    set_parent_child();
    if (not pPnt.empty()) return;
    vector<int> vec_parent(numNodes);
    for (int i = 0; i < numNodes; i++) vec_parent[i] = i == root ? i : _parent[i];
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
    _edges.emplace_back(x, y);
    return numEdges++;
  }

  // parent(root) == -1
  int parent(int x) {
    set_parent_child();
    return _parent[x];
  }

  const vector<int>& children(int x) { 
    set_parent_child();
    return _children[x];
  }

  int stsize(int x) {
    set_parent_child();
    return _stsize[x];
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

  pair<int, int> nodesOfEdge(int e) { return _edges[e]; }

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
      bool ret = false;
      ll numChildren = 0;
      for (ll cld : _nbr[nd]) {
        if (cld == pt) continue;
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
      return ret;
    };
    dfs2(dfs2, nd0, 0, -1);
    return {diam, nd0, nd1, ct0, ct1};
  }
#pragma GCC diagnostic pop

  void change_root(int newRoot) {
    pPnt.resize(0);
    if (pc_built) {
      pc_built = false;
      _depth.resize(0);
      _parent.resize(0);
      _children.resize(0);
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
    const auto& cld = tree.children(n);
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
    const auto& cld = tree.children(n);
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

// @@ !! LIM -- end mark --

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
  vector<int> _get_tecc;     // i = this.get_tecc(u) if u belongs to the i-th TECC
  bool built;
  
  bridge(int size) : llk(size), _tecc(0), _get_tecc(size), built(false) {}
  void add_edge(int u, int v) { llk.add_edge(u, v); }

  bool is_bridge(int u, int v) {
    if (u == v) return false;
    if (llk.ord(u) > llk.ord(v)) swap(u, v);
    bool b = llk.low(v) > llk.ord(u);
    DLOGKL("  is_bridge", u, v, b, llk.ord(u), llk.ord(v), llk.low(v));
    return b;
  }

  void build() {
    if (built) return;
    built = true;
    llk.build();
    auto visited = vector(llk.size, false);
    for (int r = 0; r < llk.size; r++) {
      if (not visited[r]) {
        DLOGK(r);
        auto comp = vector<int>();
        auto dfs = [&](auto rF, int u) -> void {
          if (visited[u]) return;
          visited[u] = true;
          comp.push_back(u);
          for (int v : llk.children[u]) {
            DLOGK(v, is_bridge(u, v));
            if (not is_bridge(u, v)) rF(rF, v);
          }
        };
        dfs(dfs, r);
        DLOGK(r, comp);
        for (int u : comp) _get_tecc[u] = _tecc.size();
        _tecc.push_back(move(comp));
      }
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

  int get_tecc(int u) {
    if (not built) build();
    return _get_tecc[u];
  }

  vector<pair<int, int>> tecc_edges() {
    if (not built) build();
    vector<pair<int, int>> ret;
    for (int u = 0; u < llk.size; u++) {
      for (int v : llk.children[u]) if (is_bridge(u, v)) ret.emplace_back(get_tecc(u), get_tecc(v));
    }
    return ret;
  }

};


struct articulation {
  lowlink llk;
  vector<bool> is_root;
  vector<vector<int>> bcc; // BiConnected Component
  vector<pair<int, int>> bctree_nodes; // Block Cut Tree nodes.  (0, i) ... articulation, (1, j) ... component
  vector<int> bctree_nid_art;  // bctree_nodes[x] = <0, u>  <=>  bctree_nid_art[u] = x
  vector<int> bctree_nid_comp;  // bctree_nodes[x] = <1, c>  <=>  bctree_nid_comp[c] = x;
  // bcc and bctree_nid_comp has the same size.  bctree_nid_comp[c] is the BCtree id for bcc[c].
  vector<pair<int, int>> bctree_edges; // Block Cut Tree edges.
  bool built;

  articulation(int size) : llk(size), is_root(size), bcc(0), bctree_nodes(0),
                           bctree_nid_art(size, -1), bctree_nid_comp(0), bctree_edges(0), built(false) {}
  
  void add_edge(int u, int v) { llk.add_edge(u, v); }

  void _bctree_add_art(int u) {
    ll x = bctree_nodes.size();
    bctree_nodes.emplace_back(0, u);
    bctree_nid_art[u] = x;
  }

  int _bctree_add_comp() {
    ll x = bctree_nodes.size();
    ll c = bcc.size();
    assert(c == (int)bctree_nid_comp.size());
    bctree_nodes.emplace_back(1, c);
    bcc.push_back(vector<int>());
    bctree_nid_comp.push_back(x);
    return c;
  }

  void _bctree_add_edge(int u, int c) {
    ll nid_a = bctree_nid_art[u];
    ll nid_c = bctree_nid_comp[c];
    bctree_edges.emplace_back(nid_a, nid_c);
  }

  void build() {
    if (built) return;
    built = true;
    llk.build();
    for (int u : llk.roots) is_root[u] = true;
    for (int rt : llk.roots) {
      vector<pair<int, int>> yet;
      if (llk.children[rt].size() >= 2) _bctree_add_art(rt);
      for (int u : llk.children[rt]) yet.emplace_back(rt, u);
      while (not yet.empty()) {
        auto [pt, cld] = yet.back(); yet.pop_back();
        int compidx = _bctree_add_comp();
        if (bctree_nid_art[pt] >= 0) _bctree_add_edge(pt, compidx);
        bcc[compidx].push_back(pt);
        auto dfs = [&](auto rF, int u) -> void {
          bcc[compidx].push_back(u);
          bool is_art_u = false;
          for (int v : llk.children[u]) {
            if (llk.low(v) >= llk.ord(u)) {
              is_art_u = true;
              yet.emplace_back(u, v);
            }
            else rF(rF, v);
          }
          if (is_art_u) {
            _bctree_add_art(u);
            _bctree_add_edge(u, compidx);
          }
        };
        dfs(dfs, cld);
      }
    }
  }

  bool is_articulation(int u) {
    if (not built) build();
    return bctree_nid_art[u] >= 0;
  }

};


void test1() {
  articulation au(10);
  au.add_edge(0, 1);
  au.add_edge(1, 2);
  au.add_edge(1, 6);
  au.add_edge(2, 3);
  au.add_edge(2, 4);
  au.add_edge(2, 5);
  au.add_edge(6, 7);
  au.add_edge(6, 8);
  au.add_edge(8, 9);
  au.add_edge(5, 1);
  au.add_edge(8, 1);
  au.add_edge(9, 0);

  au.build();

  DLOGK(au.llk._ord);
  DLOGK(au.llk._low);
  DLOGK(au.bcc);
  DLOGK(au.bctree_nodes);
  DLOGK(au.bctree_edges);
}

void test2() {
  bridge bu(10);
  bu.add_edge(0, 1);
  bu.add_edge(1, 2);
  bu.add_edge(1, 6);
  bu.add_edge(2, 3);
  bu.add_edge(2, 4);
  bu.add_edge(2, 5);
  bu.add_edge(6, 7);
  bu.add_edge(6, 8);
  bu.add_edge(8, 9);
  bu.add_edge(5, 1);
  bu.add_edge(8, 1);
  bu.add_edge(9, 0);

  bu.build();

  DLOGK(bu.llk._ord);
  DLOGK(bu.llk._low);
  DLOGK(bu._tecc);
  DLOGK(bu.tecc_edges());
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);


  /*
  test1();
  test2();
  */
  
  ll N, M; cin >> N >> M;
  ll A, B, C; cin >> A >> B >> C; A--; B--; C--;
  articulation au(N);
  REP(i, 0, M) {
    ll u, v; cin >> u >> v; u--; v--;
    au.add_edge(u, v);
  }
  au.build();
  ll sz = au.bctree_nodes.size();
  ll node_a, node_b, node_c;
  REP(i, 0, SIZE(au.bcc)) {
    for (ll j : au.bcc[i]) {
      if (j == A) node_a = au.bctree_nid_comp[i];
      if (j == B) node_b = au.bctree_nid_comp[i];
      if (j == C) node_c = au.bctree_nid_comp[i];
    }
  }
  if (au.bctree_nid_art[A] >= 0) node_a = au.bctree_nid_art[A];
  if (au.bctree_nid_art[B] >= 0) node_b = au.bctree_nid_art[B];
  if (au.bctree_nid_art[C] >= 0) node_c = au.bctree_nid_art[C];

  Tree tr(sz, node_b);
  for (auto [a, b] : au.bctree_edges) {
    tr.add_edge(a, b);
  }
  if (tr.lca(node_a, node_c) == node_b) cout << "Yes\n";
  else cout << "No\n";
  

  return 0;
}

