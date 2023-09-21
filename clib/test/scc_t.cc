#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:<< scc)

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig);

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig);

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st);

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t);
#endif

ostream& operator<< (ostream& os, int8_t x);

// definitions

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
  return os;
}

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ")";
  return os;
}

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v) {
  os << '[';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << ']';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig) {
  queue<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig) {
  deque<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop_front();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig) {
  priority_queue<T, T2, T3> pq(orig);
  bool first = true;
  os << '[';
  while (!pq.empty()) {
    T x = pq.top(); pq.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
}

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st) {
  stack<T> tmp(st);
  os << '[';
  bool first = true;
  while (!tmp.empty()) {
    T& t = tmp.top();
    if (first) first = false;
    else os << ", ";
    os << t;
    tmp.pop();
  }
  os << ']';
  return os;
}

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t) {
  if (t.has_value()) os << "v(" << t.value() << ")";
  else               os << "nullopt";
  return os;
}
#endif

ostream& operator<< (ostream& os, int8_t x) {
  os << (int32_t)x;
  return os;
}

// ---- end f:<<

// ---- inserted library file scc.cc
#line 50 "/home/y-tanabe/proj/compprog/clib/scc.cc"

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
#line 7 "scc_skel.cc"

struct NaiveSCC {
  bool built;
  int size;
  vector<vector<bool>> conn;
  
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
    if (! built) build();
    return _cFwd[ccid];
  }

  vector<vector<int>> _cBwd;
  const vector<int>& cBwd(int ccid) {
    if (! built) build();
    return _cBwd[ccid];
  }

  NaiveSCC(int size_) : built(false), size(size_),
                        conn(size, vector<bool>(size)) {}

  void addEdge(int from, int to) { conn[from][to] = true; }

  void build() {
    if (built) return;
    built = true;
    auto trcl = conn;
    for (ll k = 0; k < size; k++) {
      for (ll i = 0; i < size; i++) {
        for (ll j =  0; j < size; j++) {
          if (trcl[i][k] && trcl[k][j]) trcl[i][j] = true;
        }
      }
    }
    _ccForNode = vector<int>(size, -1);
    for (int i = 0; i < size; i++) {
      if (_ccForNode[i] >= 0) continue;
      vector<int> nodes({i});
      ll idx = _nodesInCC.size();
      _ccForNode[i] = idx;
      for (int j = i + 1; j < size; j++) {
        if (trcl[i][j] && trcl[j][i]) {
          nodes.push_back(j);
          _ccForNode[j] = idx;
        }
      }
      _nodesInCC.push_back(move(nodes));
    }
    int numCC = _nodesInCC.size();
    _cFwd.resize(numCC);
    _cBwd.resize(numCC);
    for (int p = 0; p < numCC; p++) {
      for (int q = 0; q < numCC; q++) {
        if (p == q) continue;
        if ([&]() -> bool {
          for (ll i : _nodesInCC[p]) {
            for (ll j : _nodesInCC[q]) if (conn[i][j]) return true;
          }
          return false;
        }()) {
          _cFwd[p].push_back(q);
          _cBwd[q].push_back(p);
        }
      }
    }
    for (ll p = 0; p < numCC; p++) {
      sort(_nodesInCC[p].begin(), _nodesInCC[p].end());
      sort(_cFwd[p].begin(), _cFwd[p].end());
      sort(_cBwd[p].begin(), _cBwd[p].end());
    }
  }
};

struct Compare {
  SCC scc;
  NaiveSCC nscc;
  Compare(int size) : scc(size), nscc(size) {}
  void addEdge(int from, int to) {
    scc.addEdge(from, to);
    nscc.addEdge(from, to);
  }

