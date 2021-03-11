#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(tree debug)
// --> f:updMaxMin tree f:<< debug
// ---- inserted function updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end updMaxMin
// ---- inserted library file tree.cc

class Edge : public pair<int, int> {
public:
  Edge() : pair<int, int>() {}
  Edge(const int& x, const int& y) : pair<int, int>(x, y) {}
  Edge(istream& stream, int shift) {
    stream >> this->first >> this->second;
    this->first -= shift;
    this->second -= shift;
  }
};

class Tree {

  void init() {
    numNodes = edge.size() + 1;
    parent.resize(numNodes);
    child.resize(numNodes);
    depth.resize(numNodes);
    for (int i = 0; i < numNodes - 1; i++) {
      Edge e = edge.at(i);
      child.at(e.first).push_back(e.second);
      child.at(e.second).push_back(e.first);
    }
    auto dfs = [&](const auto& recF, int n, int p, int l) -> void {
      parent.at(n) = p;
      depth.at(n) = l;
      int ip = -1;
      auto& vecC = child.at(n);
      int numC = vecC.size();
      for (int i = 0; i < numC; i++) {
	int c = vecC.at(i);
	if (c == p) ip = i;
	else        recF(recF, c, n, l+1);
      }
      if (n != root) {
	if (ip < numC - 1) swap(vecC.at(ip), vecC.at(numC - 1));
	vecC.resize(numC - 1);
      }
    };
    dfs(dfs, root, -1, 0);
    parent.at(root) = root;
  }

  vector<vector<int>> pPnt;   
          // pPnt.at(0) == parent
          // pPnt.at(t).at(n) == parent^{2^t}.at(n)
  void preparePPnt() {
    pPnt.push_back(parent);
    for (int t = 0; true; t++) {
      bool done = true;
      vector<int> vec(numNodes);
      for (int n = 0; n < numNodes; n++) {
	int m = pPnt.at(t).at(n);
	vec.at(n) = pPnt.at(t).at(m);
	if (vec.at(n) != m) done = false;
      }
      pPnt.push_back(move(vec));
      if (done) break;
    }
  }

  map<int, map<int, int>> __node2edgeID;

public:
  int numNodes;
  int root;
  vector<int> parent;   // parent.at(root) == root
  vector<vector<int>> child;
  vector<int> depth;
  vector<Edge> edge;

  Tree(vector<Edge>&& edge_, int root_ = 0) : root(root_), edge(move(edge_)) {
    init();
  }

  Tree(const auto& edge_, int root_ = 0) : root(root_), edge() {
    for (Edge e : edge_) edge.push_back(e);
    init();
  }

  // Lowest Common Ancestor
  int lca(int x, int y) {
    if (depth.at(x) > depth.at(y)) swap(x, y);
    int dep = depth.at(x);
    int yy = ancestorDep(y, dep);
    if (x == yy) return x;
    int t = 0;
    for (int q = 1; q < dep; q *= 2) t++;
    for ( ; t >= 0; t--) {
      if (pPnt.at(t).at(x) != pPnt.at(t).at(yy)) {
	x = pPnt.at(t).at(x);
	yy = pPnt.at(t).at(yy);
      }
    }
    return parent.at(x);
  }

  // the path between two nodes
  vector<int> nnpath(int x, int y) {
    vector<int> ret, sub;
    int c = lca(x, y);
    for ( ; x != c; x = parent.at(x)) ret.push_back(x);
    for ( ; y != c; y = parent.at(y)) sub.push_back(y);
    ret.push_back(c);
    for (int i = sub.size() - 1; i >= 0; i--) ret.push_back(sub.at(i));
    return ret;
  }

  // the ancestor of n whose depth is dep
  int ancestorDep(int n, int dep) {
    if (pPnt.size() == 0) preparePPnt();
    int diff = depth.at(n) - dep;
    assert(diff >= 0);
    for (int t = 0; diff > 0; t++) {
      if (diff & (1 << t)) {
	n = pPnt.at(t).at(n);
	diff ^= (1 << t);
      }
    }
    return n;
  }

