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
    bool pc_built;  // initially false.  set true when parent-children analysis finishes.
    vector<vector<int>> _nbr;
        // If (u, v) is an edge, then _nbr[u] has v and _nbr[v] has u.
    vector<int> _stsize;
    vector<int> _depth;
    vector<int> _parent;
    vector<vector<int>> _children;
    unordered_map<int, map<int, int>> _node2edgeIdx;
    vector<vector<int>> pPnt;     // power parent
            // pPnt[0][n] == parent of n (or root if n is root)
            // pPnt[t][n] == parent^{2^t}(n)   (but parent(root) == root here, unlike the member function)
  constructors
    Tree(int numNodes_, int root_ = 0);
  member functions
    int add_edge(int x, int y);  // Adds an edge.  Returns the edge index.
    int parent(int x);           // parent(root) == -1
    const vector<int>& children(int x);
    int stsize(int x);           // the size of the subtree
    int depth(int x);
    int lca(int x, int y);   // lowest common ancestor    
    vector<int> nnpath(int x, int y)  // path (list of nodes) between x and y, inclusive.
    int ancestorDep(int x, int dep)   // the ancestor of x whose depth is dep
    int edgeIdx(int x, int y)    // the edge index connecting x and y
                                 // if no such edge exists, -1 is returned.
    pair<int, int> nodesOfEdge(int e)  // the two nodes of the e-th edge.
    tuple<int, int, int, int, int> diameter()
      // returns (diam, nd0, nd1, ct0, ct1).  diam is the length of the diameter.  
      // nd0 and nd1 are end points of diameter.  
      // ct0 and ct1 are the centers near nd1 and nd2 (if diam is even, ct0 == ct1).
    void change_root(int newRoot)  // change the root
  internal member functions
    void set_parent_child();
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
    
  Rerooting a tree (also see https://yamate11.github.io/blog/posts/2022/08-17-rerooting/)
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

// @@ !! END() ---- tree.cc
