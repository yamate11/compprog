#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:<< scc)

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

