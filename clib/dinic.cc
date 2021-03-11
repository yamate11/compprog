#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// ----------------------------------------------------------------------

/*
  Network Maximum Flow  -- Dinic Method

  Usage: 
    Dinic d(numOfNodes, source, sink);
    d.add_edge(source, node_1, capacity_src_1);
    ...
    d.add_edge(node_10, sink, capacity_10_snk);
    ll flow = d.run();

  Note: Only directed graphs are supported (at the moment.  Support
        of undirected graphs should be easy).

  If you need the resulted flow on each edge, do:
    ll idx = d.add_edge(....);
    ...
    d.run();
    cout << d.eflow(idx) << endl;

 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- dinic.cc

struct Edge {
  int dst;  // destination
  ll cap;   // capacity
  int rev;  // index of reverse edge
  Edge(int d, ll c, int r) : dst(d), cap(c), rev(r) {}
};

struct Dinic {

  int vSize;
  int source;
  int sink;
  vector<int> level;  // from sink rather than source
  vector<size_t> iter;
  vector<vector<Edge>> edges;
  int eidx;
  vector<int> e_to_u;
  vector<int> e_to_uidx;

  ll dfs(int u, ll sCap) {
    if (u == sink) return sCap;
    ll f = 0;
    for (size_t& i = iter.at(u); i < edges.at(u).size(); i++) {
      Edge& e = edges.at(u).at(i);
      if (e.cap == 0 || level.at(e.dst) >= level.at(u)) continue;
      ll f0 = dfs(e.dst, min(sCap - f, e.cap));
      e.cap -= f0;
      edges.at(e.dst).at(e.rev).cap += f0;
      f += f0;
      if (f == sCap) break;
    }
    return f;
  }

  void set_level() {
    level.assign(vSize, -1);
    deque<pair<int,int>> deq;
    deq.emplace_back(sink, 0);
    while (!deq.empty()) {
      pair<int,int> p = deq.front(); deq.pop_front();
      int i = p.first;
      int lev = p.second;
      if (level.at(i) >= 0) continue;
      level.at(i) = lev;
      for (const Edge& erev : edges.at(i)) {
	const Edge& e = edges.at(erev.dst).at(erev.rev);
	if (e.cap == 0) continue;
	deq.emplace_back(erev.dst, lev + 1);
      }
    }
  }

public:

  Dinic(int sz, int src, int snk)
    : vSize(sz), source(src), sink(snk), edges(sz), eidx(0) {}

  ll add_edge(int u, int v, ll cap) {
    assert(0 <= u && u < vSize && 0 <= v && v < vSize);
    assert(cap >= 0);
    int nu = edges.at(u).size();
    int nv = edges.at(v).size();
    edges.at(u).emplace_back(v, cap, nv);
    edges.at(v).emplace_back(u, 0,   nu);
    assert(eidx == (ll)e_to_u.size() && eidx == (ll)e_to_uidx.size());
    e_to_u.push_back(u);
    e_to_uidx.push_back(nu);
    return eidx++;
  }

  ll run() {
    ll flow = 0;
    while(1) {
      set_level();
      if (level.at(source) == -1) break;
      iter.assign(vSize, 0);
      flow += dfs(source, LLONG_MAX);
    }
    return flow;
  }

  ll eflow(ll i) {
    Edge e = edges.at(e_to_u[i]).at(e_to_uidx[i]);
    return edges.at(e.dst).at(e.rev).cap;
  }

};
// @@ !! END ---- dinic.cc


int main() {

  {
    Dinic d1 = Dinic(2, 0, 1);
    d1.add_edge(0, 1, 10);
    assert(d1.run() == 10);
  }

  {
    Dinic d2 = Dinic(4, 0, 3);
    ll ei1 = d2.add_edge(0, 1, (ll)5e12);
    d2.add_edge(1, 3, (ll)2e12);
    d2.add_edge(0, 2, (ll)4e12);
    ll ei2 = d2.add_edge(2, 3, (ll)7e12);
    ll ei3 = d2.add_edge(0, 3, (ll)10e12);
    d2.add_edge(1, 2, 0);
    assert(d2.run() == (ll)16e12);
    assert(d2.eflow(ei1) == (ll)2e12);
    assert(d2.eflow(ei2) == (ll)4e12);
    assert(d2.eflow(ei3) == (ll)10e12);
  }

  {
    Dinic d3 = Dinic(5, 0, 4);
    d3.add_edge(0, 1, 10);
    d3.add_edge(0, 2, 2);
    d3.add_edge(1, 2, 6);
    d3.add_edge(1, 3, 6);
    d3.add_edge(3, 2, 3);
    d3.add_edge(2, 4, 5);
    d3.add_edge(3, 4, 8);
    assert(d3.run() == 11);
  }

  cerr << "OK\n";
  return 0;
}
