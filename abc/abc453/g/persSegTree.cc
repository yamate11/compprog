#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM(random debug)

// ---- inserted library file random.cc


struct Random {
  static random_device the_random_device;
  mt19937_64 rng;

  Random() : rng(the_random_device()) {}
  Random(unsigned seed) : rng(seed) {}
  
  ll range(ll i, ll j) {
    if (i >= j) {
      throw runtime_error("Random.range: invalid range");
    }
    uniform_int_distribution<ll> dist(i, j - 1);
    return dist(rng);
  }

  double rand(double a, double b) {
    if (!(a <= b)) {
      throw std::runtime_error("Random.rand: invalid range");
    }
    std::uniform_real_distribution<double> dist(a, b);
    return dist(rng);
  }

  pair<ll, ll> select2(ll i, ll j) {
    if (j - i < 2) {
      throw std::runtime_error("Random.select2: range too small");
    }
    ll x = range(i, j);
    ll y = range(i, j - 1);
    if (y >= x) ++y;
    if (x > y) swap(x, y);
    return {x, y};
  }

  template<typename RandomIt>
  void shuffle(RandomIt first, RandomIt last) { std::shuffle(first, last, rng); }

};

random_device Random::the_random_device;

// ---- end random.cc

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

template <typename T1, typename T2, typename T3, typename T4, typename T5>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5>& t);

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t);

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

template <typename T, size_t N>
ostream& operator<< (ostream& os, const array<T, N>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const unordered_set<T, C>& v);

template <typename T, typename C>
ostream& operator<< (ostream& os, const multiset<T, C>& v);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const map<T1, T2, C>& mp);

template <typename T1, typename T2, typename C>
ostream& operator<< (ostream& os, const unordered_map<T1, T2, C>& mp);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const queue<T, T2>& orig);

template <typename T, typename T2>
ostream& operator<< (ostream& os, const deque<T, T2>& orig);

template <typename T, typename T2, typename T3>
ostream& operator<< (ostream& os, const priority_queue<T, T2, T3>& orig);

template <typename T>
ostream& operator<< (ostream& os, const stack<T>& st);

#if __cplusplus >= 201703L
template <typename T>
ostream& operator<< (ostream& os, const optional<T>& t);
#endif

ostream& operator<< (ostream& os, int8_t x);

ostream& operator<< (ostream& os, const __int128& x);

// definitions

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

template <typename T1, typename T2, typename T3, typename T4, typename T5>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ", " << get<4>(t) << ")";
  return os;
}

