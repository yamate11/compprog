#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;

/*
  Functional Graph

  Usage:

    ll N; cin >> N;
    FuncGraph fg(N);
    for (ll i = 0; i < N; i++) {
      int a; cin >> a; a--;
      fg.add_edge(i, a);
    }
    fg.build();  // optional

    numcc = fg.numcc();        // the number of connected components
    ccid = fg.ccid(i);         // the seq number of the connected component containing node i
    sz1 = fg.cc_size(i);       // the size of the connected component containing i
    sz2 = fg.cycle_size(i);    // the size of the cycle that is reachable from i
    nd = fg.node_on_cycle(i);  // the first node on the cycle in the trajectory beginning with i
    flag = fg.is_on_cycle(i);  // true if i is on a cycle
    len = fg.dist_to_cycle(i);  // the distance to the cycle
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()    ---- FuncGraph.cc

struct FuncGraph {
  int size;
  vector<int> fwd;
  vector<int> _cc;
  vector<int> _cc_size;
  vector<int> _cycle_size;
  vector<int> _on_cycle;
  vector<int> _dp;
  bool _built;

  FuncGraph(int size_) : size(size_), fwd(size), _cc(size, -1), _cc_size(), _cycle_size(),
                         _on_cycle(size), _dp(size, -1), _built(false) {}

  void add_edge(int i, int j) {
    fwd[i] = j;
  };

  int _set_depth(int i) {
    if (_dp[i] < 0) {
      if (_on_cycle[i] == i) _dp[i] = 0;
      else _dp[i] = _set_depth(fwd[i]) + 1;
    }
    return _dp[i];
  }

  void build() {
    if (_built) throw runtime_error("FuncGraph: built() should be called at most once.");
    for (int i = 0; i < size; i++) {
      if (_cc[i] < 0) {
        int tmpidx = _cc_size.size();
        vector<int> stack;
        int k;
        for (k = i; _cc[k] < 0; k = fwd[k]) {
          _cc[k] = tmpidx;
          stack.push_back(k);
        }
        if (_cc[k] == tmpidx) {
          _cc_size.push_back(stack.size());
          bool on = true;
          while (not stack.empty()) {
            int m = stack.back(); stack.pop_back();
            _on_cycle[m] = on ? m : k;
            if (m == k) {
              _cycle_size.push_back(_cc_size[tmpidx] - stack.size());
              on = false;
            }
          }
        }else {
          _cc_size[_cc[k]] += stack.size();
          while (not stack.empty()) {
            int m = stack.back(); stack.pop_back();
            _on_cycle[m] = _on_cycle[k];
            _cc[m] = _cc[k];
          }
        }
      }
    }
    for (int i = 0; i < size; i++) _set_depth(i);
    _built = true;
  }

  int numcc() {
    if (not _built) build();
    return (int)_cc_size.size();
  }

  int ccid(int i) {
    if (not _built) build();
    return _cc[i];
  }

  int cc_size(int i) {
    if (not _built) build();
    return _cc_size[ccid(i)];
  }

  int cycle_size(int i) {
    if (not _built) build();
    return _cycle_size[ccid(i)];
  }

  int node_on_cycle(int i) {
    if (not _built) build();
    return _on_cycle[i];
  }

  bool is_on_cycle(int i) {
    if (not _built) build();
    return _dp[i] == 0;
  }

  int dist_to_cycle(int i) {
    return _dp[i];
  }

};

// @@ !! END ---- FuncGraph.cc
