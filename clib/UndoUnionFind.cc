#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  UnionFind with Undo operations

  see https://yamate11.github.io/blog/posts/2024/01-01-undo-union-fild/

*/

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()    ---- UndoUnionFind.cc

struct UndoUnionFind {
  int size;
  vector<int> _parent;
  vector<int> _gsize;
  vector<pair<int, int>> _history;

  UndoUnionFind(int size_) : size(size_), _parent(size), _gsize(size, 1), _history() {
    iota(_parent.begin(), _parent.end(), 0);
  }

  int leader(int i) {
    for (; _parent[i] != i; i = _parent[i]);
    return i;
  }

  int gsize(int i) { return _gsize[i]; }

  int merge(int i, int j) {
    int x = leader(i);
    int y = leader(j);
    if (x == y) {
      _history.emplace_back(-1, -1);
      return x;
    }else {
      if (_gsize[x] < _gsize[y]) swap(x, y);
      _history.emplace_back(y, x);
      _parent[y] = x;
      _gsize[x] += _gsize[y];
      return x;
    }
  }

  void undo() {
    if (_history.empty()) { throw runtime_error("UndoUnionFInd: Fatal.  Empty history stack."); }
    auto [y, x] = _history.back(); _history.pop_back();
    if (y >= 0) {
      _parent[y] = y;
      _gsize[x] -= _gsize[y];
    }
  }
};

// @@ !! END ---- UndoUnionFind.cc
