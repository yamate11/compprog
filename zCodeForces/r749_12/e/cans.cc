#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(tree)

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

// ---- end tree.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<vector<ll>> nbr(N);
  REP(i, M) {
    ll x, y; cin >> x >> y; x--; y--;
    nbr[x].push_back(y);
    nbr[y].push_back(x);
  }
  ll Q; cin >> Q;
  vector A(Q, 0LL), B(Q, 0LL), cnt(N, 0LL);
  REP(q, Q) {
    ll a, b; cin >> a >> b; a--; b--;
    A[q] = a; B[q] = b;
    cnt[a]++;
    cnt[b]++;
  }
  ll cnt_odd = 0;
  REP(i, N) if (cnt[i] % 2 == 1) cnt_odd++;
  if (cnt_odd > 0) {
    cout << "NO\n";
    cout << cnt_odd / 2 << endl;
    return 0;
  }
  cout << "YES\n";
  Tree spt(N, 0);
  queue<ll> que;
  vector<bool> seen(N);
  seen[0] = true;
  que.push(0);
  while (not que.empty()) {
    ll t = que.front(); que.pop();
    for (ll x : nbr[t]) {
      if (seen[x]) continue;
      seen[x] = true;
      spt.add_edge(t, x);
      que.push(x);
    }
  }
  REP(q, Q) {
    auto path = spt.nnpath(A[q], B[q]);
    cout << SIZE(path) << "\n";
    for (ll j : path) cout << j + 1 << " ";
    cout << "\n";
  }


  return 0;
}