  int node2edgeID(int n1, int n2) {
    if (__node2edgeID.empty()) {
      for (ll i = 0; i < numNodes - 1; i++) {
	Edge e = edge.at(i);
	__node2edgeID[e.first][e.second] = i;
	__node2edgeID[e.second][e.first] = i;
      }
    }
    auto it1 = __node2edgeID.find(n1);
    if (it1 == __node2edgeID.end()) return -1;
    auto it2 = it1->second.find(n2);
    if (it2 == it1->second.end()) return -1;
    return it2->second;
  }
  Edge node2edge(int n1, int n2) { return edge.at(node2edgeID(n1, n2)); }
  

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-but-set-variable"    
  // diameter
  //   not efficient at all.  fixed-rooted tree is not suitable....
  int diameter() {
  // tuple<int, int, int> diameter() {
    int maxDepth = 0;
    int mdArg1 = -1;
    for (int i = 0; i < numNodes; i++) {
      if (updMax(maxDepth, depth.at(i))) mdArg1 = i;
    }
    Tree tr2(edge, mdArg1);
    maxDepth = 0;
    int mdArg2;
    for (int i = 0; i < numNodes; i++) {
      if (updMax(maxDepth, tr2.depth.at(i))) mdArg2 = i;
    }
    // Return mdArg1 and mdArg2 if you need endpoints as well.
    // return make_tuple(maxDepth, mdArg1, mdArg2);
    return maxDepth;
  }
#pragma GCC diagnostic pop

};

template <typename T>
vector<T> reroot(const Tree& tree, const T& unit, auto add, auto mod) {
  vector<T> result(tree.numNodes);
  vector<T> sum(tree.numNodes);
  vector<vector<T>> sum_excl(tree.numNodes);
  
  auto dfs1 = [&](const auto& recF, int n) -> void {
    const auto& cld = tree.child.at(n);
    int k = cld.size();
    vector<T> right(k+1), m(k+1);
    T g = right.at(k) = unit;
    for (int i = k-1; i >= 0; i--) {
      int c = cld.at(i);
      recF(recF, c);
      m.at(i) = mod(sum.at(c), n, c);
      right.at(i) = g = add(m.at(i), g);
    }
    sum.at(n) = g;
    T gp = unit;
    sum_excl.at(n).resize(k);
    for (int i = 0; i < k; i++) {
      sum_excl.at(n).at(i) = add(gp, right.at(i+1));
      gp = add(gp, m.at(i));
    }
  };
  dfs1(dfs1, tree.root);

  auto dfs2 = [&](const auto& recF, int n, T t) -> void {
    result.at(n) = add(sum.at(n), t);
    const auto& cld = tree.child.at(n);
    int k = cld.size();
    for (int i = 0; i < k; i++) {
      int c = cld.at(i);
      recF(recF, c, mod(add(sum_excl.at(n).at(i), t), c, n));
    }
  };
  dfs2(dfs2, tree.root, unit);
  
  return result;
}

// ---- end tree.cc
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

  auto solve = [&](ll N, ll M, Tree& tr, auto& P, auto& H) -> bool {
    vector<ll> ap(N);
    auto dfs = [&](auto rF, ll n) -> ll {
      ll sum = P.at(n);
      for (ll c : tr.child.at(n)) {
	sum += rF(rF, c);
      }
      ap.at(n) = sum;
      return sum;
    };
    dfs(dfs, 0);
    vector<ll> happy(N);
    for (ll i = 0; i < N; i++) {
      ll a = ap.at(i); 
      ll b = H.at(i);
      if (a < b || a + b < 0 || (a + b) % 2 != 0) return false;
      happy.at(i) = (a + b) / 2;
    }
    for (ll i = 0; i < N; i++) {
      ll sum = 0;
      for (ll c : tr.child.at(i)) {
	sum += happy.at(c);
      }
      if (sum > happy.at(i)) return false;
    }
    DLOG("ap=", ap);
    DLOG("happy=", happy);
    return true;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll n, m; cin >> n >> m;
    vector<ll> p(n), h(n);
    for (ll i = 0; i < n; i++) cin >> p.at(i);
    for (ll i = 0; i < n; i++) cin >> h.at(i);
    vector<Edge> ve;
    for (ll i = 0; i < n-1; i++) {
      ll a, b; cin >> a >> b; a--; b--;
      ve.emplace_back(a, b);
    }
    Tree tr(move(ve));
    cout << (solve(n, m, tr, p, h) ? "YES\n" : "NO\n");
  }

  return 0;
}

