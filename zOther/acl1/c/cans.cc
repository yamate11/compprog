#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(minCostFlow debug)
// --> minCostFlow f:<< debug
// ---- inserted library file minCostFlow.cc

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

// ---- end minCostFlow.cc
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

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v) {
  os << '{';
  for (auto it = v.begin(); it != v.end(); it++) {
    if (it != v.begin()) os << ", ";
    os << *it;
  }
  os << '}';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp) {
  os << '[';
  for (auto it = mp.begin(); it != mp.end(); it++) {
    if (it != mp.begin()) os << ", ";
    os << it->first << ": " << it->second;
  }
  os << ']';

  return os;
}

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig) {
  queue<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop();
    if (!first) os << ", ";
    os << x;
    first = false;
  }
  return os << ']';
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

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st) {
  stack<T> tmp(st);
  os << '[';
  bool first = true;
  while (!tmp.empty()) {
    T& t = tmp.top();
    if (first) first = false;
    else os << ", ";
    os << t;
    tmp.pop();
  }
  os << ']';
  return os;
}

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t) {
  if (t.has_value()) os << "v(" << t.value() << ")";
  else               os << "nullopt";
  return os;
}
#endif

ostream& operator<< (ostream& os, int8_t x) {
  os << (int32_t)x;
  return os;
}

// ---- end <<
// ---- inserted library file debug.cc
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(Head&& head) {
  cerr << head << endl;
}

template <class Head, class... Tail>
void dbgLog(Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(__VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(__VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif

// ---- end debug.cc
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<string> S(N);
  for (ll i = 0; i < N; i++) cin >> S[i];
  vector rbl(N, vector(M, vector(N, vector(M, false))));
  ll cntC = 0;
  ll cntP = 0;
  vector encC(N, vector(M, 0LL));
  vector encP(N, vector(M, 0LL));
  for (ll i = N - 1; i >= 0; i--) {
    for (ll j = M - 1; j >= 0; j--) {
      if (S[i][j] == '#') continue;
      encP[i][j] = cntP++;
      if (S[i][j] == 'o') encC[i][j] = cntC++;
      rbl[i][j][i][j] = true;
      if (j+1 < M && S[i][j+1] != '#') {
	for (ll k = N - 1; k >= 0; k--) {
	  for (ll l = M - 1; l >= 0; l--) {
	    rbl[i][j][k][l] = rbl[i][j][k][l] || rbl[i][j+1][k][l];
	  }
	}
      }
      if (i+1 < N && S[i+1][j] != '#') {
	for (ll k = N - 1; k >= 0; k--) {
	  for (ll l = M - 1; l >= 0; l--) {
	    rbl[i][j][k][l] = rbl[i][j][k][l] || rbl[i+1][j][k][l];
	  }
	}
      }
    }
  }
  ll source = cntC + cntP;
  ll sink = cntC + cntP + 1;
  ll ceil = 1000;
  MinCostFlow mcf(cntC + cntP + 2);
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < M; j++) {
      if (S[i][j] == '#') continue;
      DLOG("to sink", cntC + encP[i][j], "->", sink);
      mcf.add_edge(cntC + encP[i][j], sink, 1, 0);
      if (S[i][j] == 'o') {
	DLOG("from source", source, "->", encC[i][j]);
	mcf.add_edge(source, encC[i][j], 1, 0);
	for (ll k = i; k < N; k++) {
	  for (ll l = j; l < M; l++) {
	    if (rbl[i][j][k][l]) {
	      ll f = ceil - (k - i + l - j);
	      DLOG("gen", encC[i][j], "->", cntC + encP[k][l], "(", f, ")");
	      mcf.add_edge(encC[i][j], cntC + encP[k][l], 1, f);
	    }
	  }
	}
      }
    }
  }
  ll v = mcf.run(source, sink, cntC);
  cout << ceil * cntC - v << endl;

  return 0;
}

