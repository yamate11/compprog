#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  Minimal Cost Flow

  Usage:
    MinCostFlow mcf(num_of_nodes);
    mcf.add_edge(src_0, dst_0, capacity_0, cost_0);
    mcf.add_edge(src_1, dst_1, capacity_1, cost_1);
    ...
    ll answer = mcf.run(source, sink, vol_flow);
 */

// @@ !! LIM()

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- minCostFlow.cc

struct Edge {
  int dst;
  ll cap;
  ll cost;
  int rev;
  Edge(int d, ll ca, ll co, int r) : dst(d), cap(ca), cost(co), rev(r) {}
};

class MinCostFlow {
  int vSize;
  vector<vector<Edge>> edges;

public:
  MinCostFlow(int sz) :
    vSize(sz), edges(sz) {}

  void add_edge(int u, int v, ll cap, ll cost) {
    edges.at(u).emplace_back(v, cap, cost, edges.at(v).size());
    edges.at(v).emplace_back(u, 0, -cost, edges.at(u).size() - 1);
  }
  
  // Returns minimum cost for flow f from source to sink,
  // or -1 if there is no path.
  ll run(int source, int sink, ll f) {
    ll retval = 0;
    vector<ll> h(vSize); // potential
    vector<int> prevv(vSize);
    vector<int> preve(vSize);
    using Pair = pair<ll, int>;
    while (f > 0) {
      priority_queue<Pair, vector<Pair>, greater<Pair>> pque;
      vector<ll> dist(vSize, LLONG_MAX);
      dist.at(source) = 0;
      pque.emplace(0, source);
      while (!pque.empty()) {
	Pair p = pque.top(); pque.pop();
	ll dd; int v; tie(dd, v) = p;
	if (dist.at(v) < dd) continue;
	for (int i = 0; i < (int)edges.at(v).size(); i++) {
	  Edge& e = edges.at(v).at(i);
	  if (e.cap > 0 &&
	      dist.at(e.dst) > dist.at(v) + e.cost + h.at(v) - h.at(e.dst)) {
	    dist.at(e.dst) = dist.at(v) + e.cost + h.at(v) - h.at(e.dst);
	    prevv.at(e.dst) = v;
	    preve.at(e.dst) = i;
	    pque.emplace(dist.at(e.dst), e.dst);
	  }
	}
      }
      if (dist.at(sink) == LLONG_MAX) return -1;
      for (int v = 0; v < vSize; v++) h.at(v) += dist.at(v);

      ll d = f;
      for (int v = sink; v != source; v = prevv.at(v)) {
	d = min(d, edges.at(prevv.at(v)).at(preve.at(v)).cap);
      }
#if DEBUG_LIB
      // DLOG_LIB("flow =", d);
      stack<int> path;
      for (int v = sink; v != source; v = prevv.at(v)) {
	path.push(v);
	// DLOG_LIB("  ", prevv.at(v), "->", v);
      }
      path.push(source);
      DLOG_LIB("flow =", d, ", path =", path);
#endif
      f -= d;
      retval += d * h.at(sink);
      for (int v = sink; v != source; v = prevv.at(v)) {
	Edge& e = edges.at(prevv.at(v)).at(preve.at(v));
	e.cap -= d;
	edges.at(v).at(e.rev).cap += d;
      }
    }
    return retval;
  }

};

// @@ !! END ---- minCostFlow.cc

  
int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    MinCostFlow mcf(5);
    mcf.add_edge(0, 1, 10, 2);
    mcf.add_edge(0, 2, 2, 4);
    mcf.add_edge(1, 2, 6, 6);
    mcf.add_edge(1, 3, 6, 2);
    mcf.add_edge(2, 4, 5, 2);
    mcf.add_edge(3, 2, 3, 3);
    mcf.add_edge(3, 4, 8, 6);
    ll c = mcf.run(0, 4, 9);
    assert(c == 80);
  }

  cout << "Test Done." << endl;
  return 0;
  
}
