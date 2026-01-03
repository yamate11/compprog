#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(input scc)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

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
  // @InpNbrList(N, M, fwd, dir=True, bwd=bwd, dec=1) [rEsM3rMa]
  auto fwd = vector(N, vector(0, int()));
  auto bwd = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd[u].emplace_back(v);
    bwd[v].emplace_back(u);
  }
  // @End [rEsM3rMa]
  SCC scc(N);
  REP(i, 0, N) {
    for (ll p : fwd[i]) scc.addEdge(i, p);
  }
  scc.build();
  ll ans = 0;
  vector visited(N, false);
  auto go = [&](auto rF, ll nd) -> void {
    ans++;
    visited[nd] = true;
    for (ll p : bwd[nd]) {
      if (not visited[p]) rF(rF, p);
    }
  };
  REP(i, 0, N) {
    if (not visited[i]) {
      if (ssize(scc.nodesInCC(scc.ccForNode(i))) > 1) go(go, i);
    }
  }
  cout << ans << endl;
  return 0;
}

