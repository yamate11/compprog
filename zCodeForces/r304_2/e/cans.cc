#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(dinic debug cmpNaive)
// --> dinic f:<< debug cmpNaive
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

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig) {
  deque<T, T2> que(orig);
  bool first = true;
  os << '[';
  while (!que.empty()) {
    T x = que.front(); que.pop_front();
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
// ---- inserted library file cmpNaive.cc

const string end_mark("^__=end=__^");
const string end_file_mark("^__=end_file=__^");

int naive(istream& cin, ostream& cout);
int body(istream& cin, ostream& cout);

void cmpNaive() {
  while (true) {
    string s;
    getline(cin, s);
    bool run_body;
    if (s.at(0) == 'Q') {
      return;
    }else if (s.at(0) == 'B') {
      run_body = true;
    }else if (s.at(0) == 'N') {
      run_body = false;
    }else {
      cerr << "Unknown body/naive specifier.\n";
      exit(1);
    }
    string input_s;
    while (true) {
      getline(cin, s);
      if (s == end_mark) break;
      input_s += s;
      input_s += "\n";
    }
    stringstream ss_in(move(input_s));
    stringstream ss_out;
    if (run_body) {
      body(ss_in, ss_out);
    }else {
      naive(ss_in, ss_out);
    }
    cout << ss_out.str() << end_mark << endl;
  }
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

#if CMPNAIVE
  if (argc == 2) {
    if (strcmp(argv[1], "cmpNaive") == 0) {
      cmpNaive();
    }else if (strcmp(argv[1], "naive") == 0) {
      naive(cin, cout);
    }else {
      cerr << "Unknown argument.\n";
      exit(1);
    }
  }else {
#endif
    body(cin, cout);
#if CMPNAIVE
  }
#endif
  return 0;
}

/*
int naive(istream& cin, ostream& cout) {
  return 0;
}
int body(istream& cin, ostream& cout) {
  return 0;
}
*/

// ---- end cmpNaive.cc
// @@ !! LIM  -- end mark --

int naive(istream& cin, ostream& cout) {
  ll n, m; cin >> n >> m;
  vector<ll> A(n), B(n);
  for (ll i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (ll i = 0; i < n; i++) {
    cin >> B[i];
  }
  vector<ll> P(m), Q(m);
  for (ll i = 0; i < m; i++) {
    ll p, q; cin >> p >> q; p--; q--;
    P[i] = p;
    Q[i] = q;
  }
  string s; cin >> s;
  if (s == "YES") {
    for (ll i = 0; i < n * n; i++) {
      ll a; cin >> a;
    }
  }
  cout << "OK\n";

  return 0;
}

struct MyExc : exception {};

int body(istream& cin, ostream& cout) {

  try {
    ll n, m; cin >> n >> m;
    vector<ll> A(n), B(n);
    ll sa = 0, sb = 0;
    for (ll i = 0; i < n; i++) {
      cin >> A[i];
      sa += A[i];
    }
    for (ll i = 0; i < n; i++) {
      cin >> B[i];
      sb += B[i];
    }
    if (sa != sb) throw MyExc();
    vector<ll> P(m), Q(m);
    for (ll i = 0; i < m; i++) {
      ll p, q; cin >> p >> q; p--; q--;
      P[i] = p;
      Q[i] = q;
    }
    ll big = 1e10;
    Dinic dinic(2 + n + n + n + 2 * m, 0, 1);
    vector eidx(n, vector(n, -1LL));
    {
      ll source = 0;
      ll sink = 1;
      auto v1 = [&](ll i) -> ll { return 2 + i; };
      auto v2 = [&](ll i) -> ll { return 2 + n + i; };
      auto ei = [&](ll i) -> ll { return 2 + n + n + i; };
      auto ed1 = [&](ll i) -> ll { return 2 + n + n + n + i; };
      auto ed2 = [&](ll i) -> ll { return 2 + n + n + n + m + i; };
      for (ll i = 0; i < n; i++) {
	dinic.add_edge(source, v1(i), A[i]);
	dinic.add_edge(v2(i), sink, B[i]);
	eidx[i][i] = dinic.add_edge(v1(i), ei(i), big);
	dinic.add_edge(ei(i), v2(i), big);
      }
      for (ll i = 0; i < m; i++) {
	eidx[P[i]][Q[i]] = dinic.add_edge(v1(P[i]), ed1(i), big);
	dinic.add_edge(ed1(i), v2(Q[i]), big);
	eidx[Q[i]][P[i]] = dinic.add_edge(v1(Q[i]), ed2(i), big);
	dinic.add_edge(ed2(i), v2(P[i]), big);
      }
    }
    ll flow = dinic.run();
    if (flow != sa) throw MyExc();

    
#if DEBUG
    DLOG("///");
    for (ll i = 0; i < (ll)dinic.edges.size(); i++) {
      DLOG("  i=", i);
      for (auto& e : dinic.edges[i]) {
	DLOG("e.dst=", e.dst, "e.cap=", e.cap, "e.rev=", e.rev);
      }
    };
    DLOG("///");
#endif

#if DEBUG
    for (ll i = 0; i < (ll)dinic.edges.size(); i++) {
      DLOG("** ", i);
      for (Edge e : dinic.edges[i]) {
	Edge r = dinic.edges[e.dst][e.rev];
	DLOG("e", i, "->", e.dst, ";", r.cap);
      }
    }
#endif

    cout << "YES\n";
    for (ll i = 0; i < n; i++) {
      for (ll j = 0; j < n; j++) {
	if (j > 0) cout << " ";
	ll ei = eidx[i][j];
	ll fl = ei < 0 ? 0 : dinic.eflow(ei);
	// DLOG("** i=", i, "j=", j, "eidx[i][j]=", eidx[i][j], "flow=", fl);
	cout << fl;
      }
      cout << "\n";
    }
    

  }catch(const MyExc& e) {
    cout << "NO\n";
  }

  return 0;
}

