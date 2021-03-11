#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:<<)
// --> f:<<
// ---- inserted function << from util.cc
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

template <typename T>
ostream& operator<< (ostream& os, const set<T>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const map<T1, T2>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
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
// ---- end <<
// @@ !! LIM  -- end mark --


//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN()
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
// @@ !! END ---- scc.cc


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<Edge> edge1 = { Edge(0, 1), Edge(1, 0) };
  SCC scc1(2, edge1);
  assert(scc1.size == 2);
  assert(scc1.numComp == 1);
  assert(scc1.nodesInCC.at(0) == vector<int>({0,1}));
  assert(scc1.ccForNode == vector<int>({0,0}));

  vector<Edge> edge2 = {
    Edge(0, 1), Edge(1, 2), Edge(2, 0),
    Edge(1, 3), Edge(3, 4), Edge(4, 5),
    Edge(5, 6), Edge(6, 5)
  };
  SCC scc2(7, edge2);
  assert(scc2.size == 7);
  assert(scc2.numComp == 4);
  assert(scc2.ccForNode.at(0) == scc2.ccForNode.at(2));
  assert(scc2.ccForNode.at(5) == scc2.ccForNode.at(6));
  assert(scc2.nodesInCC.at(scc2.ccForNode.at(3)).size() == 1);
  assert(scc2.cArr.at(scc2.ccForNode.at(0))
	 == vector<int>({scc2.ccForNode.at(3)}));
  for (int n = 0; n < scc2.numComp; n++) {
    for (int m: scc2.cArr.at(n)) assert(n < m);
  }

  vector<Edge> edge3 = {
    Edge(0,1), Edge(0,2), Edge(1,2), Edge(2,1),
    Edge(1,3), Edge(2,3), Edge(3,6), Edge(6,2),
    Edge(3,4), Edge(3,5), Edge(3,8), Edge(4,4), Edge(4,9), Edge(9,10),
    Edge(5,7), Edge(7,5), Edge(7,10), Edge(8,10)
  };
  SCC scc3(11, edge3);
  int c1236 = scc3.ccForNode.at(1);
  int c57 = scc3.ccForNode.at(5);
  int c4 = scc3.ccForNode.at(4);
  int c8 = scc3.ccForNode.at(8);
  int c9 = scc3.ccForNode.at(9);
  assert(scc3.nodesInCC.at(c1236).size() == 4);
  assert(scc3.nodesInCC.at(c57).size() == 2);
  assert(scc3.nodesInCC.at(c4).size() == 1);
  assert(scc3.nodesInCC.at(c9).size() == 1);
  assert(scc3.cArr.at(c4) == vector<int>({c9}));
  assert(scc3.cRevArr.at(c4) == vector<int>({c1236}));
  vector<int> varr1236 = scc3.cArr.at(c1236);
  set<int> sarr1236(varr1236.begin(), varr1236.end());
  assert(varr1236.size() == 3);
  assert(sarr1236.count(c4) == 1);
  assert(sarr1236.count(c57) == 1);
  assert(sarr1236.count(c8) == 1);
  for (int n = 0; n < scc3.numComp; n++) {
    for (int m: scc3.cArr.at(n)) assert(n < m);
  }

  cout << "Test completed." << endl;
  return 0;
}

