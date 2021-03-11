#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(tree tree)
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
    parent.resize(numNodes);
    child.resize(numNodes);
    depth.resize(numNodes);
    for (int i = 0; i < numNodes - 1; i++) {
      Edge e = edge.at(i);
      child.at(e.first).push_back(e.second);
      child.at(e.second).push_back(e.first);
    }
    auto dfs = [&](const auto& recF, int n, int p, int l) -> void {
      parent.at(n) = p;
      depth.at(n) = l;
      int ip = -1;
      auto& vecC = child.at(n);
      int numC = vecC.size();
      for (int i = 0; i < numC; i++) {
	int c = vecC.at(i);
	if (c == p) ip = i;
	else        recF(recF, c, n, l+1);
      }
      if (n != root) {
	if (ip < numC - 1) swap(vecC.at(ip), vecC.at(numC - 1));
	vecC.resize(numC - 1);
      }
    };
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

  map<int, map<int, int>> __node2edgeID;

public:
  int numNodes;
  int root;
  vector<int> parent;   // parent.at(root) == root
  vector<vector<int>> child;
  vector<int> depth;
  vector<Edge> edge;

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

  int node2edgeID(int n1, int n2) {
    if (__node2edgeID.empty()) {
      for (ll i = 0; i < numNodes - 1; i++) {
	Edge e = edge.at(i);
	__node2edgeID[e.first][e.second] = i;
	__node2edgeID[e.second][e.first] = i;
      }
    }
    auto it1 = __node2edgeID.find(n1);
    if (it1 == __node2edgeID.end()) return -1;
    auto it2 = it1->second.find(n2);
    if (it2 == it1->second.end()) return -1;
    return it2->second;
  }
  Edge node2edge(int n1, int n2) { return edge.at(node2edgeID(n1, n2)); }
  

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"    
  // diameter
  //   not efficient at all.  fixed-rooted tree is not suitable....
  int diameter() {
  // tuple<int, int, int> diameter() {
    int maxDepth = 0;
    int mdArg1 = -1;
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

  ll N; cin >> N;
  vector<Edge> ve;
  for (ll i = 0; i < N-1; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    ve.emplace_back(a, b);
  }
  Tree tr(move(ve));
  vector<ll> nEven, nOdd;
  for (ll i = 0; i < N; i++) {
    if (tr.depth.at(i) % 2 == 0) nEven.push_back(i);
    else nOdd.push_back(i);
  }
  vector<ll> ans(N);
  auto ass1 = [&](ll i, ll& p) -> bool {
    if (p <= N) {
      ans.at(i) = p;
      p += 3;
      return true;
    }else {
      return false;
    }
  };
  ll n0 = 3, n1 = 1, n2 = 2;
  if ((ll)nEven.size() <= N / 3) {
    for (ll i : nEven) ass1(i, n0);
    for (ll i : nOdd)  ass1(i, n0) || ass1(i, n1) || ass1(i, n2);
  }else if ((ll)nOdd.size() <= N / 3) {
    for (ll i : nOdd)  ass1(i, n0);
    for (ll i : nEven)  ass1(i, n0) || ass1(i, n1) || ass1(i, n2);
  }else {
    for (ll i : nEven) ass1(i, n1) || ass1(i, n0);
    for (ll i : nOdd)  ass1(i, n2) || ass1(i, n0);
  }
  for (ll i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << ans.at(i);
  }
  cout << endl;
  return 0;
}

