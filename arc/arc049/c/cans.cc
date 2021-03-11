#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(scc f:updMaxMin)
// --> scc f:updMaxMin
// ---- inserted library file scc.cc
using Edge = pair<int, int>;

struct SCC {
  // size is the number of nodes
  int size;

  // numComp is the number of SCCs
  int numComp;

  // ccForNode.at(n) is the identifier of the SCC that n belongs to
  vector<int> ccForNode;

  // nodesInCC.at(c) is the vector of nodes in SCC c.
  vector<vector<int>> nodesInCC;

  // cArr.at(c) is the vector of SCCs that are right after c.
  // Identifiers are in a topological order.  I.e.,
  //     m \in cArr.at(n) => n < m
  vector<vector<int>> cArr;

  // cRevArr.at(c) is the vector of SCCs that are right before c.
  vector<vector<int>> cRevArr;

  void init(auto edges) {
    vector<vector<int>> arr(size);
    vector<vector<int>> revArr(size);
    for (Edge e : edges) {
      arr[e.first].push_back(e.second);
      revArr[e.second].push_back(e.first);
    }
    vector<bool> visited(size);
    vector<int> finOrder;
    auto dfs1 = [&](const auto& recF, int n) -> void {
      if (visited.at(n)) return;
      visited.at(n) = true;
      for (int m : arr[n]) recF(recF, m);
      finOrder.push_back(n);
    };
    for (int i = 0; i < size; i++) {
      if (!visited.at(i)) dfs1(dfs1, i);
    }
    ccForNode.resize(size, -1);
    vector<set<int>> compRev;
    auto dfs2 = [&](const auto& recF, int n, int ccID) -> void {
      ccForNode.at(n) = ccID;
      nodesInCC.at(ccID).push_back(n);
      for (int m : revArr.at(n)) {
	int y = ccForNode.at(m);
	if (y == -1) {
	  recF(recF, m, ccID);
	}else if (y == ccID) {
	  // do nothing
	}else {
	  compRev.at(ccID).insert(y);
	}
      }
    };
    int ccID = 0;
    for (int f = (int)finOrder.size() -1; f >= 0; f--) {
      int n = finOrder.at(f);
      if (ccForNode.at(n) == -1) {
	nodesInCC.push_back(vector<int>());
	compRev.push_back(set<int>());
	dfs2(dfs2, n, ccID++);
      }
    }
    numComp = ccID;
    cArr.resize(numComp);
    cRevArr.resize(numComp);
    for (int i = 0; i < numComp; i++) {
      auto& s = compRev.at(i);
      cRevArr.at(i) = vector<int>(s.begin(), s.end());
      for (int x : cRevArr.at(i)) cArr.at(x).push_back(i);
    }
  }

  // _size is the number of nodes.
  // Edges should be numbered from 0 to _size - 1.
  // _edges is the vector of pair of int and int.
  SCC(int _size, vector<Edge>& _edges)
    : size(_size) { init(_edges); }
  SCC(int _size, vector<Edge>&& _edges)
    : size(_size) { init(_edges); }
};
// ---- end scc.cc
// ---- inserted function updMaxMin from util.cc
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
// ---- end updMaxMin
// @@ !! LIM  -- end mark --

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll A; cin >> A;
  vector<ll> X(A), Y(A);
  for (ll i = 0; i < A; i++) {
    ll x, y; cin >> x >> y; x--; y--;
    X.at(i) = x;
    Y.at(i) = y;
  }
  ll B; cin >> B;
  vector<ll> U(B), V(B);
  for (ll i = 0; i < B; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    U.at(i) = u;
    V.at(i) = v;
  }
  
  ll ans = 0;
  for (ll effB = 0; effB < (1LL << B); effB++) {
    vector<bool> blankNode(N);
    vector<Edge> edges;
    for (ll i = 0; i < A; i++) edges.emplace_back(Y.at(i), X.at(i));
    for (ll i = 0; i < B; i++) {
      if ((effB >> i) & 1) {
	edges.emplace_back(U.at(i), V.at(i));
      }else {
	blankNode.at(U.at(i)) = true;
      }
    }
    SCC scc(N, edges);
    ll M = scc.numComp;
    vector<bool> blankComp(M);

    auto mkBlank = [&](const auto& recF, ll n) -> void {
      if (blankComp.at(n)) return;
      blankComp.at(n) = true;
      for (ll m : scc.cArr.at(n)) recF(recF, m);
    };

    for (ll i = M - 1; i >= 0; i--) {
      auto nodes = scc.nodesInCC.at(i);
      if (nodes.size() > 1 || blankNode.at(nodes.at(0))) {
	mkBlank(mkBlank, i);
      }
    }

    ll cnt = N;
    for (ll i = 0; i < M; i++) {
      if (blankComp.at(i)) { cnt -= scc.nodesInCC.at(i).size(); }
    }
    updMax(ans, cnt);
  }
  cout << ans << endl;


  return 0;
}

