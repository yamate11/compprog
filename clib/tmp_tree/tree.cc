#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Tree ...  rooted tree.  The nodes must be {0, 1, .., numNodes-1}

  members
    int numNodes;
    int root;
    bool pc_built;  // initially false.  set true when parent-children analysis finishes.
    vector<vector<int>> _nbr;
        // If (u, v) is an edge, then _nbr[u] has v and _nbr[v] has u.
    vector<int> _stsize;
    vector<int> _depth;
    vector<int> _parent;
    vector<vector<int>> _children;
    unordered_map<int, map<int, int>> _edge_idx;
    vector<vector<int>> pPnt;     // power parent
            // pPnt[0][n] == parent of n (or root if n is root)
            // pPnt[t][n] == parent^{2^t}(n)   (but parent(root) == root here, unlike the member function)
    vector<int> _edge_order;     
    vector<int> _inv_edge_order;
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
    int edge_idx(int x, int y)   // the edge index connecting x and y
                                 // if no such edge exists, -1 is returned.
    pair<int, int> nodesOfEdge(int e)  // the two nodes of the e-th edge.
    int euler_edge(int nd1, int nd2)   // The Euler Tour index of the edge from nd1 to nd2.
                                       // Use -1 for the imaginary edge to/from the root.
    int euler_in(int nd)               // The Euler Tour index of the edge to nd from its parent.
    int euler_out(int nd)              // The Euler Tour index of the edge from nd to its parent.
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

  struct pe_t {
    int peer;
    int edge;
    pe_t(int peer_ = -1, int edge_ = -1) : peer(peer_), edge(edge_) {}
    static const pe_t end_object;
  };

  struct nbr_t {
    int parent_idx;                 // pe[parent_idx] is the parent
    vector<pe_t> pe;
    nbr_t() : parent_idx(-1), pe() {}
  };

  template<bool get_peer>
  struct nbr_iterator {
    const nbr_t& body;
    int pe_idx;
    explicit nbr_iterator(const nbr_t& body_, int pe_idx_) : body(body_), pe_idx(pe_idx_) {
      if (pe_idx == body.parent_idx) pe_idx++;
    }
    auto operator*() const -> typename conditional<get_peer, int, const pe_t&>::type {
      if constexpr (get_peer) return body.pe[pe_idx].peer;
      else                    return body.pe[pe_idx];
    }
    const nbr_iterator& operator++() {
      pe_idx++;
      if (pe_idx == body.parent_idx) pe_idx++;
      return *this;
    }
    bool operator !=(const nbr_iterator& o) const { return pe_idx != o.pe_idx; }
  };

  template<bool get_peer>
  struct children_view {
    const nbr_t& body;
    children_view(const nbr_t& body_) : body(body_) {}
    nbr_iterator<get_peer> begin() const { return nbr_iterator<get_peer>(body, 0); }
    nbr_iterator<get_peer> end() { return nbr_iterator<get_peer>(body, std::ssize(body.pe)); }
  };

  int numNodes;
  int root;
  vector<nbr_t> _nbr;
  vector<pair<int, int>> _edges;   // (x, y) in _edges => x < y
  vector<int> _parent;             // _parent[root] == -1
  vector<int> _stsize;
  vector<int> _depth;
  unordered_map<int, unordered_map<int, int>> _edge_idx;
  vector<vector<int>> pPnt;   
          // pPnt[0][n] == parent of n (or root if n is root)
          // pPnt[t][n] == parent^{2^t}[n]
  // Euler Tour
  vector<int> _euler_in;
  vector<int> _euler_out;
  bool _node2edge_built = false;
  bool _euler_built = false;

  Tree(int numNodes_, int root_ = 0) : numNodes(numNodes_), root(root_), _nbr(numNodes_) {
    if (numNodes == 1) _set_parent();
  }

  // Implementation note:
  // Adding Tree(int, const vector<pair<int, int>>, int) is not a good idea.  If it were added,
  // Tree tr(n, x); would fail when x is long long.  You need to write Tree tr(n, (int)x), then.

  int add_edge(int x, int y) {
    int i = ssize(_edges);
    if (i >= numNodes - 1) throw range_error("add_edge");
    _nbr[x].pe.emplace_back(y, i);
    _nbr[y].pe.emplace_back(x, i);
    _edges.emplace_back(min(x, y), max(x, y));
    if (i + 1 == numNodes - 1) _set_parent();
    return i;
  }

  void _set_parent() {   // called from constructor, add_edge() and change_root()
    if (numNodes != ssize(_edges) + 1) throw range_error("_set_parent");
    _nbr[root].parent_idx = ssize(_nbr[root].pe);   // root does not have a parent.
    vector<tuple<int, int, int>> stack{{root, -1, -1}};
    while (not stack.empty()) {
      auto& [nd, cidx, pt] = stack.back();
      cidx++;
      if (cidx < ssize(_nbr[nd].pe)) {
        ll cld = _nbr[nd].pe[cidx].peer;
        if (cld == pt) _nbr[nd].parent_idx = cidx;
        else stack.emplace_back(cld, -1, nd);
      }else {
        stack.pop_back();
      }
    }
  }

  pe_t parent_pe(int nd) { return _nbr[nd].pe[_nbr[nd].parent_idx]; }
  int parent(int nd) { return nd == root ? -1 : parent_pe(nd).peer; }
  int num_children(int nd) { return _nbr[nd].pe.size() - (_nbr[nd].parent_idx == (int)_nbr[nd].pe.size() ? 0 : 1); }
  pe_t child_pe(int nd, int idx) { return _nbr[nd].pe[idx < _nbr[nd].parent_idx ? idx : idx + 1]; }
  int child(int nd, int idx) { return child_pe(nd, idx).peer; }
  int child_edge(int nd, int idx) { return child_pe(nd, idx).edge; }
  auto children_pe(int nd) { return children_view<false>(_nbr[nd]); }
  auto children(int nd) { return children_view<true>(_nbr[nd]); }

  int stsize(int nd0) {
    if (_stsize.empty()) {
      _stsize.resize(numNodes, 1);
      vector<pair<int, int>> stack{{root, -1}};
      while (not stack.empty()) {
        auto& [nd, cidx] = stack.back();
        cidx++;
        if (cidx < num_children(nd)) {
          stack.emplace_back(child(nd, cidx), -1);
        }else {
          if (nd != root) _stsize[parent(nd)] += _stsize[nd];
          stack.pop_back();
        }
      }
    }
    return _stsize[nd0];
  }

  int depth(int nd0) {
    if (_depth.empty()) {
      _depth.resize(numNodes);
      vector<pair<int, int>> stack{{root, -1}};
      while (not stack.empty()) {
        auto& [nd, cidx] = stack.back();
        if (cidx == -1) _depth[nd] = nd == root ? 0 : _depth[parent(nd)] + 1;
        cidx++;
        if (cidx < num_children(nd)) stack.emplace_back(child(nd, cidx), -1);
        else stack.pop_back();
      }
    }
    return _depth[nd0];
  }

  int edge_idx(int x, int y) {
    if (_edge_idx.empty()) {
      for (int i = 0; i < ssize(_edges); i++) {
        auto [xx, yy] = _edges[i];
        _edge_idx[xx][yy] = i;
        _edge_idx[yy][xx] = i;
      }
    }
    auto it = _edge_idx.find(x);
    if (it == _edge_idx.end()) return -1;
    auto it2 = it->second.find(y);
    if (it2 == it->second.end()) return -1;
    return it2->second;
  }

  pair<int, int> nodes_of_edge(int e) { return _edges[e]; }

  void _set_euler() {
    _euler_in.resize(numNodes);
    _euler_out.resize(numNodes);
    vector<pair<int, int>> stack{{root, -1}};
    int idx = 0;
    while (not stack.empty()) {
      auto& [nd, cidx] = stack.back();
      if (cidx == -1) _euler_in[nd] = idx++;
      cidx++;
      if (cidx < num_children(nd)) stack.emplace_back(child(nd, cidx), -1);
      else {
        _euler_out[nd] = idx++;
        stack.pop_back();
      }
    }
  }

  int euler_in(int nd) {
    if (_euler_in.empty()) _set_euler();
    return _euler_in[nd];
  }

  int euler_out(int nd) {
    if (_euler_out.empty()) _set_euler();
    return _euler_out[nd];
  }

  void preparePPnt() {
    if (not pPnt.empty()) return;
    vector<int> vec_parent(numNodes);
    for (int i = 0; i < numNodes; i++) vec_parent[i] = i == root ? i : parent(i);
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

  // Lowest Common Ancestor
  int lca(int x, int y) {
    if (depth(x) > depth(y)) swap(x, y);
    int dep = depth(x);
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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"    
  tuple<int, int, int, int, int> diameter() {
    if (numNodes == 1) return {0, 0, 0, 0, 0};
    if (numNodes == 2) return {1, 0, 1, 0, 1};
    depth(root);   // to ensure that _depth is correctly built
    int nd0 = max_element(_depth.begin(), _depth.end()) - _depth.begin();
    int nd1 = -1, ct0 = -1, ct1 = -1;
    int diam = 0;
    auto dfs2 = [&](auto rF, int nd, int dp, int pt) -> bool {
      // DFS from nd0, which is different from the root.
      bool ret = false;
      ll numChildren = 0;
      for (auto [cld, _e] : _nbr[nd].pe) {
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
    root = newRoot;
    _set_parent();
    _stsize.clear();
    _depth.clear();
    _edge_idx.clear();
    _euler_in.clear();
    _euler_out.clear();
    pPnt.clear();
  }

};

const Tree::pe_t end_object{-1, -1};

template <typename M>
auto reroot(Tree& tree, const M& unit, auto add, auto mod1, auto mod2) {
  using A = decltype(mod2(M(), 0));
  vector<A> result(tree.numNodes);
  vector<vector<M>> sum_left(tree.numNodes);
  vector<vector<M>> sum_right(tree.numNodes);
  
  auto dfs1 = [&](const auto& recF, int nd) -> A {
    int k = tree.num_children(nd);
    vector<M> ws(k);
    for (int i = 0; i < k; i++) {
      int c = tree.child(nd, i);
      ws[i] = mod1(recF(recF, c), nd, c);
    }
    sum_left[nd].resize(k + 1, unit);
    sum_right[nd].resize(k + 1, unit);
    for (int i = 0; i < k; i++) sum_left[nd][i + 1] = add(sum_left[nd][i], ws[i]);
    for (int i = k - 1; i >= 0; i--) sum_right[nd][i] = add(sum_right[nd][i + 1], ws[i]);
    return mod2(sum_right[nd][0], nd);
  };
  dfs1(dfs1, tree.root);

  auto dfs2 = [&](const auto& recF, int nd, const M& t) -> void {
    result[nd] = mod2(add(sum_right[nd][0], t), nd);
    int k = tree.num_children(nd);
    for (int i = 0; i < k; i++) {
      int c = tree.child(nd, i);
      M excl_c = add(sum_left[nd][i], sum_right[nd][i + 1]);
      M m_for_c = add(excl_c, t);
      A v_for_c = mod2(m_for_c, nd);
      M pass_c = mod1(v_for_c, c, nd);
      recF(recF, c, pass_c);
    }
  };
  dfs2(dfs2, tree.root, unit);
  
  return result;
}

template <typename M>
vector<M> reroot(Tree& tree, const M& unit, auto add, auto mod1) {
  return reroot<M>(tree, unit, add, mod1, [](const M& m, int i) -> M { return m; });
}

// @@ !! END() ---- tree.cc
