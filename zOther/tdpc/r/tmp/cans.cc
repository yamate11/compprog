#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <atcoder/scc>
// using namespace atcoder;

// @@ !! LIM(debug scc f:perfmeas)

// ---- inserted function f:<< from util.cc
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

// ---- end f:<<

// ---- inserted library file debug.cc
template <class... Args>
string dbgFormat(const char* fmt, Args... args) {
  size_t len = snprintf(nullptr, 0, fmt, args...);
  char buf[len + 1];
  snprintf(buf, len + 1, fmt, args...);
  return string(buf);
}

template <class Head>
void dbgLog(bool with_nl, Head&& head) {
  cerr << head;
  if (with_nl) cerr << endl;
}

template <class Head, class... Tail>
void dbgLog(bool with_nl, Head&& head, Tail&&... tail)
{
  cerr << head << " ";
  dbgLog(with_nl, forward<Tail>(tail)...);
}

#if DEBUG
  #define DLOG(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL(func, ...) func(__VA_ARGS__)
#else
  #define DLOG(...)
  #define DLOGNNL(...)
  #define DFMT(...)
  #define DCALL(func, ...)
#endif

/*
#if DEBUG_LIB
  #define DLOG_LIB(...)        dbgLog(true, __VA_ARGS__)
  #define DLOGNNL_LIB(...)     dbgLog(false, __VA_ARGS__)
  #define DFMT_LIB(...)        cerr << dbgFormat(__VA_ARGS__) << endl
  #define DCALL_LIB(func, ...) func(__VA_ARGS__)
#else
  #define DLOG_LIB(...)
  #define DFMT_LIB(...)
  #define DCALL_LIB(func, ...)
#endif
*/

#define DUP1(E1)       #E1 "=", E1
#define DUP2(E1,E2)    DUP1(E1), DUP1(E2)
#define DUP3(E1,...)   DUP1(E1), DUP2(__VA_ARGS__)
#define DUP4(E1,...)   DUP1(E1), DUP3(__VA_ARGS__)
#define DUP5(E1,...)   DUP1(E1), DUP4(__VA_ARGS__)
#define DUP6(E1,...)   DUP1(E1), DUP5(__VA_ARGS__)
#define DUP7(E1,...)   DUP1(E1), DUP6(__VA_ARGS__)
#define DUP8(E1,...)   DUP1(E1), DUP7(__VA_ARGS__)
#define DUP9(E1,...)   DUP1(E1), DUP8(__VA_ARGS__)
#define DUP10(E1,...)   DUP1(E1), DUP9(__VA_ARGS__)
#define DUP11(E1,...)   DUP1(E1), DUP10(__VA_ARGS__)
#define DUP12(E1,...)   DUP1(E1), DUP11(__VA_ARGS__)
#define GET_MACRO(_1,_2,_3,_4,_5,_6,_7,_8,_9,_10,_11,_12,NAME,...) NAME
#define DUP(...)          GET_MACRO(__VA_ARGS__, DUP12, DUP11, DUP10, DUP9, DUP8, DUP7, DUP6, DUP5, DUP4, DUP3, DUP2, DUP1)(__VA_ARGS__)
#define DLOGK(...)        DLOG(DUP(__VA_ARGS__))
#define DLOGKL(lab, ...)  DLOG(lab, DUP(__VA_ARGS__))

#if DEBUG_LIB
  #define DLOG_LIB   DLOG
  #define DLOGK_LIB  DLOGK
  #define DLOGKL_LIB DLOGKL
#endif

// ---- end debug.cc

double get_time_sec();

// ---- inserted library file scc.cc
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
    // vector<set<int>> compRev;
    auto dfs2 = [&](const auto& recF, int n, int ccID) -> void {
      DLOGKL("dfs2", n, ccID);
      ccForNode.at(n) = ccID;
      nodesInCC.at(ccID).push_back(n);
      for (int m : revArr.at(n)) {
	int y = ccForNode.at(m);
	if (y == -1) {
	  recF(recF, m, ccID);
	}else if (y == ccID) {
	  // do nothing
	}else {
	  // compRev.at(ccID).insert(y);
	}
      }
    };
    int ccID = 0;
    for (int f = (int)finOrder.size() -1; f >= 0; f--) {
      int n = finOrder.at(f);
      if (ccForNode.at(n) == -1) {
	nodesInCC.push_back(vector<int>());
	// compRev.push_back(set<int>());
	dfs2(dfs2, n, ccID++);
      }
    }
    numComp = ccID;
    /*
    cArr.resize(numComp);
    cRevArr.resize(numComp);
    for (int i = 0; i < numComp; i++) {
      auto& s = compRev.at(i);
      cRevArr.at(i) = vector<int>(s.begin(), s.end());
      for (int x : cRevArr.at(i)) cArr.at(x).push_back(i);
    }
    */
  }

  // _size is the number of nodes.
  // Edges should be numbered from 0 to _size - 1.
  // _edges is the vector of pair of int and int.
  SCC(int _size, vector<Edge>& _edges)
    : size(_size) { init(_edges); }
  SCC(int _size, vector<Edge>&& _edges)
    : size(_size) { init(_edges); }
};
// ---- end scc.cc

// ---- inserted function f:perfmeas from util.cc

// For performance measurement.
// Returns seconds from the epoch in double
double get_time_sec() {
  using namespace std::chrono;
  return static_cast<double>(duration_cast<nanoseconds>(steady_clock::now().time_since_epoch()).count())/1000000000;
}

// ---- end f:perfmeas

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<Edge> edges;
  ll N, M; cin >> N >> M;
  for (ll i = 0; i < M; i++) {
    ll x, y; cin >> x >> y;
    edges.emplace_back(x, y);
  }
  auto edges2 = edges;

  double t1 = get_time_sec();
  SCC scc(N, move(edges));
  double t2 = get_time_sec();

  double t3 = get_time_sec();
  atcoder::scc_graph atscc(N);
  double t4 = get_time_sec();
  for (ll i = 0; i < M; i++) {
    atscc.add_edge(edges2[i].first, edges2[i].second);
  }
  double t5 = get_time_sec();
  auto g = atscc.scc();
  double t6 = get_time_sec();

  

  cout << t2 - t1 << endl;

  cout << endl;

  cout << t4 - t3 << endl;
  cout << t5 - t4 << endl;
  cout << t6 - t5 << endl;

  cout << g[0][0] << scc.ccForNode[0] << endl;

  return 0;
}

