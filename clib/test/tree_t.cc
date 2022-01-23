#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

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


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<TreeEdge> edge1({{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}});
  Tree t1(7, edge1);
  assert(t1.nnpath(1, 2) == vector<int>({1,0,2}));
  assert(t1.nnpath(3, 2) == vector<int>({3,1,0,2}));
  assert(t1.nnpath(6, 0) == vector<int>({6,2,0}));
  assert(t1.nnpath(4, 2) == vector<int>({4,1,0,2}));
  assert(t1.nnpath(2, 4) == vector<int>({2,0,1,4}));

  Tree t2(3);
  t2.add_edge(0, 1);
  t2.add_edge(0, 2);
  assert(t2.edgeIdx(0,1) == 0);
  assert(t2.edgeIdx(2,0) == 1);

  vector<TreeEdge>
    edge3({{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7},
	   {6,8}, {3,9}, {9,10}, {0,11}, {11,12}, {11,13}});
  Tree t3(14, edge3);
  assert(t3.nnpath(1,5) == vector<int>({1,2,3,4,5}));
  assert(t3.nnpath(7,2) == vector<int>({7,6,5,4,3,2}));
  for (int i = 0; i <=7; i++) assert(t3.ancestorDep(7,i) == i);
  assert(t3.lca(7,8) == 6);
  assert(t3.lca(8,13) == 0);
  assert(t3.lca(7,10) == 3);
  assert(t3.diameter() == 9);

  vector<TreeEdge>
    edge4({{0,1}, {1,2}, {3,4}, {0,3}, {3,5}, {6,7}, {6,8}, {6,1}});
  Tree t4(9, edge4);
  auto sub4 = [](Tree t, int i)  {
    auto v = t.child(i);
    return set<int>(v.begin(), v.end());
  };
  assert(sub4(t4, 0) == set<int>({1,3}));
  assert(sub4(t4, 1) == set<int>({2,6}));
  assert(sub4(t4, 3) == set<int>({4,5}));
  assert(sub4(t4, 6) == set<int>({7,8}));
  assert(sub4(t4, 8) == set<int>());
  assert(t4.parent(0) == -1);
  assert(t4.parent(1) == 0);
  assert(t4.parent(2) == 1);
  assert(t4.parent(6) == 1);
  assert(t4.parent(8) == 6);

  // The length of the longest simple path that goes through the node
  using T5 = pair<ll, ll>;
  vector<TreeEdge> edge5({{0,1}, {0,2}, {0,3}, {1,4}, {1,5}, {2,6}, {2,7}});
  vector<ll> len5({10,6,3,5,3,2,1});
  Tree t5(8, edge5);
  auto add5 = [&](T5 p1, T5 p2) -> T5 {
    ll a1 = p1.first;
    ll a2 = p2.first;
    if (a1 < a2) swap(a1, a2);
    if (a2 < p1.second) a2 = p1.second;
    if (a2 < p2.second) a2 = p2.second;
    return make_pair(a1, a2);
  };
  auto mod5 = [&](T5 p, ll n, ll c) -> T5 {
    return make_pair(p.first + len5[t5.edgeIdx(n,c)], 0);
  };
  auto v5 = reroot(t5, make_pair(0, 0), add5, mod5);
  vector<ll> ans5 = {23, 23, 23, 18, 23, 21, 23, 22};
  assert(t5.numNodes == 8);
  for (ll i = 0; i < t5.numNodes; i++) {
    assert(v5[i].first + v5[i].second == ans5[i]);
  }

  // ABC160-F
  using T6 = pair<ll, ll>;
  const T6 unitT6({0, 1});
  auto fact6 = [&](const auto& recF, ll n) -> ll {
    if (n == 0) return 1;
    return n * recF(recF, n-1);
  };
  auto add6 = [&](T6 tt1, T6 tt2) -> T6 {
    ll card1; ll perm1; tie(card1, perm1) = tt1;
    ll card2; ll perm2; tie(card2, perm2) = tt2;
    ll card = card1 + card2;
    ll perm = perm1 * perm2 * fact6(fact6, card)
                  / (fact6(fact6, card1) * fact6(fact6, card2));
    T6 ret = make_pair(card, perm);
    return ret;
  };
  auto mod6 = [&](T6 t, ll n, ll c) -> T6 {
    return make_pair(t.first + 1, t.second);
  };
  vector<TreeEdge> edge6({{0,1}, {1,2}, {2,3}, {2,4}, {2,5}, {5,6}, {5,7}});
                                // input No.4
  Tree t6(8);
  for (auto [x, y] : edge6) t6.add_edge(y, x);
  auto res6 = reroot(t6, unitT6, add6, mod6);
  vector<ll> ans6({40,280,840,120,120,504,72,72}); 
  assert(t6.numNodes = 8);
  for (ll i = 0; i < 8; i++) assert(res6[i].second == ans6[i]);

  // NJPC2017-E   https://njpc2017.contest.atcoder.jp/tasks/njpc2017_e
  vector<TreeEdge> edge7({{1,0},{2,1},{1,3},{3,4},{3,5},{6,5}});
  vector<ll> time({2,3,5,1,4,6});
  for (ll rt = 0; rt < 7; rt++) {
    Tree t7(7, edge7, rt);
    using T7 = pair<ll, ll>;
    const T7 unitT7 = make_pair(0, 0);
    auto  add7 = [&](const T7& tt1, const T7& tt2) -> T7 {
      ll top1, rev1; tie(top1, rev1) = tt1;
      ll top2, rev2; tie(top2, rev2) = tt2;
      return make_pair(max(top1, top2), rev1 + rev2);
    };
    auto mod7 = [&](const T7& t, ll n, ll c) -> T7 {
      ll eid = t7.edgeIdx(c, n);
      ll addRev = (edge7[eid].first == n) ? 1 : 0;
      return make_pair(t.first + time[eid], t.second + addRev);
    };
    auto res7 = reroot(t7, unitT7, add7, mod7);
    { ll x, z;
      tie(x, z) = res7[1]; assert(x == 15 && z == 4);
      tie(x, z) = res7[3]; assert(x == 10 && z == 3);
      tie(x, z) = res7[4]; assert(x == 11 && z == 2);
      tie(x, z) = res7[5]; assert(x == 12 && z == 2);
    }
  }


  cerr << "test done." << endl;
  return 0;
}

