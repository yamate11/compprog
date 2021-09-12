#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
   SCC ... strongly connected component
                    This employs Tarjan's algorithm.

   Usage:
     ll N; cin >> N;
     SCC scc(N);     // argument is the number of nodes.  
     for (ll i = 0; i < M; i++) {
       ll x, y; cin >> x, y; x--; y--;   // nodes should be 0-indexed.
       scc.addEdge(x, y);
     }
     scc.build();    // optional (will be lazily built even if omitted)
     // Now you can call:
     ll sz = scc.numComp(); // number of components
     ll nd = some arbitarily node...
     ll ccid = scc.ccForNode(nd);  // component that nd belongs to
     const vector<int>& nodes = scc.nodesInCC(ccid);
                            // vector of nodes in component ccid
     assert(nodes.find(nd) != nodes.end());  // should hold
     // CCIDs are topologically sorted IN REVERSE ORDER.
     scc.edge_build();  // optional (will be lazily built even if omitted)
     // Now you can call:
     const vector<int>& fwds = scc.cFwd(ccid);
                        // successors in the DAG of sccs
     // for all elelment f of fwds, ccid > f holds. (reverse top. order)
     const vector<int>& bwds = scc.cBwd(ccid);
                        // predecessors in the DAG of sccs

   APIs:
     SCC(int size)                            constructor
           Original nodes should be {0, .., size-1}
     void addEdge(int from, int to)           adds an edge
     void build()                             (optional)
     void edge_build()                        (optional)
     int numComp()                            number of SCCs
     int ccForNode(int nd)                    ID of SCC which nd belongs to
     const vector<int>& nodesInCC(int ccid)   nodes in SCC ccid
     const vector<int>& cFwd(int ccid)        successor SCCs of ccid
     const vector<int>& cBwd(int ccid)        predecessor SCCs of ccid
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- scc.cc

template<typename E>
struct CSR {  // Compressed Sparse Row
  int size;
  vector<int> start;
  vector<E> es;
  vector<pair<int, E>> tmp;
  CSR(int size_) : size(size_), start(size + 1) {}
  void add(int i, const E& e) { tmp.emplace_back(i, E(e)); }
  void add(int i, E&& e) { tmp.emplace_back(i, e); }
  void build() {
    vector<int> num(size);
    int tot = 0;
    for (auto& [i, e] : tmp) {
      num[i]++;
      tot++;
    }
    es.resize(tot);
    for (int i = 0; i < size; i++) start[i+1] = start[i] + num[i];
    for (auto& [i, e] : tmp) {
      es[start[i + 1] - num[i]] = move(e);
      num[i]--;
    }
  }
};

struct SCC {
  int size;

  CSR<int> csr;

  vector<int> _ccForNode;
  int ccForNode(int nd) {
    if (!built) build();
    return _ccForNode[nd];
  }

  vector<vector<int>> _nodesInCC;
  const vector<int>& nodesInCC(int ccid) {
    if (!built) build();
    return _nodesInCC[ccid];
  }

  int numComp() {
    if (! built) build();
    return _nodesInCC.size();
  }

  vector<vector<int>> _cFwd;
  const vector<int>& cFwd(int ccid) {
    if (!edge_built) edge_build();
    return _cFwd[ccid];
  }

  vector<vector<int>> _cBwd;
  const vector<int>& cBwd(int ccid) {
    if (!edge_built) edge_build();
    return _cBwd[ccid];
  }

  // true if sccs have built
  bool built;

  // true if edges between sccs have built
  bool edge_built;

  SCC(int sz) : size(sz), csr(size), _ccForNode(sz), 
                built(false), edge_built(false) {}

  void addEdge(int from, int to) { csr.add(from, to); }

  void build() {
    if (built) return;
    built = true;
    csr.build();
    int idx = 0;
    vector<int> stack;
    vector<int> index(size, -1);
    vector<int> lowlink(size);
    vector<bool> onstack(size, false);
    auto dfs = [&](auto rF, int i) -> void {
      // DLOGKL("dfs", i);
      index[i] = idx;
      lowlink[i] = idx;
      idx++;
      stack.push_back(i);
      onstack[i] = true;
      for (int k = csr.start[i]; k < csr.start[i + 1]; k++) {
        int j = csr.es[k];
        if (index[j] < 0) {
          rF(rF, j);
          lowlink[i] = min(lowlink[i], lowlink[j]);
        }else if (onstack[j]) {
          lowlink[i] = min(lowlink[i], index[j]);
        }
      }
      // DLOGK(i, lowlink[i], index[i]);
      if (lowlink[i] == index[i]) {
        int ccid = _nodesInCC.size();
        _nodesInCC.resize(ccid + 1);
        vector<int>& cc = _nodesInCC[ccid];
        while (true) {
          int j = stack.back(); stack.pop_back();
          onstack[j] = false;
          cc.push_back(j);
          _ccForNode[j] = ccid;
          if (j == i) break;
        }
      }
    };
    for (int i = 0; i < size; i++) if (index[i] < 0) dfs(dfs, i);
  }

  void edge_build() {
    if (edge_built) return;
    edge_built = true;
    if (!built) build();
    int sz = _nodesInCC.size();
    _cFwd.resize(sz);
    _cBwd.resize(sz);
    for (int icc = 0; icc < sz; icc++) {
      vector<bool> tmp(sz);
      for (int i : _nodesInCC[icc]) {
        for (int k = csr.start[i]; k < csr.start[i + 1]; k++) {
          int j = csr.es[k];
          int jcc = _ccForNode[j];
          if (icc == jcc) continue;
          if (tmp[jcc]) continue;
          tmp[jcc] = true;
          _cFwd[icc].push_back(jcc);
          _cBwd[jcc].push_back(icc);
        }
      }
    }
  }
};

// @@ !! END ---- scc.cc
