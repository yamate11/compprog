#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(scc binsearch)
// --> scc binsearch
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
// ---- inserted library file binsearch.cc

template<typename T>
T binsearch(auto check, T yes, T no, T err = (T)1) {
  while (abs(yes - no) > err) {
    T mid = (yes + no) / (T)2;
    if (check(mid)) yes = mid;
    else            no  = mid;
  }
  return yes;
}

// ---- end binsearch.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto limsq = [](ll w) -> ll {
    auto check = [&w](ll p) -> bool {
      return p * (p + 1) / 2 <= w;
    };
    ll p = binsearch<ll>(check, 0, w);
    return p;
  };

  auto exhaust = [&limsq](ll w) -> ll {
    if (w <= 1) return w;
    ll p = limsq(w);
    ll sum = (p * (p + 1) * (2*p + 1) / 6 + p * (p + 1) / 2) / 2;
    ll ret = w * (p + 1) - sum;
    return ret;
  };

#if DEBUG
  assert(exhaust(9) == 26);
  assert(exhaust(4) == 8);
  assert(exhaust(2) == 3);
#endif

  ll n, m; cin >> n >> m;
  vector<Edge> edges;
  using rec_t = tuple<ll, ll, ll>;
  vector<rec_t> rec;
  for (ll i = 0; i < m; i++) {
    ll x, y, w; cin >> x >> y >> w; x--; y--;
    rec.emplace_back(x, y, w);
    edges.emplace_back(x, y);
  }
  ll start; cin >> start; start--;
  SCC scc(n, move(edges));
  
  vector<ll> ccval(scc.numComp);
  using nbr_t = pair<ll, ll>;
  vector<vector<nbr_t>> ccnbr(scc.numComp);
  for (ll i = 0; i < m; i++) {
    auto [x, y, w] = rec[i];
    ll idx = scc.ccForNode[x];
    ll idy = scc.ccForNode[y];
    if (idx == idy) {
      ccval[idx] += exhaust(w);
    }else {
      ccnbr[idx].emplace_back(idy, w);
    }
  }
  vector<ll> val(scc.numComp, -1);
  auto getVal = [&](auto rF, ll t) -> ll {
    ll& ret = val[t];
    if (ret == -1) {
      ll vmax = 0;
      for (auto [u, w] : ccnbr[t]) {
        vmax = max(vmax, rF(rF, u) + w);
      }
      ret = ccval[t] + vmax;
    }
    return ret;
  };
  ll t0 = scc.ccForNode[start];
  ll ans = getVal(getVal, t0);
  cout << ans << endl;
  
  return 0;
}

