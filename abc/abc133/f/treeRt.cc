#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Nodes must be numbered from 0 to numNodes-1
 */
class TreeRt {
  int _numNodes;
  int _root;
  vector<vector<int>> _nbr;
  vector<int> _parent;

  void dfs(int n, int p) {
    _parent.at(n) = p;
    for (int m : nbr.at(n)) {
      if (m == p) continue;
      dfs(m, n);
    }
  }

public:
  // Naturally, v1.size() == v2.size() == numNodes - 1
  TreeRt(const vector<int>& v1, const vector<int>& v2, int root)
    : _root(root), _numNodes(v1.size() + 1), _nbr(v1.size() + 1) {
    assert(v2.size() + 1 == _numNodes);
    for (int i = 0; i < _numNodes; i++) {
      nbr.at(v1.at(i)).push_back(v2.at(i));
      nbr.at(v2.at(i)).push_back(v1.at(i));
    }
    dfs(_root, _root);
  }

  int parent(int n) { return _parent.at(n); }

  vector<int> children(int n) {
    vector<int> ret;
    for (int m : _nbr.at(n)) {
      if (m == _parent.at(n)) continue;
      ret.push_back(m);
    }
    return ret;
  }

};


class TreeLCA : TreeRt {
  TreeLCA(const vector<int>& v1, const vector<int>& v2, int root)
    : TreeRt(v1, v2, root) {
    
  }
};

