#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(dinic)

// ---- inserted library file dinic.cc

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
// ---- end dinic.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll H, W, C; cin >> H >> W >> C;
  ll tot = 0;
  vector A(H, vector(W, 0LL)); REP(r, H) REP(c, W) {
    cin >> A[r][c];
    tot += A[r][c];
  }
  ll ndTrue = 0;
  ll ndFalse = 1;
  // Node enc(r, c) means that (r,c) is hatched.
  auto enc = [&](ll r, ll c) -> ll { return c + W * r + 2; };

  Dinic d(2 + W * H, ndTrue, ndFalse);
  REP(r, H) REP(c, W) d.add_edge(ndTrue, enc(r, c), A[r][c]);
  REP(r, H) REP(c, W) {
    if (r-1 >= 0 and c-1 >= 0) d.add_edge(enc(r, c), enc(r-1, c-1), C);
    else                       d.add_edge(enc(r, c), ndFalse,       C);
    if (r-1 >= 0 and c+1 < W)  d.add_edge(enc(r, c), enc(r-1, c+1), C);
    else                       d.add_edge(enc(r, c), ndFalse,       C);
  }
  ll flow = d.run();
  cout << tot - flow << endl;
  return 0;
}

