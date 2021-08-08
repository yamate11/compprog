#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM(scc)

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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto getscc = [&]() {
    vector<Edge> edges;
    ll N; cin >> N;
    for (ll i = 0; i < N; i++) {
      for (ll j = 0; j < N; j++) {
        ll t; cin >> t;
        if (t == 0) continue;
        edges.emplace_back(i, j);
      }
    }
    return SCC(N, move(edges));
  };
  SCC scc = getscc();
  ll M = scc.numComp;
  const vector<vector<int>>& fwd = scc.cArr;
  vector<ll> rank(M, -1LL);
  auto calc_rank = [&](auto rF, ll i) -> ll {
    ll& ret = rank[i];
    if (ret < 0) {
      ret = 0;
      for (ll c : fwd[i]) ret = max(ret, rF(rF, c) + 1);
    }
    return ret;
  };
  for (ll i = 0; i < M; i++) calc_rank(calc_rank, i);
  vector<ll> sval(M);
  for (ll i = 0; i < M; i++) sval[i] = scc.nodesInCC[i].size();
  auto pval = vector(M, vector<ll>(M, -1));
  auto calc_pval = [&](auto rF, ll i, ll j) -> ll {
    ll& ret = pval[i][j];
    if (ret < 0) {
      if (rank[i] > rank[j]) ret = rF(rF, j, i);
      else {
        if (rank[j] == 0) {
          ret = sval[i];
        }else {
          ret = 0;
          for (ll c : fwd[j]) ret = max(ret, rF(rF, i, c));
        }
        if (i != j) ret += sval[j];
      }
    }
    return ret;
  };
  ll ans = 0;
  for (ll i = 0; i < M; i++) {
    for (ll j = 0; j < M; j++) ans = max(ans, calc_pval(calc_pval, i, j));
  }
  cout << ans << endl;
  

  return 0;
}

