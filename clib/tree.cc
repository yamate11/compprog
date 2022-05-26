#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Tree ...  rooted tree.  The nodes must be {0, 1, .., numNodes-1}

  members
    int numNodes;
    int root;
    int numEdges;   // must be (numNodes - 1) once the initial construction finishes
    bool good_nbr;  // initially false.  set true when parent-children analysis finishes.
    vector<vector<int>> _nbr;
        // If (u, v) is the idx-th edge, then _nbr[u] has v and _nbr[v] has u.
        // When good_nbr is true, then _nbr[u][0] is the parent.  (_nbr[root][0] is -1)
    vector<int> _depth;
    unordered_map<int, map<int, int>> _node2edgeIdx;
    vector<vector<int>> pPnt;     // power parent
            // pPnt[0][n] == parent of n (or root if n is root)
            // pPnt[t][n] == parent^{2^t}(n)   (but parent(root) == root here, unlike the member function)
  constructors
    Tree(int numNodes_, int root_ = 0);
    Tree(int numNodes_, const auto& edge_, int root_ = 0);
  member functions
    int add_edge(int x, int y);  // Adds an edge.  Returns the edge index.
    int parent(int x);           // parent(root) == -1
    vector<int> child(int x);
    int depth(int x);
    int lca(int x, int y);   // lowest common ancestor    
    vector<int> nnpath(int x, int y)  // path (list of nodes) between x and y, inclusive.
    int acestorDep(int x, int dep)   // the ancestor of x whose depth is dep
    int edgeIdx(int x, int y)    // the edge index connecting x and y
                                 // if no such edge exists, -1 is returned.
    Edge node2edge(int x, int y)   // the edge connecting x and y
                                   // the edge should exist.
    int diameter()           // diameter
  internal member functions
    void set_parent_child();  // change the order of _nbr so that _nbr[u][0] is the parent of u.  Also good_nbr := true
                              // Note that _nbr[root][0] == -1
    void preparePPnt();       // sets vector pPnt for lca etc


  Typical usage:

    ll N, root; cin >> N >> root;
    Tree tr(N, root);
    for (ll i = 0; i < N-1; i++) {
      ll a, b; cin >> a >> b; a--; b--;
      tr.add_edge(a, b);
    }
    auto dfs = [&](const auto& recF, ll n) -> T {
      do_something();
      for (ll c : tr.child(n)) {
        T t = recF(recF, c);
	...
      }
    };
    dfs(dfs, tr.root);
    
  Rerooting a tree.  
    Let C^n_i be the set of children of node i where the root node is n.
    Let us also assume that some value v[n] of type T is defined by:
      v[n] = v^n[n], 
         where v^n[m] = \sum_k { f(v^n[k], m, k) | k \in C^n_m }
               \sum is some commutative monoid operation.
               f :: T -> int -> int -> T
    A point is that v^n needs to be the result of monoid operation.
    Sometimes it is a bit strong assumption; but stick to the restriction,
    the final value you want can be obtained by applying some other function:
         g(v[n])

  Typical usage:
    int root = 0;
    Tree tree(numNodes);
    tree.add_edge(x, y); ....;
    using T = ...;
    const T unitT = ... ;
    auto add = [&](const T& t1, const T& t2) -> T { ... };
    // (T, add, unitT) is the monoid.
    auto mod = [&](const T& t, int node, int child) -> T { ... };
    // The value used at node when the value used at child is t
    vector<T> result = reroot(tree, unitT, add, mod);
    for (int i = 0; i < tr.numNodes; i++) 
      cout << result[i] << endl; // print answers

 */


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- tree.cc

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
  int diameter() {
    set_parent_child();
    ll nd0 = max_element(_depth.begin(), _depth.end()) - _depth.begin();
    auto dfs2 = [&](auto rF, int nd, int pt, int dp) -> int {
      int ret = 0;
      for (ll cld : _nbr[nd]) {
        if (cld < 0 or cld == pt) continue;
        ret = max(ret, 1 + rF(rF, cld, nd, dp + 1));
      }
      return ret;
    };
    return dfs2(dfs2, nd0, -1, 0);
  }
#pragma GCC diagnostic pop

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

// @@ !! END() ---- tree.cc
