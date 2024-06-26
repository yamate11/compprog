#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(tree)
// --> f:updMaxMin tree
// ---- inserted function updMaxMin from util.cc
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
// ---- end updMaxMin
// ---- inserted library file tree.cc

class Edge : public pair<int, int> {
public:
  Edge() : pair<int, int>() {}
  Edge(const int& x, const int& y) : pair<int, int>(x, y) {}
  Edge(istream& stream, int shift) {
    stream >> this->first >> this->second;
    this->first -= shift;
    this->second -= shift;
  }
};

class Tree {

  void init() {
    numNodes = edge.size() + 1;
    for (int i = 0; i < numNodes - 1; i++) {
      Edge e = edge.at(i);
      node2edge[e.first][e.second] = node2edge[e.second][e.first] = i;
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

  vector<vector<int>> pPnt;   
          // pPnt.at(0) == parent
          // pPnt.at(t).at(n) == parent^{2^t}.at(n)
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
  vector<Edge> edge;
  map<int, map<int, int>> node2edge;

  Tree(vector<Edge>&& edge_, int root_ = 0) : root(root_), edge(move(edge_)) {
    init();
  }

  Tree(const auto& edge_, int root_ = 0) : root(root_), edge() {
    for (Edge e : edge_) edge.push_back(e);
    init();
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

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"    
  // diameter
  //   not efficient at all.  fixed-rooted tree is not suitable....
  int diameter() {
  // tuple<int, int, int> diameter() {
    int maxDepth = 0;
    int mdArg1;
    for (int i = 0; i < numNodes; i++) {
      if (updMax(maxDepth, depth.at(i))) mdArg1 = i;
    }
    Tree tr2(edge, mdArg1);
    maxDepth = 0;
    int mdArg2;
    for (int i = 0; i < numNodes; i++) {
      if (updMax(maxDepth, tr2.depth.at(i))) mdArg2 = i;
    }
    // Return mdArg1 and mdArg2 if you need endpoints as well.
    // return make_tuple(maxDepth, mdArg1, mdArg2);
    return maxDepth;
  }
};
#pragma GCC diagnostic pop

// ---- end tree.cc
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  vector<Edge> ve;
  vector<ll> C;
  vector<ll> D;
  for (ll i = 0; i < N-1; i++) {
    ll a, b, c, d; cin >> a >> b >> c >> d; a--; b--;
    ve.emplace_back(a, b);
    C.push_back(c);
    D.push_back(d);
  }
  Tree tr(ve);
  vector<ll> X, Y, U, V;
  vector<set<ll>> qInfo(N);
  for (ll i = 0; i < Q; i++) {
    ll x, y, u, v; cin >> x >> y >> u >> v; u--; v--;
    X.push_back(x);
    Y.push_back(y);
    U.push_back(u);
    V.push_back(v);
    ll w = tr.lca(u, v);
    qInfo.at(u).insert(x);
    qInfo.at(v).insert(x);
    qInfo.at(w).insert(x);
  }
  vector<ll> numCols(N);
  vector<ll> distCols(N);
  vector<ll> origDist(N);
  ll origD = 0;
  vector<map<ll, pair<ll, ll>>> aInfo(N);
  auto setDat = [&](const auto& recF, ll n) -> void {
    for (ll x : qInfo.at(n)) {
      origDist.at(n) = origD;
      aInfo.at(n)[x] = make_pair(numCols.at(x), distCols.at(x));
    }
    for (ll c : tr.child.at(n)) {
      ll e = tr.node2edge.at(n).at(c);
      ll ec = C.at(e);
      ll ed = D.at(e);
      origD += ed;
      numCols.at(ec)++;
      distCols.at(ec) += ed;
      recF(recF, c);
      origD -= ed;
      numCols.at(ec)--;
      distCols.at(ec) -= ed;
    }
  };
  setDat(setDat, 0);
  for (ll i = 0; i < Q; i++) {
    ll x = X.at(i);
    ll y = Y.at(i);
    ll u = U.at(i);
    ll v = V.at(i);
    ll w = tr.lca(u, v);
    ll uN, uD; tie(uN, uD) = aInfo.at(u).at(x);
    ll vN, vD; tie(vN, vD) = aInfo.at(v).at(x);
    ll wN, wD; tie(wN, wD) = aInfo.at(w).at(x);
    ll num = uN + vN - 2 * wN;
    ll dist = uD + vD - 2 * wD;
    ll oDist = origDist.at(u) + origDist.at(v) - 2 * origDist.at(w);
    cout << oDist - dist + y * num << endl;
  }

  return 0;
}

