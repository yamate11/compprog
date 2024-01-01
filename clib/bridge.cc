/*
  bridge.cc 

  - Lowlink
  - Bridge and Two-edge connected component
  - Articulation point, Biconnected component, and Block-Cut Tree
  The library name might be misleading.  

  For description, see https://yamate11.github.io/blog/posts/2023/09-05-bridge/

 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()    ---- bridge.cc

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



// @@ !! END ---- bridge.cc
