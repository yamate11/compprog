#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug)
// --> f:<< debug minCostFlow
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

template <typename T>
ostream& operator<< (ostream& os, const multiset<T>& v) {
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

// ---- end debug.cc
// @@ !! LIM  -- end mark --

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
      f -= d;
      retval += d * h.at(sink);
      DLOG("flow vol=", d, "accumulated cost=", retval);
      for (int v = sink; v != source; v = prevv.at(v)) {
	DLOG("  ", prevv.at(v), "->", v);
	Edge& e = edges.at(prevv.at(v)).at(preve.at(v));
	e.cap -= d;
	edges.at(v).at(e.rev).cap += d;
      }
    }
    return retval;
  }

};

// ---- end minCostFlow.cc

ll mypow(ll b, ll i) {
  if (i == 0) return 0;
  if (i == 1) return b;
  if (i == 2) return b * b;
  if (i == 3) return b * b * b;
  assert(0);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector A(N, 0LL), B(N, 0LL), R(3, 0LL);
  for (ll i = 0; i < N; i++) cin >> A.at(i);
  for (ll i = 0; i < N; i++) cin >> B.at(i);
  for (ll i = 0; i < 3; i++) cin >> R.at(i);
  
  MinCostFlow mcf(1 + 3 + N + 1);
  for (ll i = 0; i < 3; i++) {
    mcf.add_edge(0, 1+i, M, 0);
    DLOG("edge1", 0, 1+i, M, 0);
    for (ll j = 0; j < N; j++) {
      ll c = (A.at(j) * mypow(B.at(j), i+1)) % R.at(i);
      mcf.add_edge(1+i, 4+j, 1, -c);
      DLOG("edge2", 1+i, 4+j, 1, -c);
    }
  }
  for (ll j = 0; j < N; j++) {
    for (ll i = 0; i < 3; i++) {
      ll c = A.at(j) * (mypow(B.at(j), i+1) - mypow(B.at(j), i));
      mcf.add_edge(4+j, 4+N, 1, c);
      DLOG("edge3", 4+j, 4+N, 1, c);
    }
  }
  ll total = mcf.run(0, 4+N, 3*M);
  cout << -total << endl;

  return 0;
}
