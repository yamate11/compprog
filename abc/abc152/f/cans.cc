#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// --- DEBUG begin --- cut here ---
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

// operator<< definitions for some classes

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p) {
  os << "(" << p.first << ", " << p.second << ")";
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
// --- DEBUG end --- cut here ---

#if DEFINED_POWER
compilation error: util.cc should be included first
#else
#define DEFINED_POWER 1
template<typename T>
T power(T a, ll b) {
  T twoPow = a;
  T rv = 1;
  while (b > 0) {
    if (b & 1LL) rv *= twoPow;
    twoPow *= twoPow;
    b >>= 1;
  }
  return rv;
}
#endif


// --- TREE begin --- cut here ---

class Tree {

  void init(auto fGet) {
    for (int i = 0; i < numNodes - 1; i++) {
      auto p = fGet(i);
      int x = p.first;
      int y = p.second;
      edge.push_back(p);
      node2edge[x][y] = i;
      node2edge[y][x] = i;
    }
    auto dfs = [&](const auto& recF, int n, int p, int l) -> void {
      parent.at(n) = p;
      depth.at(n) = l;
      for (auto c : node2edge[n]) {
	if (c.first == p) continue;
	child.at(n).push_back(c.first);
	recF(recF, c.first, n, l+1);
      }
    };
    parent.resize(numNodes);
    child.resize(numNodes);
    depth.resize(numNodes);
    dfs(dfs, root, -1, 0);
    parent.at(root) = root;
  }

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

public:
  int numNodes;
  int root;
  vector<int> parent;   // parent.at(root) == root
  vector<vector<int>> child;
  vector<int> depth;
  vector<vector<int>> pPnt;   
  // pPnt.at(0) == parent
  // pPnt.at(t).at(n) == parent^{2^t}.at(n)
  vector<pair<int, int>> edge;
  map<int, map<int, int>> node2edge;

  enum CType { none, zero_indexed, one_indexed };

  // N ... the number of nodes
  // edges ... vector<integer, integer>.  Should be zero-indexed
  Tree(auto edges, int _root = 0) : numNodes(edges.size() + 1), root(_root) {
    auto getF = [&](int i) -> pair<int, int> { return edges[i]; };
    init(getF);
  }

  Tree(istream& stream, CType mode = one_indexed) : root(0) {
    if (mode == none) {
      cerr << "Sorry, not implemented.\n";
      assert(0);
    }
    stream >> numNodes;
    auto getF = [&](int i) -> pair<int, int> {
      int x, y; stream >> x >> y;
      if (mode == one_indexed) { x--; y--; }
      return make_pair(x, y);
    };
    init(getF);
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

};

// --- TREE end --- cut here ---


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  Tree tr(cin);
  ll N = tr.numNodes;
  auto parentSeq = [&](ll n) -> ll {
    ll ret = 0;
    for ( ; n > 0; n = tr.parent.at(n)) {
      ret |= (1LL << tr.node2edge.at(n).at(tr.parent.at(n)));
    }
    return ret;
  };
  
  ll M; cin >> M;
  vector<ll> conn(M);
  for (ll j = 0; j < M; j++) {
    ll u, v; cin >> u >> v; u--; v--;
    conn.at(j) = parentSeq(u) ^ parentSeq(v);
  }
  ll cnt = 0;
  for (ll x = 1; x < (1L << M); x++) {
    ll sunion = 0;
    for (ll i = 0; i < M; i++) {
      if (!(x & (1L << i))) continue;
      sunion |= conn.at(i);
    }
    ll c = __builtin_popcountll(sunion);
    DLOG("x, c", x, c);
    ll thisCnt = power<ll>(2, N-1 - c);
    if (__builtin_popcountll(x) % 2 == 1) cnt += thisCnt;
    else                                  cnt -= thisCnt;
  }
  cout << power<ll>(2, N-1) - cnt << endl;

  return 0;
}

