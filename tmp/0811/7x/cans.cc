#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(scc)

// ---- inserted library file scc.cc

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

// ---- end scc.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  SCC scc(N);
  REP(i, M) {
    ll a, b; cin >> a >> b;
    scc.addEdge(a, b);
  }
  ll sz = scc.numComp();
  cout << sz << "\n";
  REP2R(i, sz - 1, 0) {
    const auto& ns = scc.nodesInCC(i);
    cout << SIZE(ns);
    for (ll j : scc.nodesInCC(i)) cout << " " << j;
    cout << "\n";
  }

  return 0;
}