template <typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4,T5,T6>& t) {
  os << "(" << get<0>(t) << ", " << get<1>(t)
     << ", " << get<2>(t) << ", " << get<3>(t) << ", " << get<4>(t) << ", " << get<5>(t) << ")";
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

template <typename T, size_t N>
ostream& operator<< (ostream& os, const array<T, N>& v) {
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

// for Enum type; just displays ordinals.
template <typename E>
typename std::enable_if<std::is_enum<E>::value, std::ostream&>::type
operator<<(std::ostream& os, E e) {
    return os << static_cast<typename std::underlying_type<E>::type>(e);
}

// This is a very ad-hoc implementation...
// Known problem: "1 << 127" cannot be handled.
ostream& operator<<(ostream& os, const __int128& v) {
  unsigned __int128 a = v < 0 ? -v : v;
  ll i = 0;
  string s(64, ' ');
  if (v == 0) {
    s[i++] = '0';
  }else {
    while (a > 0) {
      s[i++] = '0' + (char)(a % 10);
      a /= 10;
    }
  }
  if (v < 0) {
    s[i++] = '-';
  }
  s.erase(s.begin() + i, s.end());
  reverse(s.begin(), s.end());
  os << s;
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

// @@ !! LIM -- end mark --

template <typename DAT, typename OP,
	  typename ADD_t, typename COMP_t, typename APPL_t, bool lazy>
struct GenPersSegTree {
  
  struct NodeOrd {
    NodeOrd* left;
    NodeOrd* right;
    DAT val;
  };
  
  struct NodeLazy {
    NodeLazy* left;
    NodeLazy* right;
    DAT val;
    OP susp;
  };

  using Node = conditional_t<lazy, NodeLazy, NodeOrd>;

  DAT unit_dat;
  OP unit_op;
  ADD_t add;
  COMP_t comp;
  APPL_t appl;
  int size = 0;

  Node* newNode() {
    if constexpr (lazy) return new Node(nullptr, nullptr, unit_dat, unit_op);
    else                return new Node(nullptr, nullptr, unit_dat);
  };

  Node* newNodeVal(DAT val) {
    Node* nd = newNode();
    nd->val = move(val);
    return nd;
  }

  Node* newNodeTwo(Node* nd1, Node* nd2) {
    Node* nd = newNode();
    nd->left = nd1;
    nd->right = nd2;
    nd->val = add(nd1->val, nd2->val);
    return nd;
  }

  Node* fromVector(const vector<DAT>& vec) {
    auto sub = [&](auto rF, ll lo, ll hi) -> Node* {
      if (lo + 1 == hi) {
        return newNodeVal(vec[lo]);
      }else {
        ll mid = (lo + hi) / 2;
        return newNodeTwo(rF(rF, lo, mid), rF(rF, mid, hi));
      }
    };
    size = ssize(vec);
    return sub(sub, 0, size);
  }

  DAT query(Node* root, ll rngLo, ll rngHi) const {
    if (rngHi <= rngLo) return unit_dat;
    auto sub = [&](auto rF, Node* nd, ll lo, ll hi) -> DAT {
      if (rngHi <= lo or  hi <= rngLo) return unit_dat;
      if (rngLo <= lo and hi <= rngHi) return nd->val;
      ll mid = (lo + hi) / 2;
      DAT ret;
      if constexpr (lazy) ret = appl(nd->susp, add(rF(rF, nd->left, lo, mid), rF(rF, nd->right, mid, hi)));
      else                ret =                add(rF(rF, nd->left, lo, mid), rF(rF, nd->right, mid, hi));
      return ret;
    };
    return sub(sub, root, 0, size);
  }

  Node* _push(Node* nd, const OP& op) {
    if constexpr (lazy) {
      if (op == unit_op) return nd;
      return new Node(nd->left, nd->right, appl(op, nd->val), comp(op, nd->susp));
    }else {
      return nd;
    }
  }

  Node* _func_update_set(Node* root, ll rngLo, ll rngHi, auto fin) {
    auto sub = [this, &rngLo, &rngHi, &fin](auto rF, Node* nd, ll lo, ll hi, const OP& op) -> Node* {
      if (rngHi <= lo or  hi <= rngLo) return _push(nd, op);
      if (rngLo <= lo and hi <= rngHi) return fin(nd, op);
      ll mid = (lo + hi) / 2;
      OP comped;
      if constexpr (lazy) comped = comp(op, nd->susp);
      else                comped = OP{};
      Node* ndL = rF(rF, nd->left,  lo,  mid,      comped );
      Node* ndR = rF(rF, nd->right, mid, hi,  move(comped));
      // Make sure that "move(comped)" is called after "comped".
      return newNodeTwo(ndL, ndR);
    };
    return sub(sub, root, 0, size, unit_op);
  }

  Node* update(Node* root, ll rngLo, ll rngHi, const OP& op_asked) {
    static_assert(lazy, "update() only supports for lazy trees.");
    return _func_update_set(root, rngLo, rngHi,
                            [this, &op_asked](Node* nd, const OP& op) { return _push(nd, comp(op_asked, op)); });
  }

  Node* set(Node* root, ll i, DAT t) {
    return _func_update_set(root, i, i + 1, [this, &t](Node*, const OP&) { return newNodeVal(move(t)); });
  }
};

template<typename DAT>
auto make_pers_seg_tree(DAT unit_dat, auto add, const vector<DAT>& init_dat) {
  auto st = GenPersSegTree<DAT, monostate, decltype(add), monostate, monostate, false
                           >(unit_dat, {}, add, {}, {}, 0);
  auto root = st.fromVector(init_dat);
  return make_pair(st, root);
}

template<typename DAT, typename OP>
auto make_pers_seg_tree_lazy(DAT unit_dat, OP unit_op, auto add, auto comp, auto appl, const vector<DAT>& init_dat) {
  auto st = GenPersSegTree<DAT, OP, decltype(add), decltype(comp), decltype(appl), true
                           >(unit_dat, unit_op, add, comp, appl, 0);
  auto root = st.fromVector(init_dat);
  return make_pair(st, root);
}


template <typename DAT, typename OP, typename ADD_t, typename APPL_t>
struct NaiveImpl {
  
  DAT unit_dat;
  OP unit_op;
  ADD_t add;
  APPL_t appl;
  vector<vector<DAT>> data;
  
  int fromVector(const vector<DAT>& vec) {
    data.push_back(vec);
    return ssize(data) - 1;
  }

  DAT query(int idx, ll rngLo, ll rngHi) const {
    ll ret = unit_dat;
    for (int i = rngLo; i < rngHi; i++) ret = add(ret, data[idx][i]);
    return ret;
  }

  int update(int idx, ll rngLo, ll rngHi, const OP& op_asked) {
    vector<DAT> new_vec = data[idx];
    for (int i = rngLo; i < rngHi; i++) new_vec[i] = appl(op_asked, new_vec[i]);
    data.push_back(move(new_vec));
    return ssize(data) - 1;
  }

  int set(int idx, ll i, DAT t) {
    vector<DAT> new_vec = data[idx];
    new_vec[i] = move(t);
    data.push_back(move(new_vec));
    return ssize(data) - 1;
  }
};

template <typename DAT, typename OP>
auto make_naive_impl(DAT unit_dat, OP unit_op, auto add, auto appl, const vector<DAT>& init_data) {
  NaiveImpl<DAT, OP, decltype(add), decltype(appl)> ni(unit_dat, unit_op, add, appl);
  ll idx = ni.fromVector(init_data);
  return make_pair(ni, idx);
}

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  Random rand;

  {
    auto mymax = [&](ll a, ll b) -> ll { return max(a, b); };
    vector<ll> init_dat{3, 5, 1, 4, 10, 2};
    auto [st, r1] = make_pers_seg_tree(0LL, mymax, init_dat);
    assert(st.query(r1, 0, 6) == 10);
    assert(st.query(r1, 1, 4) == 5);
    auto r2 = st.set(r1, 2, 20);
    assert(st.query(r2, 0, 6) == 20);
    assert(st.query(r2, 1, 4) == 20);
    assert(st.query(r2, 6, 0) == 0);
  }  
  {
    auto mymax = [&](ll a, ll b) -> ll { return max(a, b); };
    vector<ll> init_dat{3, 5, 1, 4, 10, 2};
    auto [st, r1] = make_pers_seg_tree_lazy(0LL, 0LL, mymax, plus<ll>(), plus<ll>(), init_dat);
    assert(st.query(r1, 0, 6) == 10);
    assert(st.query(r1, 1, 4) == 5);
    auto r2 = st.set(r1, 2, 20);
    assert(st.query(r2, 0, 6) == 20);
    assert(st.query(r2, 1, 4) == 20);
    auto r3 = st.update(r2, 3, 5, 100);
    assert(st.query(r3, 0, 1) == 3);
    assert(st.query(r3, 1, 2) == 5);
    assert(st.query(r3, 2, 3) == 20);
    assert(st.query(r3, 3, 4) == 104);
    assert(st.query(r3, 4, 5) == 110);
    assert(st.query(r3, 5, 6) == 2);
    assert(st.query(r3, 6, 0) == 0);
  }  
  ll repeat = 100;
  ll repeat2 = 100;
  {
    for (int _r = 0; _r < repeat; _r++) {
      ll sz = rand.range(1, 11);
      vector<ll> vec(sz);
      for (int i = 0; i < sz; i++) vec[i] = rand.range(-9, 10);
      auto [st, pt0] = make_pers_seg_tree(0LL, plus<ll>(), vec);
      auto [ni, idx0] = make_naive_impl(0LL, 0LL, plus<ll>(), plus<ll>(), vec);
      vector<decltype(pt0)> rec1;
      vector<decltype(idx0)> rec2;
      rec1.push_back(pt0);
      rec2.push_back(idx0);
      for (int _r2 = 0; _r2 < repeat2; _r2++) {
        int j0 = rand.range(0, ssize(rec1));
        int j1 = rand.range(0, sz);
        int x = rand.range(-9, 10);
        auto pt = st.set(rec1[j0], j1, x);
        auto idx = ni.set(rec2[j0], j1, x);
        rec1.push_back(pt);
        rec2.push_back(idx);
        int i = rand.range(0, ssize(rec1));
        int lo = rand.range(0, sz);
        int hi = rand.range(lo + 1, sz + 1);
        ll a1 = st.query(rec1[i], lo, hi);
        ll a2 = ni.query(rec2[i], lo, hi);
        assert(a1 == a2);
      }
    }
  }
  {
    using OP = optional<ll>;
    auto mymin = [&](ll a, ll b) -> ll { return min(a, b); };
    auto comp = [&](OP f, OP g) -> OP { return f ? f : g; };
    auto appl = [&](OP f, ll x) -> ll { return f ? *f : x; };
    ll big = 1e9;
    for (int _r = 0; _r < repeat; _r++) {
      ll sz = rand.range(1, 11);
      vector<ll> vec(sz);
      for (int i = 0; i < sz; i++) vec[i] = rand.range(-9, 10);
      auto [st, pt0] = make_pers_seg_tree_lazy(big, OP{}, mymin, comp, appl, vec);
      auto [ni, idx0] = make_naive_impl(big, OP{}, mymin, appl, vec);
      vector<decltype(pt0)> rec1;
      vector<decltype(idx0)> rec2;
      rec1.push_back(pt0);
      rec2.push_back(idx0);
      for (int _r2 = 0; _r2 < repeat2; _r2++) {
        int j0 = rand.range(0, ssize(rec1));
        int j1 = rand.range(0, sz);
        int x = rand.range(-9, 10);
        auto pt = st.set(rec1[j0], j1, x);
        auto idx = ni.set(rec2[j0], j1, x);
        rec1.push_back(pt);
        rec2.push_back(idx);
        int k0 = rand.range(0, ssize(rec1));
        int k1 = rand.range(0, sz);
        int k2 = rand.range(k1 + 1, sz + 1);
        int y = rand.range(-9, 10);
        auto pt3 = st.update(rec1[k0], k1, k2, y);
        auto idx3 = ni.update(rec2[k0], k1, k2, y);
        rec1.push_back(pt3);
        rec2.push_back(idx3);
        int i = rand.range(0, ssize(rec1));
        int lo = rand.range(0, sz);
        int hi = rand.range(lo + 1, sz + 1);
        ll a1 = st.query(rec1[i], lo, hi);
        ll a2 = ni.query(rec2[i], lo, hi);
        assert(a1 == a2);
      }
    }
  }


  cout << "Ok." << endl;
  return 0;
}

