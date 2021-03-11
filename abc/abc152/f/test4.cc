#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

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

  Tree(CType mode = one_indexed, auto& stream = cin) : root(0) {
    if (mode == none) {
      cerr << "Sorry, not implemented.\n";
      assert(0);
    }
    stream >> numNodes;
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


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<pair<int,int>> edge1({{0,1}, {0,2}, {1,3}, {1,4}, {2,5}, {2,6}});
  Tree t1(edge1);
  assert(t1.nnpath(1, 2) == vector<int>({1,0,2}));
  assert(t1.nnpath(3, 2) == vector<int>({3,1,0,2}));
  assert(t1.nnpath(6, 0) == vector<int>({6,2,0}));
  assert(t1.nnpath(4, 2) == vector<int>({4,1,0,2}));
  assert(t1.nnpath(2, 4) == vector<int>({2,0,1,4}));

  stringstream ss2("3\n1 2\n1 3\n");
  Tree t2(Tree::one_indexed, ss2);
  assert(t2.edge.at(1) == make_pair(0, 2));
  assert(t2.node2edge.at(0).at(1) == 0);
  assert(t2.node2edge.at(2).at(0) == 1);

  vector<pair<int,int>>
    edge3({{0,1}, {1,2}, {2,3}, {3,4}, {4,5}, {5,6}, {6,7},
	   {6,8}, {3,9}, {9,10}, {0,11}, {11,12}, {11,13}});
  Tree t3(edge3);
  assert(t3.nnpath(1,5) == vector<int>({1,2,3,4,5}));
  assert(t3.nnpath(7,2) == vector<int>({7,6,5,4,3,2}));
  for (int i = 0; i <=7; i++) assert(t3.ancestorDep(7,i) == i);
  assert(t3.lca(7,8) == 6);
  assert(t3.lca(8,13) == 0);
  assert(t3.lca(7,10) == 3);

  cerr << "test done." << endl;
  return 0;
}

