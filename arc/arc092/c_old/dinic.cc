#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// See debug.cc for usage etc
#define DEBUG 1

template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

#if DEBUG
  #define DLOG(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DCALL(func, ...)
#endif

class Dinic {
  friend class DinicTest;

  struct Edge {
    int to;
    ll capacity;
    int rev;
    Edge(int _to, ll _capacity, int _rev)
      : to(_to), capacity(_capacity), rev(_rev) {}
    const char* to_c_str() {
      stringstream ss;
      ss << "to: " << to << ", cap: " << capacity << ", rev: " << rev;
      return ss.str().c_str();
    }
  };

  struct FindPath {
    vector<int> iSt;
    const vector<int>& level;
    
    FindPath(const vector<int> _level) : level(_level) {}
    ll run(int s, int e) {
      return run_sub(LLONG_MAX, s, e);
    }
    ll run_sub(int f, int s, int e) {
      if (s == e) return f;
      int& i = iSt.at(s);
      for (; i < (int)edges.at(s).size(); i++) {
	auto ed = edges.at(s).at(i);
	if (level.at(s) >= level.at(ed.to)) continue;
	if (ed.capacity == 0) continue;
	ll flow = findPath(level, iSt, min(f, ed.capacity), ed.to, e);
	if (flow > 0) {
	  ed.capacity -= flow;
	  edges.at(ed.to).at(ed.rev).capacity += flow;
	  return flow;
	}
      }
      return 0;
    }
  };

  int numNodes;
  vector<vector<Edge>> edges;

  vector<int> buildLevel(int s, int e) {
    vector<int> level(numNodes, -1);
    queue<int> q;
    level.at(s) = 0;
    q.push(s);
    while (!q.empty()) {
      int x = q.front(); q.pop();
      DLOG("Edges from %d", x);
      for (Edge ed : edges.at(x)) {
	DLOG("edge at %d, %s", x, ed.to_c_str());
	if (level.at(ed.to) >= 0 || ed.capacity == 0) continue;
	level.at(ed.to) = level.at(x) + 1;
	q.push(ed.to);
      }
    }
    return level;
  }

  ll findPath(auto level, auto iSt, ll f, int s, int e) {
    if (s == e) return f;
    int& i = iSt.at(s);
    for (; i < (int)edges.at(s).size(); i++) {
      auto ed = edges.at(s).at(i);
      if (level.at(s) >= level.at(ed.to)) continue;
      if (ed.capacity == 0) continue;
      ll flow = findPath(level, iSt, min(f, ed.capacity), ed.to, e);
      if (flow > 0) {
	ed.capacity -= flow;
	edges.at(ed.to).at(ed.rev).capacity += flow;
	return flow;
      }
    }
    return 0;
  }

public:
  Dinic(int _numNodes) : numNodes(_numNodes), edges(_numNodes) {}

  void addEdge(int from, int to, ll cap) {
    auto& esF = edges.at(from);
    auto& esT = edges.at(to);
    esF.emplace(esF.end(), to, cap, esT.size());
    esT.emplace(esT.end(), from, 0, esF.size()-1);
    DLOG("tmp: %d", edges.at(from).size());
    DLOG("tmp2: %d", esF.size());
  }

  ll solve(int s, int e) {
    ll flow = 0;
    while (1) {
      vector<int> level = buildLevel(s, e);
#if DEBUG
      for (int i = 0; i < numNodes; i++) {
	DLOG("level[%d] == %d", i, level.at(i));
      }
#endif
      if (level.at(e) < 0) return flow;
      vector<int> iSt(numNodes);
      flow += findPath(level, iSt, LLONG_MAX, s, e);
    }
    return flow;
  }

};


class DinicTest {
public:
  Dinic dnc1;

  DinicTest() : dnc1(2) {
    dnc1.addEdge(0, 1, 10);
  }

  void run() {
    test1();
  }

  void test1() {
    auto level = dnc1.buildLevel(0, 1);
    assert(level.at(0) == 0);
    assert(level.at(1) == 1);
    ll flow = FindPath fp(level).run(1, 1);
    assert(flow == LLONG_MAX);
  }
};


int main() {
  DinicTest dt = DinicTest();
  dt.run();
  
  return 0;
}
