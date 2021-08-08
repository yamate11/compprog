#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <atcoder/scc>
// using namespace atcoder;

// @@ !! LIM()

/*
   SCC ... strongly connected component
                    employs Tarjan's algorithm

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
     int numComp()                            number of SCCs
     int ccForNode(int nd)                    ID of SCC that nd belongs to
     const vector<int>& nodesInCC(int ccid)   nodes in SCC ccid
     const vector<int>& cFwd(int ccid)        successor SCCs
     const vector<int>& cBwd(int ccid)        predecessor SCCs
 */

struct SCC {
  int size;

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

  // forward relation in the original graph
  vector<vector<int>> _oFwd;

  // true if sccs have built
  bool built;

  // true if edges between sccs have built
  bool edge_built;

  SCC(int sz) : size(sz), _ccForNode(sz), _oFwd(sz), 
                built(false), edge_built(false) {}

  void addEdge(int from, int to) {
    _oFwd[from].push_back(to);
    // built = false;
  }

  void build() {
    if (built) return;
    int idx = 0;
    vector<int> stack;
    vector<int> index(size, -1);
    vector<int> lowlink(size);
    vector<bool> onstack(size, false);
    auto dfs = [&](auto rF, int i) -> void {
      index[i] = idx;
      lowlink[i] = idx;
      idx++;
      stack.push_back(i);
      onstack[i] = true;
      for (int j : _oFwd[i]) {
        if (index[j] < 0) {
          rF(rF, j);
          lowlink[i] = min(lowlink[i], lowlink[j]);
        }else if (onstack[j]) {
          lowlink[i] = min(lowlink[i], index[j]);
        }
      }
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
    for (int i = 0; i < size; i++) dfs(dfs, i);
    built = true;
  }

  void edge_build() {
    if (edge_built) return;
    if (!built) build();
    int sz = _nodesInCC.size();
    _cFwd.resize(sz);
    _cBwd.resize(sz);
    vector<bool> tmp;
    for (int i = 0; i < size; i++) {
      int icc = _ccForNode[i];
      for (int j : _oFwd[i]) {
        int jcc = _ccForNode[j];
        if (icc == jcc) continue;
        if (tmp[jcc]) continue;
        tmp[jcc] = true;
        _cFwd[icc].push_back(jcc);
        _cBwd[jcc].push_back(icc);
      }
      for (int j : _oFwd[i]) {
        int jcc = _ccForNode[j];
        tmp[jcc] = false;
      }
    }
    edge_built = true;
  }
};

double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using Edge = pair<int, int>;

  vector<Edge> edges;
  ll N, M; cin >> N >> M;
  double t90 = get_time_sec();
  for (ll i = 0; i < M; i++) {
    ll x, y; cin >> x >> y;
    edges.emplace_back(x, y);
  }
  double t91 = get_time_sec();
  auto edges2 = edges;
  double t92 = get_time_sec();

  double t1 = get_time_sec();
  SCC scc(N);
  vector<Edge> ttt;
  vector<vector<int>> foo(N);
  double t10 = get_time_sec();
  for (ll i = 0; i < M; i++) {
    // ttt.emplace_back(edges2[i].first, edges2[i].second);
    foo[edges2[i].first].push_back(edges2[i].second);
  }
  double t10a = get_time_sec();
  for (ll i = 0; i < M; i++) {
    scc.addEdge(edges2[i].first, edges2[i].second);
  }
  double t2 = get_time_sec();
  scc.build();
  double t25 = get_time_sec();


  double t3 = get_time_sec();
  atcoder::scc_graph atscc(N);
  double t4 = get_time_sec();
  for (ll i = 0; i < M; i++) {
    atscc.add_edge(edges2[i].first, edges2[i].second);
  }
  double t5 = get_time_sec();
  auto g = atscc.scc();
  double t6 = get_time_sec();



  cout << t91 - t90 << endl;
  cout << t92 - t91 << endl;

  cout << endl;

  cout << t10 - t1 << endl;
  cout << t10a - t10 << "  *" << endl;
  cout << t2 - t10a << endl;
  cout << t25 - t2 << endl;

  cout << endl;

  cout << t4 - t3 << endl;
  cout << t5 - t4 << endl;
  cout << t6 - t5 << endl;

  /*
  cout << g[0][0] << endl;
  cout << scc.ccForNode(0) << endl;
  */

  return 0;
}

