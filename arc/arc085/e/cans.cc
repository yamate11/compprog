#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#if defined(DEBUG)

#include <unistd.h>
#include <sys/fcntl.h>
#define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
#define DCALL(func, ...) func(__VA_ARGS__)

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#else  // defined(DEBUG)

#define DLOG(...)
#define DCALL(func, ...)

#endif // defined(DEBUG)
// ----------------------------------------------------------------------

struct Edge {
  int dst;
  ll cap;
  int rev;
  Edge(int d, ll c, int r) : dst(d), cap(c), rev(r) {}
};

class Dinic {

  int vSize;
  int source;
  int sink;
  vector<int> level;  // from sink rather than source
  vector<size_t> iter;
  vector<vector<Edge>> edges;

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
    : vSize(sz), source(src), sink(snk), edges(sz) {}

  void add_edge(int u, int v, ll cap) {
    assert(0 <= u && u < vSize && 0 <= v && v < vSize);
    assert(cap > 0);
    int nu = edges.at(u).size();
    int nv = edges.at(v).size();
    edges.at(u).push_back(Edge(v, cap, nv));
    edges.at(v).push_back(Edge(u, 0,   nu));
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
};

// ----------------------------------------------------------------------
int main(int argc, char *argv[]) {
#if defined(DEBUG)
  // GDB on Cygwin ignores redirection at run command.
  if (argc == 2) dup2(open(argv[1], 0), 0);
#else
  // For performance.  We should not use C-style stdio functions
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cout << setprecision(20);

  int N; cin >> N;

  ll myINF = (ll)1e16;

  ll pos = 0;
  Dinic g(N+2, 0, N+1);
  for (int i = 1; i <= N; i++) {
    ll a; cin >> a;
    if (a < 0) g.add_edge(0, i, -a);
    else {
      g.add_edge(i, N+1, a);
      pos += a;
    }
  }
  for (int i = 1; i <= N; i++) {
    for (int j = 2; j <= N && i*j <= N; j++) {
      g.add_edge(i, i*j, myINF);
    }
  }
  ll flow = g.run();
  cout << pos - flow << endl;

  return 0;
}

