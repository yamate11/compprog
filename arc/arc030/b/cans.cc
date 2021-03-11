#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(tree)
// --> tree
// ---- inserted library file tree.cc

class Tree {

  void init(auto fGet) {
    for (int i = 0; i < numNodes - 1; i++) {
      auto p = fGet(i);
      int x = p.first;
      int y = p.second;
      edge.push_back(p);
      node2edge[x][y] = i;
      node2edge[y][x] = i;
    }
    auto dfs = [&](const auto& recF, int n, int p, int l) -> void {
      parent.at(n) = p;
      depth.at(n) = l;
      for (auto c : node2edge[n]) {
	if (c.first == p) continue;
	child.at(n).push_back(c.first);
	recF(recF, c.first, n, l+1);
      }
    };
    parent.resize(numNodes);
    child.resize(numNodes);
    depth.resize(numNodes);
    dfs(dfs, root, -1, 0);
    parent.at(root) = root;
  }

  void preparePPnt() {
    pPnt.push_back(parent);
    for (int t = 0; true; t++) {
      bool done = true;
      vector<int> vec(numNodes);
      for (int n = 0; n < numNodes; n++) {
	int m = pPnt.at(t).at(n);
	vec.at(n) = pPnt.at(t).at(m);
	if (vec.at(n) != m) done = false;
      }
      pPnt.push_back(move(vec));
      if (done) break;
    }
  }

public:
  int numNodes;
  int root;
  vector<int> parent;   // parent.at(root) == root
  vector<vector<int>> child;
  vector<int> depth;
  vector<vector<int>> pPnt;   
  // pPnt.at(0) == parent
  // pPnt.at(t).at(n) == parent^{2^t}.at(n)
  vector<pair<int, int>> edge;
  map<int, map<int, int>> node2edge;

  enum CType { none, zero_indexed, one_indexed };

  // N ... the number of nodes
  // edges ... vector<integer, integer>.  Should be zero-indexed
  Tree(auto edges, int _root = 0) : numNodes(edges.size() + 1), root(_root) {
    auto getF = [&](int i) -> pair<int, int> { return edges[i]; };
    init(getF);
  }

  Tree(int N, istream& stream, CType mode = one_indexed)
    : numNodes(N), root(0) {
    if (mode == none) {
      cerr << "Sorry, not implemented.\n";
      assert(0);
    }
    auto getF = [&](int i) -> pair<int, int> {
      int x, y; stream >> x >> y;
      if (mode == one_indexed) { x--; y--; }
      return make_pair(x, y);
    };
    init(getF);
  }

  // Lowest Common Ancestor
  int lca(int x, int y) {
    if (depth.at(x) > depth.at(y)) swap(x, y);
    int dep = depth.at(x);
    int yy = ancestorDep(y, dep);
    if (x == yy) return x;
    int t = 0;
    for (int q = 1; q < dep; q *= 2) t++;
    for ( ; t >= 0; t--) {
      if (pPnt.at(t).at(x) != pPnt.at(t).at(yy)) {
	x = pPnt.at(t).at(x);
	yy = pPnt.at(t).at(yy);
      }
    }
    return parent.at(x);
  }

  // the path between two nodes
  vector<int> nnpath(int x, int y) {
    vector<int> ret, sub;
    int c = lca(x, y);
    for ( ; x != c; x = parent.at(x)) ret.push_back(x);
    for ( ; y != c; y = parent.at(y)) sub.push_back(y);
    ret.push_back(c);
    for (int i = sub.size() - 1; i >= 0; i--) ret.push_back(sub.at(i));
    return ret;
  }

  // the ancestor of n whose depth is dep
  int ancestorDep(int n, int dep) {
    if (pPnt.size() == 0) preparePPnt();
    int diff = depth.at(n) - dep;
    assert(diff >= 0);
    for (int t = 0; diff > 0; t++) {
      if (diff & (1 << t)) {
	n = pPnt.at(t).at(n);
	diff ^= (1 << t);
      }
    }
    return n;
  }

};
// ---- end tree.cc
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X; cin >> N >> X; X--;
  vector<ll> H(N);
  for (ll i = 0; i < N; i++) cin >> H.at(i);
  vector<pair<ll, ll>> ab(N-1);
  for (ll i = 0; i < N-1; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    ab.at(i) = make_pair(a, b);
  }
  Tree tr(ab, X);
  
  auto dfs = [&](const auto& recF, ll n) -> ll {
    ll tot = 0;
    for (ll c : tr.child.at(n)) {
      ll z = recF(recF, c);
      if (z >= 0) tot += 2 + z;
    }
    if (tot > 0) return tot;
    if (H.at(n)) return 0;
    return -1;
  };
  ll val = dfs(dfs, X);
  cout << (val > 0 ? val : 0) << endl;

  return 0;
}

