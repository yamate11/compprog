#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;


// @@ !! LIM(debug tree mod)
// --> f:<< debug f:updMaxMin tree f:gcd mod
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
};
#pragma GCC diagnostic pop

template <typename T, typename ADD_T, typename MOD_T>
class RerootTree {
public:
  const Tree& tree;
  const T& unitT;
  const ADD_T& add;   // T -> T -> T
  const MOD_T& mod;   // T -> int -> int -> T
  
  vector<vector<T>> left;
  vector<vector<T>> right;
  vector<T> res;

  T dfs1(int n) {
    vector<T> vec;
    for (ll c : tree.child.at(n)) vec.push_back(mod(dfs1(c), c, n));
    int k = tree.child.at(n).size();
    vector<T>& leftN = left.at(n);
    vector<T>& rightN = right.at(n);
    leftN.resize(k+1);
    leftN.at(0) = unitT;
    for (int i = 0; i < k; i++) {
      leftN.at(i+1) = add(leftN.at(i), vec.at(i));
    }
    rightN.resize(k+1);
    rightN.at(k) = unitT;
    for (int i = k-1; i >= 0; i--) {
      rightN.at(i) = add(vec.at(i), rightN.at(i+1));
    }
    return rightN.at(0);
  }

  void dfs2(int n, const T& parRes) {
    T thisRes = add(right.at(n).at(0), parRes);
    res.at(n) = thisRes;
    for (int i = 0; i < (int)tree.child.at(n).size(); i++) {
      int c = tree.child.at(n).at(i);
      T x = add(parRes, add(left.at(n).at(i), right.at(n).at(i+1)));
      dfs2(c, mod(move(x), n, c));
    }
  }

  RerootTree(const Tree& tree_, auto add_, auto mod_, T unitT_
	     ) : tree(tree_), unitT(unitT_), add(add_), mod(mod_),
		 left(tree.numNodes), right(tree.numNodes),
		 res(tree.numNodes) {
    dfs1(tree.root);
    dfs2(tree.root, unitT);
  }
};


// ---- end tree.cc
// ---- inserted function gcd from util.cc
// g = eGCD(a, b, s, t)  --->  sa + tb = g
ll eGCD(ll a, ll b, ll& s, ll& t) {
  if (a == 0) {
    s = 0;
    t = 1;
    return b;
  }
  ll u = 0;
  ll g = eGCD(b % a, a, t, u);
  s = u - (b / a) * t;
  return g;
}

// gcd(0, x) = x, gcd(-x, y) = gcd(x, y)
ll gcd(ll a, ll b) {
  ll dummy1 = 0;
  ll dummy2 = 0;
  return eGCD(abs(a), abs(b), dummy1, dummy2);
}
// ---- end gcd
// ---- inserted library file mod.cc

ll MOD = 1e9 + 7;
// ll MOD = 998244353;

struct Fp {
  ll val;

  Fp(ll t = 0) {
    if      (t >= MOD)  val = t % MOD;
    else if (t >= 0)    val = t;
    else if (t >= -MOD) val = t + MOD;
    else {
      ll v = t % MOD;
      if (v == 0) val = 0;
      else        val = v + MOD;
    }
  }

  Fp& operator +=(const Fp& t) {
    val += t.val;
    if (val >= MOD) val -= MOD;
    return *this;
  }

  Fp& operator -=(const Fp& t) {
    val -= t.val;
    if (val < 0) val += MOD;
    return *this;
  }

  Fp& operator *=(const Fp& t) {
    val = (val * t.val) % MOD;
    return *this;
  }

  Fp inv() const {
    if (val == 0) {
      cerr << "inv() is called for zero." << endl;
      exit(1);
    }
    ll u = 0;
    ll v = 0;
    eGCD(val, MOD, u, v);
    return Fp(u);
  }

  Fp& operator /=(const Fp& t) {
    return (*this) *= t.inv();
  }

  Fp operator +(const Fp& t) const { return Fp(val) += t; }
  Fp operator -(const Fp& t) const { return Fp(val) -= t; }
  Fp operator *(const Fp& t) const { return Fp(val) *= t; }
  Fp operator /(const Fp& t) const { return Fp(val) /= t; }
  Fp operator -() const { return Fp(-val); }

  bool operator ==(const Fp& t) const { return val == t.val; }
  bool operator !=(const Fp& t) const { return val != t.val; }
  
  operator ll() const { return val; }

};

class Comb {
  int nMax;
  vector<Fp> vFact;
  vector<Fp> vInvFact;
public:
  Comb(int nm) : nMax(nm), vFact(nm+1), vInvFact(nm+1) {
    vFact.at(0) = 1;
    for (int i = 1; i <= nMax; i++) vFact.at(i) = i * vFact.at(i-1);
    vInvFact.at(nMax) = vFact.at(nMax).inv();
    for (int i = nMax; i >= 1; i--) vInvFact.at(i-1) = i * vInvFact.at(i);
  }
  Fp fact(int n) { return vFact.at(n); }
  Fp comb(int n, int r) {
    return vFact.at(n) * vInvFact.at(r) * vInvFact.at(n-r);
  }
  // The number of permutation extracting r from n.
  Fp perm(int n, int r) {
    return vFact.at(n) * vInvFact.at(n-r);
  }
};

// ---- end mod.cc
// @@ !! LIM  -- end mark --

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN(tree) ---- reroot.cc

template<typename T, typename AddT, typename ModT1, typename ModT2>
void reroot(const Tree& tr,
	    AddT add,
	    T unit,
	    vector<T> result,
	    ModT1 f1,   // f1(n, -1, v) should work
	    ModT2 f2
	    ) {
  vector<vector<T>> left(tr.numNodes, vector<T>(1, unit));
  vector<vector<T>> right(tr.numNodes, vector<T>(1, unit));
  vector<T> first(tr.numNodes);
  auto dfs1 = [&](const auto& recF, int n) {
    T gl = unit;
    int k = tr.child.at(n).size();
    for (int i = 0; i < k; i++) {
      int c = tr.child.at(n).at(i);
      recF(recF, c);
      gl = left.at(n).at(i+1) = add(gl, f1(n, c, first.at(c)));
    }
    T gr = unit;
    for (int i = 0; i < k; i++) {
      int c = tr.child.at(n).at(k-1 - i);
      gr = right.at(n).at(i+1) = add(f1(n, c, first.at(c)), gr);
    }
    assert(gl == gr);
    first.at(n) = f2(n, gl);
  };
  dfs1(dfs1, tr.root);
  auto dfs2 = [&](const auto& recF, int n, int p, T tp) -> void {
    T mod_tp = f1(n, p, tp);
    result.at(n) = f2(n, add(first.at(n), mod_tp));
    int k = tr.child.at(n).size();
    for (int i = 0; i < k; i++) {
      int c = tr.child.at(n).at(i);
      T tn = add(add(left.at(n).at(i), right.at(n).at(k-i-1)), mod_tp);
      recF(recF, c, n, f2(n, tn));
    }
  };
  dfs2(dfs2, tr.root, -1);
}

// @@ !! END ---- reroot.cc

int main() {
  ll N, M; cin >> N >> M;
  MOD = M;
  vector<Edge> ve;
  for (ll i = 0; i < N-1; i++) {
    ll a, b; cin >> a >> b; a--; b--;
    ve.emplace_back(a, b);
  }
  Tree tr(move(ve));
  
  auto myadd = [](Fp 

}
