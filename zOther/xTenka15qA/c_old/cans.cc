#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug minCostFlow board)
// --> f:<< debug minCostFlow board
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
// ---- inserted library file board.cc

struct BrdIdx {
  int r;
  int c;
  BrdIdx(int r_, int c_) : r(r_), c(c_) {}

  BrdIdx& operator +=(const BrdIdx& o) { r += o.r; c += o.c; return *this; }
  BrdIdx& operator -=(const BrdIdx& o) { r -= o.r; c -= o.c; return *this; }
  BrdIdx& operator *=(int k) { r *= k; c *= k; return *this; }
  BrdIdx operator +(const BrdIdx& o) const { return BrdIdx(*this) += o; }
  BrdIdx operator -(const BrdIdx& o) const { return BrdIdx(*this) -= o; }
  BrdIdx operator *(int k) const { return BrdIdx(*this) *= k; }
  BrdIdx operator -() const { return (*this) * (-1); }

  bool operator ==(const BrdIdx& o) const { return r == o.r && c == o.c; }
  bool operator !=(const BrdIdx& o) const { return !((*this) == o); }
  bool operator <(const BrdIdx& o) const {
    return r < o.r || (r == o.r && c < o.c); }
  bool operator <=(const BrdIdx& o) const {
    return r < o.r || (r == o.r && c <= o.c); }
  bool operator >(const BrdIdx& o) const { return o < *this; }
  bool operator >=(const BrdIdx& o) const { return o <= *this; }

  BrdIdx rotateQ() { return BrdIdx(-c, r); } // counter-clockwise

  static vector<BrdIdx> nbr4, nbr5, nbr8, nbr9;
};

vector<BrdIdx>
  BrdIdx::nbr4({      {1,0},      {0,1},       {-1,0},        {0,-1}       }),
  BrdIdx::nbr5({{0,0},{1,0},      {0,1},       {-1,0},        {0,-1}       }),
  BrdIdx::nbr8({      {1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}}),
  BrdIdx::nbr9({{0,0},{1,0},{1,1},{0,1},{-1,1},{-1,0},{-1,-1},{0,-1},{1,-1}});

BrdIdx operator *(int k, const BrdIdx& o) { return o * k; }
ostream& operator <<(ostream& os, const BrdIdx& i) {
  os << "(" << i.r << "," << i.c << ")";
  return os;
}

template <typename T>
struct Board {

  void readData(istream& is) {
    for (int i = 0; i < nR; i++) {
      for (int j = 0; j < nC; j++) {
	T t; is >> t;
	set(i, j, t);
      }
    }
  }

  const int nR;
  const int nC;
  const T def;
  vector<T> data;
  int dispWidth;

  Board(int nR_, int nC_, T def_)
    : nR(nR_), nC(nC_), def(def_), data(nR*nC, def), dispWidth(0) {}
  Board(istream& is, int nR_, int nC_, T def_)
    : nR(nR_), nC(nC_), def(def_), data(nR*nC, def), dispWidth(0) {
    readData(is);
  }
  BrdIdx bIdx(int r = 0, int c = 0) { return BrdIdx(r, c); }
  int enc(int r, int c) const { return nC * r + c; }
  int enc(const BrdIdx& bi) const { return nC * bi.r + bi.c; }
  pair<int, int> dec(int i) const { return make_pair(i / nC, i % nC); }
  BrdIdx decIdx(int i) const { return BrdIdx(i / nC, i % nC); }
  bool in(int r, int c) const { return 0 <= r && r < nR && 0 <= c && c < nC; }
  bool in(const BrdIdx& bi) const { return in(bi.r, bi.c); }
  const T get(int r, int c) const {
    return in(r, c) ? data.at(enc(r, c)) : def;
  }
  const T get(const BrdIdx& bi) const { return get(bi.r, bi.c); }
  // Note: returning a reference (const T& get(...)) is problematic
  //       when T is bool.  (vector<bool> is implemented in a specific way)
  void set(int r, int c, T t) { if (in(r, c)) data.at(enc(r, c)) = t; }
  void set(const BrdIdx& bi, T t) { set(bi.r, bi.c, t); }
  void setDispWidth(int w) { dispWidth = w; }
};

template<typename T>
ostream& operator <<(ostream& os, const Board<T>& brd) {
  for (int r = 0; r < brd.nR; r++) {
    for (int c = 0; c < brd.nC; c++) {
      os << setw(brd.dispWidth) << brd.get(r, c);
    }
    if (r < brd.nR - 1) os << "\n";
  }
  return os;
}

// ---- end board.cc
// @@ !! LIM  -- end mark --




#if 0
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
    DLOG("ae", u, v, cap, cost);
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
#if DEBUG
      DLOG("flow =", d);
      for (int v = sink; v != source; v = prevv.at(v)) {
	DLOG("  ", prevv.at(v), "->", v);
      }
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
#endif


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll M, N; cin >> M >> N;
  Board<ll> brd(M, N, -1);
  for (ll r = 0; r < M; r++) {
    for (ll c = 0; c < N; c++) {
      ll a; cin >> a;
      brd.set(r, c, a);
    }
  }
  auto eff = [](ll x) -> bool { return x == 1 || x == 2; };
  vector<BrdIdx> veff;
  map<BrdIdx, ll> mp;
  for (ll r = 0; r < M; r++) {
    for (ll c = 0; c < N; c++) {
      ll b; cin >> b;
      BrdIdx bi(r, c);
      ll a = brd.get(bi);
      ll x = (a << 1) | b;
      brd.set(bi, x);
      if (eff(x)) {
	mp[bi] = veff.size();
	veff.push_back(bi);
      }
    }
  }
  DLOG("veff=", veff);
  using StA = pair<BrdIdx, BrdIdx>;
  vector<StA> dom;
  auto op = [&](BrdIdx bi, BrdIdx bj) -> void {
    if (!brd.in(bj)) return;
    ll x = brd.get(bi);
    ll y = brd.get(bj);
    DLOG("bi=", bi, "bj=", bj, "x=", x, "y=", y);
    if (!eff(x) || !eff(y) || x == y) return;
    dom.emplace_back(bi, bj);
  };
  for (ll r = 0; r < M; r++) {
    for (ll c = 0; c < N; c++) {
      BrdIdx bi(r, c);
      op(bi, BrdIdx(r+1, c));
      op(bi, BrdIdx(r, c+1));
    }
  }
  DLOG("dom=", dom);
  ll esize = veff.size();
  ll dsize = dom.size();
  MinCostFlow mcf(2 + esize + dsize);
  for (ll i = 0; i < esize; i++) {
    mcf.add_edge(0, 2 + i, 1, 2);
    mcf.add_edge(2 + i, 1, 1, 0);
  }
  for (ll i = 0; i < dsize; i++) {
    const auto& [bi, bj] = dom.at(i);
    ll idx = 2 + esize + i;
    mcf.add_edge(0, idx, 2, 0);
    mcf.add_edge(idx, 2 + mp.at(bi), 1, 1);
    mcf.add_edge(idx, 2 + mp.at(bj), 1, 1);
  }
  DLOG("esize=", esize);
  ll ans = mcf.run(0, 1, esize);
  assert(ans % 2 == 0);
  cout << ans / 2 << endl;

  return 0;
}

