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

// @@ !! LIM(scc f:updMaxMin)

// ---- inserted library file scc.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/scc.cc

template<typename E>
struct CSR {  // Compressed Sparse Row
  ll size;
  vector<ll> start;
  vector<E> es;
  vector<pair<ll, E>> tmp;
  CSR(ll size_) : size(size_), start(size + 1) {}
  void add(ll i, const E& e) { tmp.emplace_back(i, E(e)); }
  void add(ll i, E&& e) { tmp.emplace_back(i, e); }
  void build() {
    vector<ll> num(size);
    ll tot = 0;
    for (auto& [i, e] : tmp) {
      num[i]++;
      tot++;
    }
    es.resize(tot);
    for (ll i = 0; i < size; i++) start[i+1] = start[i] + num[i];
    for (auto& [i, e] : tmp) {
      es[start[i + 1] - num[i]] = move(e);
      num[i]--;
    }
  }
};

struct SCC {
  ll size;

  CSR<ll> csr;

  vector<ll> _ccForNode;
  ll ccForNode(ll nd) {
    if (!built) build();
    return _ccForNode[nd];
  }

  vector<vector<ll>> _nodesInCC;
  const vector<ll>& nodesInCC(ll ccid) {
    if (!built) build();
    return _nodesInCC[ccid];
  }

  ll numComp() {
    if (! built) build();
    return _nodesInCC.size();
  }

  vector<vector<ll>> _cFwd;
  const vector<ll>& cFwd(ll ccid) {
    if (!edge_built) edge_build();
    return _cFwd[ccid];
  }

  vector<vector<ll>> _cBwd;
  const vector<ll>& cBwd(ll ccid) {
    if (!edge_built) edge_build();
    return _cBwd[ccid];
  }

  // true if sccs have built
  bool built;

  // true if edges between sccs have built
  bool edge_built;

  SCC(ll sz) : size(sz), csr(size), _ccForNode(sz), 
                built(false), edge_built(false) {}

  void addEdge(ll from, ll to) { csr.add(from, to); }

  void build() {
    if (built) return;
    built = true;
    csr.build();
    ll idx = 0;
    vector<ll> stack;
    vector<ll> index(size, -1);
    vector<ll> lowlink(size);
    vector<bool> onstack(size, false);
    auto dfs = [&](auto rF, ll i) -> void {
      // DLOGKL("dfs", i);
      index[i] = idx;
      lowlink[i] = idx;
      idx++;
      stack.push_back(i);
      onstack[i] = true;
      for (ll k = csr.start[i]; k < csr.start[i + 1]; k++) {
        ll j = csr.es[k];
        if (index[j] < 0) {
          rF(rF, j);
          lowlink[i] = min(lowlink[i], lowlink[j]);
        }else if (onstack[j]) {
          lowlink[i] = min(lowlink[i], index[j]);
        }
      }
      // DLOGK(i, lowlink[i], index[i]);
      if (lowlink[i] == index[i]) {
        ll ccid = _nodesInCC.size();
        _nodesInCC.resize(ccid + 1);
        vector<ll>& cc = _nodesInCC[ccid];
        while (true) {
          ll j = stack.back(); stack.pop_back();
          onstack[j] = false;
          cc.push_back(j);
          _ccForNode[j] = ccid;
          if (j == i) break;
        }
      }
    };
    for (ll i = 0; i < size; i++) if (index[i] < 0) dfs(dfs, i);
  }

  void edge_build() {
    if (edge_built) return;
    edge_built = true;
    if (!built) build();
    ll sz = _nodesInCC.size();
    _cFwd.resize(sz);
    _cBwd.resize(sz);
    for (ll icc = 0; icc < sz; icc++) {
      vector<bool> tmp(sz);
      for (ll i : _nodesInCC[icc]) {
        for (ll k = csr.start[i]; k < csr.start[i + 1]; k++) {
          ll j = csr.es[k];
          ll jcc = _ccForNode[j];
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

// ---- inserted function f:updMaxMin from util.cc
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
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpMVec(Q, (T, (U, dec=1), (V, dec=1))) [ZD4lmK1f]
  auto T = vector(Q, ll());
  auto U = vector(Q, ll());
  auto V = vector(Q, ll());
  for (int i = 0; i < Q; i++) {
    ll v1; cin >> v1; T[i] = v1;
    ll v2; cin >> v2; v2 -= 1; U[i] = v2;
    ll v3; cin >> v3; v3 -= 1; V[i] = v3;
  }
  // @End [ZD4lmK1f]

  SCC scc(N);

  REP(i, 0, Q) {
    if (T[i] == 0) {
      scc.addEdge(U[i], V[i]);
    }else {
      scc.addEdge(U[i], V[i]);
    }
  }
  scc.build();
  
  REP(i, 0, Q) {
    if (T[i] == 1) {
      if (scc.ccForNode(U[i]) == scc.ccForNode(V[i])) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";
  ll M = scc.numComp();
  vector<ll> rank(M, -1LL);
  auto calc_rank = [&](auto rF, ll i) -> ll {
    ll& r = rank[i];
    if (r < 0) {
      r = 0;
      for (ll j : scc.cBwd(i)) {
        updMax(r, 1 + rF(rF, j));
      }
    }
    return r;
  };
  REP(i, 0, M) calc_rank(calc_rank, i);
  vector<ll> ans(N);
  REP(i, 0, N) ans[i] = rank[scc.ccForNode(i)];
  REPOUT(i, 0, N, ans[i] + 1, " ");

  return 0;
}