  void check() {
    ll nc = scc.numComp();
    assert(scc.numComp() == nscc.numComp());
    vector<int> corr(nc);
    for (ll i = 0; i < scc.size; i++) {
      corr[scc.ccForNode(i)] = nscc.ccForNode(i);
    }
    auto eq_corr = [&](auto& vec1, auto& vec2) {
      // DLOGK(vec1, vec2);
      vector<int> vec;
      for (int x : vec1) vec.push_back(corr[x]);
      sort(vec.begin(), vec.end());
      assert(vec == vec2);
    };

    // DLOGK(corr);
    for (ll p = 0; p < nc; p++) {
      /*
      DLOGK(p);
      DLOGK(scc._ccForNode);
      DLOGK(scc._nodesInCC);
      DLOGK(nscc._ccForNode);
      DLOGK(nscc._nodesInCC);
      */
      auto vv = scc.nodesInCC(p);
      sort(vv.begin(), vv.end());
      assert(vv == nscc.nodesInCC(corr[p]));
      scc.edge_build();
      /*
      DLOGK(scc._cFwd);
      DLOGK(scc._cBwd);
      DLOGK(nscc._cFwd);
      DLOGK(nscc._cBwd);
      */
      eq_corr(scc.cFwd(p), nscc.cFwd(corr[p]));
      eq_corr(scc.cBwd(p), nscc.cBwd(corr[p]));
      for (ll r : scc.cFwd(p)) assert (p > r);
      for (ll r : scc.cBwd(p)) assert (r > p);
    }
  }

};


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  random_device rd;
  mt19937 rng(rd());
  auto randrange = [&rng](ll i, ll j) -> ll {
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  };

  {
    SCC scc1(2);
    scc1.addEdge(0, 1);
    scc1.addEdge(1, 0);
    scc1.build();
    assert(scc1.size == 2);
    // DLOGK(scc1._nodesInCC);
    // DLOGK(scc1.numComp());
    assert(scc1.numComp() == 1);
    assert(scc1.nodesInCC(0).size() == 2);
    assert(scc1.ccForNode(0) == 0);
    assert(scc1.ccForNode(1) == 0);
  }
  {
    SCC scc2(7);
    scc2.addEdge(0, 1);
    scc2.addEdge(1, 2);
    scc2.addEdge(2, 0);
    scc2.addEdge(1, 3);
    scc2.addEdge(3, 4);
    scc2.addEdge(4, 5);
    scc2.addEdge(5, 6);
    scc2.addEdge(6, 5);
    assert(scc2.size == 7);
    assert(scc2.numComp() == 4);
    assert(scc2.ccForNode(0) == scc2.ccForNode(2));
    assert(scc2.ccForNode(5) == scc2.ccForNode(6));
    assert(scc2.nodesInCC(scc2.ccForNode(3)).size() == 1);
    assert(scc2.cFwd(scc2.ccForNode(0)) == vector<int>({scc2.ccForNode(3)}));
    for (int n = 0; n < scc2.numComp(); n++) {
      for (int m: scc2.cFwd(n)) assert(n > m);
    }
  }
  {
    SCC scc3(11);
    scc3.addEdge(0, 1);
    scc3.addEdge(0, 2);
    scc3.addEdge(1, 2);
    scc3.addEdge(2, 1);
    scc3.addEdge(1, 3);
    scc3.addEdge(2, 3);
    scc3.addEdge(3, 6);
    scc3.addEdge(6, 2);
    scc3.addEdge(3, 4);
    scc3.addEdge(3, 5);
    scc3.addEdge(3, 8);
    scc3.addEdge(4, 4);
    scc3.addEdge(4, 9);
    scc3.addEdge(9, 10);
    scc3.addEdge(5, 7);
    scc3.addEdge(7, 5);
    scc3.addEdge(7, 10);
    scc3.addEdge(8, 10);
    int c1236 = scc3.ccForNode(1);
    int c57 = scc3.ccForNode(5);
    int c4 = scc3.ccForNode(4);
    int c8 = scc3.ccForNode(8);
    int c9 = scc3.ccForNode(9);
    assert(scc3.nodesInCC(c1236).size() == 4);
    assert(scc3.nodesInCC(c57).size() == 2);
    assert(scc3.nodesInCC(c4).size() == 1);
    assert(scc3.nodesInCC(c9).size() == 1);
    assert(scc3.cFwd(c4) == vector<int>({c9}));
    assert(scc3.cBwd(c4) == vector<int>({c1236}));
    vector<int> varr1236 = scc3.cFwd(c1236);
    set<int> sarr1236(varr1236.begin(), varr1236.end());
    assert(varr1236.size() == 3);
    assert(sarr1236.count(c4) == 1);
    assert(sarr1236.count(c57) == 1);
    assert(sarr1236.count(c8) == 1);
    for (int n = 0; n < scc3.numComp(); n++) {
      for (int m: scc3.cFwd(n)) assert(n > m);
    }
  }
  {
    ll N = 4;
    for (ll x = 0; x < 1LL << (N*N); x++) {
      // DLOGKL("loop", x);
      Compare cp(N);
      for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
          if (((x >> (4*i + j)) & 1) != 0) cp.addEdge(i, j);
        }
      }
      cp.check();
    }
  }
  {
    ll rpt = 1000;
    for (ll i = 0; i < rpt; i++) {
      ll N = randrange(10, 100);
      ll M = randrange(0, N*N);
      auto rec = vector(N, vector(N, false));
      Compare cp(N);
      for (ll j = 0; j < M; j++) {
        ll x = randrange(0, N);
        ll y = randrange(0, N);
        cp.addEdge(x, y);
      }
      cp.check();
    }
  }
  cout << "Test completed." << endl;
  return 0;
}

