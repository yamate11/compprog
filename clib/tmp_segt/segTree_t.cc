#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
using pll = pair<ll, ll>;

// @@ !! LIM(debug segTree)

// ---- inserted function f:<< from util.cc

// declarations

template <typename T1, typename T2>
ostream& operator<< (ostream& os, const pair<T1,T2>& p);

template <typename T1, typename T2, typename T3>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3>& t);

template <typename T1, typename T2, typename T3, typename T4>
ostream& operator<< (ostream& os, const tuple<T1,T2,T3,T4>& t);

template <typename T>
ostream& operator<< (ostream& os, const vector<T>& v);

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
#line 42 "./debug.cc"
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

// ---- inserted library file segTree.cc
#line 9 "./segTree.cc"

// It seems that we should keep the size power of two,
// considering the binary search.

pair<int, int> segtree_range_of_node(int ht, unsigned i) {
  unsigned m = bit_floor(i);
  unsigned w = ht + 1 - bit_width(i);
  int lo = (i ^ m) << w;
  int hi = lo + (1LL << w);
  return make_pair(lo, hi);
}

vector<int> segtree_nodes_for_range(int ht, unsigned lo, unsigned hi) {
  vector<int> left;
  vector<int> right;
  lo = (1 << ht) + lo;
  hi = (1 << ht) + hi - 1;
  while (lo <= hi) {
    if (lo == hi) {
      left.push_back(lo);
      break;
    }
    if (lo & 1) {
      left.push_back(lo);
      lo++;
    }
    if (not (hi & 1)) {
      right.push_back(hi);
      hi--;
    }
    lo >>= 1;
    hi >>= 1;
  }
  while (not right.empty()) {
    left.push_back(right.back());
    right.pop_back();
  }
  return left;
}

template <typename DAT, typename OP,
	  typename ADD_t, typename COMP_t, typename APPL_t, bool lazy> 
struct GenSegTree {
  using GST = GenSegTree<DAT, OP, ADD_t, COMP_t, APPL_t, lazy>;

  int orig_size;     // size of initdat
  int size;	     // power of two; >= 2
  int height;        // size = 1 << height;
  vector<DAT> node;  // vector of size 2*size.
                     // 0                 : unused
                     // 1    ... size-1   : interval
                     // size ... 2*size-1 : leaf
  vector<OP> susp;   // vector of size size.
                     // suspended operation FOR CHILDREN
                     // (already applied to this node)
  DAT unit_dat;
  OP unit_op;
  ADD_t add;
  COMP_t comp;
  APPL_t appl;
    
  GenSegTree() {}

  GenSegTree(DAT unit_dat_, OP unit_op_, ADD_t add_, COMP_t comp_, APPL_t appl_,
             const vector<DAT>& initdat = vector<DAT>())
    : unit_dat(unit_dat_), unit_op(unit_op_),
      add(add_), comp(comp_), appl(appl_) { set_data(initdat); }

  void set_data(const vector<DAT>& initdat) {
    orig_size = initdat.size();
    if (initdat.size() <= 1) height = 0;
    else   height = sizeof(int) * 8 - __builtin_clz(initdat.size() - 1);
    size = 1 << height;
    node.resize(2*size, unit_dat);
    for (int i = 0; i < (int)initdat.size(); i++) node[size + i] = initdat[i];
    for (int t = size - 1; t >= 1; t--) node[t] = add(node[t<<1|0], node[t<<1|1]);
    susp.resize(size, unit_op);
  }

  void child_updated_sub(int t) {
    node[t] = appl(susp[t], add(node[t<<1|0], node[t<<1|1]));
  }

  void child_updated(int l, int r) {
    r--;
    while (l > 1) {
      l >>= 1;
      r >>= 1;
      child_updated_sub(l);
      if (l < r) child_updated_sub(r);
    }
  }

  void node_op(int i, OP f) {
    node[i] = appl(f, node[i]);
    if (i < size) susp[i] = comp(f, susp[i]);
  }

  // Note that susp[i] HAS ALREADY BEEN APPLIED TO node[i].
  // When push_one(i) is called, susp[j] is updated (for j : i's child) and it is applied to node[j].
  void push_one(int i) {
    node_op(i<<1|0, susp[i]);
    node_op(i<<1|1, susp[i]);
    susp[i] = unit_op;
  }

  void push_upto(int l, int r) {
    for (int s = height; s >= 1; s--) {
      int lz = l >> s;
      int rz = (r-1) >> s;
      push_one(lz);
      if (lz < rz) push_one(rz);
    }
  }

  DAT query(int l, int r) {
    if (l >= r) return unit_dat;
    DAT ret_l = unit_dat;
    DAT ret_r = unit_dat;
    l += size;
    r += size;
    if constexpr(lazy) push_upto(l, r);
    while (l < r) {
      if (l & 1) {
	ret_l = add(ret_l, node[l]);
	l++;
      }
      if (r & 1) {
	ret_r = add(node[r-1], ret_r);
      }
      l >>= 1;
      r >>= 1;
    }
    DAT ret = add(ret_l, ret_r);
    return ret;
  }

  const DAT& get_single(int i) {
    if constexpr(lazy) push_upto(size + i, size + i + 1);
    return node[size + i];
  }

  void set_single(int i, const DAT& t) {
    ll x = size + i;
    if constexpr(lazy) push_upto(x, x + 1);
    node[x] = t;
    for (x >>= 1; x >= 1; x >>= 1) node[x] = add(node[x<<1|0], node[x<<1|1]);
  }

  // obsolete
  template<bool xx = lazy> enable_if_t<! xx> update(int i, DAT t) {
    ll x = size + i;
    node[x] = t;
    for (x >>= 1; x >= 1; x >>= 1) node[x] = add(node[x<<1|0], node[x<<1|1]);
  }

  template<bool xx = lazy> enable_if_t<xx> update(int l, int r, const OP& f) {
    if (l >= r) return;
    l += size;
    r += size;
    push_upto(l, r);
    int l0 = l, r0 = r;
    while (l < r) {
      if (l & 1) {
	node_op(l, f);
	l++;
      }
      if (r & 1) {
	node_op(r-1, f);
      }
      l >>= 1;
      r >>= 1;
    }
    child_updated(l0, r0);
  }

  pair<int, int> range_of_node(unsigned i) { return segtree_range_of_node(height, i); }

  vector<int> nodes_for_range(unsigned lo, unsigned hi) { return segtree_nodes_for_range(height, lo, hi); }

  friend ostream& operator<<(ostream& os, GenSegTree& st) {
    os << '[';
    for (int i = 0; i < st.orig_size; i++) {
      if (i > 0) os << ", ";
      os << st.get_single(i);
    }
    os << ']';
    return os;
  }

  int binsearch_r_until(const auto& check, int l) {
    // DLOGKL("in: binsearch_r_until", l);
    if (not check(unit_dat)) return l - 1;
    if (l == orig_size) return l;
    DAT val = unit_dat;
    int x = l + size;
    if constexpr(lazy) push_upto(x, x + 1);
    while (true) {
      if (x & 1) {
        DAT t = add(val, node[x]);
        if (not check(t)) break;
        val = t;
        x++;
        if (__builtin_popcountll(x) == 1) return orig_size;
      }
      x >>= 1;
      // DLOGKL("1: ", x, val);
    }
    while (x < size) {
      if constexpr(lazy) push_one(x);
      x <<= 1;
      DAT t = add(val, node[x]);
      if (check(t)) {
        x++;
        val = t;
      }
      // DLOGKL("2: ", x, val);
    }
    // DLOGKL("3: ", x - size, orig_size);
    return min(x - size, orig_size);
  }

  int binsearch_r_from(const auto& check, int l) {
    return binsearch_r_until([&](DAT x) { return not check(x); }, l) + 1;
  }

  int binsearch_l_until(const auto& check, int r) {
    if (not check(unit_dat)) return r + 1;
    if (r == 0) return 0;
    DAT val = unit_dat;
    int x = r + size;
    if (x == 2 * size) {
      if (check(node[1])) return 0;
      x = 1;
    }else {
      if constexpr(lazy) push_upto(x - 1, x);
      while (true) {
        if (x & 1) {
          x--;
          DAT t = add(node[x], val);
          if (not check(t)) break;
          val = t;
          if (__builtin_popcountll(x) == 1) return 0;
        }
        x >>= 1;
      }
    }
    while (x < size) {
      if constexpr(lazy) push_one(x);
      x = x << 1 | 1;
      DAT t = add(node[x], val);
      if (check(t)) {
        val = t;
        x--;
      }
    }
    return x + 1 - size;
  }

  int binsearch_l_from(const auto& check, int r) {
    return binsearch_l_until([&](DAT x) { return not check(x); }, r) - 1;
  }

};

template<typename DAT, typename OP>
auto make_seg_tree_lazy(DAT unit_dat, OP unit_op, auto add, auto comp, auto appl,
                        const vector<DAT>& initdat = vector<DAT>()) {
  using ret_t = GenSegTree<DAT, OP, decltype(add), decltype(comp), decltype(appl), true>;
  return ret_t(unit_dat, unit_op, add, comp, appl, initdat);
}

void* dummy_comp(void* x, void* y) { return nullptr; }
template<typename DAT>
DAT dummy_appl(void* x, const DAT& y) { return y; }

template<typename DAT>
auto make_seg_tree(DAT unit_dat, auto add, const vector<DAT>& initdat = vector<DAT>()) {
  using ret_t = GenSegTree<DAT, void*, decltype(add), void* (*)(void*, void*), DAT (*)(void*, const DAT&), false>;
  return ret_t(unit_dat, nullptr, add, dummy_comp, dummy_appl<DAT>, initdat);
}

// ---- end segTree.cc

// @@ !! LIM -- end mark --
#line 8 "segTree_skel.cc"

random_device rd;
mt19937_64 rng(rd());
ll randrange(ll i, ll j) {
  uniform_int_distribution<ll> dist(i, j - 1);
  return dist(rng);
}
  
template <typename DAT, typename OP,
	  typename ADD_t, typename COMP_t, typename APPL_t, bool lazy> 
bool segtree_data_equals(const GenSegTree<DAT, OP, ADD_t, COMP_t, APPL_t, lazy>& s1,
                         const GenSegTree<DAT, OP, ADD_t, COMP_t, APPL_t, lazy>& s2) {
  return s1.orig_size == s2.orig_size and s1.size == s2.size and s1.height == s2.height and
    s1.node == s2.node and s1.susp == s2.susp and s1.unit_dat == s2.unit_dat;
}

template <typename DAT, typename OP, typename Fadd, typename Fappl>
struct Naive {
  DAT unit_dat;
  Fadd add;
  Fappl appl;
  vector<DAT> vec;
  int size;

  Naive(DAT unit_dat_, Fadd add_, Fappl appl_, const vector<DAT>& vec_)
    : unit_dat(unit_dat_), add(add_), appl(appl_), vec(vec_), size(vec_.size()) {}

  DAT query(int l, int r) {
    DAT ret = unit_dat;
    for (int i = l; i < r; i++) ret = add(ret, vec[i]);
    return ret;
  }

  void update(int l, int r, OP f) {
    for (int i = l; i < r; i++) vec[i] = appl(f, vec[i]);
  }

  int search_r_until(const auto& check, int l) {
    ll val = unit_dat;
    if (not check(val)) return l - 1;
    for (ll i = l; i < size; i++) {
      val = add(val, vec[i]);
      if (not check(val)) return i;
    }
    return size;
  }

  int search_r_from(const auto& check, int l) {
    ll val = unit_dat;
    if (check(val)) return l;
    for (ll i = l; i < size; i++) {
      val = add(val, vec[i]);
      if (check(val)) return i + 1;
    }
    return size + 1;
  }

  int search_l_until(const auto& check, int r) {
    ll val = unit_dat;
    if (not check(val)) return r + 1;
    for (ll i = r - 1; i >= 0; i--) {
      val = add(vec[i], val);
      if (not check(val)) return i + 1;
    }
    return 0;
  }

  int search_l_from(const auto& check, int r) {
    ll val = unit_dat;
    if (check(val)) return r;
    for (ll i = r - 1; i >= 0; i--) {
      val = add(vec[i], val);
      if (check(val)) return i;
    }
    return -1;
  }

};


void test1() {

  {
    auto add = [&](ll x, ll y) -> ll { return min(x, y); };
    vector<ll> init_vec{5, 1, 2, 3, 7};
    auto st = make_seg_tree(LLONG_MAX, add, init_vec);

    assert(st.query(0, 5) == 1);
    assert(st.query(0, 3) == 1);
    assert(st.query(3, 5) == 3);
    assert(st.query(2, 5) == 2);
    assert(st.get_single(2) == 2);
    st.set_single(1, 10);
    assert(st.get_single(1) == 10);
    assert(st.query(0, 2) == 5);
    assert(st.query(0, 5) == 2);
    st.set_single(2, 20);
    assert(st.query(0, 5) == 3);

    stringstream ss;
    ss << st;
    assert(ss.str() == "[5, 10, 20, 3, 7]");
  }

  {
    using OP = optional<ll>;
    auto add = [&](ll x, ll y) -> ll { return min(x, y); };
    auto comp = [&](OP h, OP g) -> OP { return h.has_value() ? h : g; };
    auto apply = [&](OP f, ll x) -> ll { return f.value_or(x); };
    vector<ll> init_vec{5, 1, 2, 3, 7};
    auto st = make_seg_tree_lazy(LLONG_MAX, OP(), add, comp, apply, init_vec);

    assert(st.query(0, 5) == 1);
    assert(st.get_single(2) == 2);
    st.update(1, 4, 10);
    assert(st.query(0, 5) == 5);
    assert(st.query(1, 5) == 7);
  }

  {
    auto st = make_seg_tree(0, plus<int>(), vector<int>{0, 1, 2, 3, 4, 5});
    ll lim = 0;
    auto check_GE = [&](int x) -> bool { return x >= lim; };
    auto check_LE = [&](int x) -> bool { return x <= lim; };
    lim = 9;
    assert(st.binsearch_r_from(check_GE, 2) == 5);
    lim = 10000;
    assert(st.binsearch_r_from(check_GE, 2) == 7);
    lim = 5;
    assert(st.binsearch_r_until(check_LE, 2) == 4);
    lim = -1000;
    assert(st.binsearch_r_until(check_LE, 2) == 1);

    auto st2 = make_seg_tree(0, plus<int>(), vector<int>{1, 1, 1, 1, 1});
    lim = 2;
    assert(st2.binsearch_l_until(check_LE, 3) == 1);
    lim = -1000;
    assert(st2.binsearch_l_until(check_LE, 3) == 4);
    lim = 2;
    assert(st2.binsearch_l_from(check_GE, 3) == 1);
    lim = 10000;
    assert(st2.binsearch_l_from(check_GE, 3) == -1);

    auto st3 = make_seg_tree(0, plus<int>(), vector<int>{1, 0, 0, 0, 1});
    lim = 0;
    assert(st3.binsearch_r_from(check_LE, 1) == 1);
    assert(st3.binsearch_r_until(check_LE, 1) == 4);
    st3.set_single(4, 0);
    assert(st3.binsearch_r_until(check_LE, 1) == 5);
  }
}

void test2() {
  auto sub = [&](auto& ivec) {
    ll sz = ivec.size();
    auto add = plus<int>();
    auto appl = [&](ll f, ll x) -> ll { return f; };
    auto st = make_seg_tree<ll>(0, add, ivec);
    Naive<ll, ll, decltype(add), decltype(appl)> nv(0, add, appl, ivec);
    ll rep = 1000;
    for (ll r = 0; r < rep; r++) {
      ll i = randrange(0, sz);
      {
        ll x = randrange(0, 4);
        st.set_single(i, x);
        nv.update(i, i + 1, x);
      }
      ll j = randrange(0, sz);
      ll k = randrange(j, sz);
      assert(st.query(j, k) == nv.query(j, k));
      ll jj = randrange(0, sz);
      assert(st.get_single(jj) == nv.query(jj, jj + 1));
      ll lim = randrange(0, 19);
      auto checkLE = [&](ll x) -> bool { return x <= lim; };
      auto checkGE = [&](ll x) -> bool { return x >= lim; };
      ll p = randrange(0, sz + 1);
      assert(st.binsearch_r_until(checkLE, p) == nv.search_r_until(checkLE, p));
      p = randrange(0, sz + 1);
      assert(st.binsearch_l_until(checkLE, p) == nv.search_l_until(checkLE, p));
      p = randrange(0, sz + 1);
      assert(st.binsearch_r_from(checkGE, p) == nv.search_r_from(checkGE, p));
      p = randrange(0, sz + 1);
      assert(st.binsearch_l_from(checkGE, p) == nv.search_l_from(checkGE, p));
    }
  };
  auto ivec = vector<ll>(5, 0LL);
  sub(ivec);
  ivec = vector<ll>(8, 0LL);
  sub(ivec);
}

void test3() {
  using DAT = pair<ll, ll>;
  using OP = optional<ll>;

  auto sub = [&](ll sz) {

    auto init_vec = vector<ll>(sz);

    auto add = [](DAT x, DAT y) -> DAT { return DAT(x.first + y.first, x.second + y.second); };
    auto comp = [](OP f, OP g) -> OP { return f ? f : g; };
    auto appl = [](OP f, DAT x) -> DAT { return f ? DAT(*f * x.second, x.second) : x; };
    auto dat_init = vector<DAT>();
    for (int i = 0; i < (int)init_vec.size(); i++) dat_init.emplace_back(init_vec[i], 1);
    auto st = make_seg_tree_lazy<DAT, OP>(DAT(), OP(), add, comp, appl, dat_init);

    auto appl_nv = [&](OP f, ll x) -> ll { return f ? *f : x; };
    Naive<ll, OP, decltype(plus<ll>()), decltype(appl_nv)> nv(0, plus<ll>(), appl_nv, init_vec);
    ll rep = 1000;
    for (ll r = 0; r < rep; r++) {
      {
        ll i0 = randrange(0, sz);
        ll i1 = randrange(i0, sz);
        ll x = randrange(0, 4);
        st.update(i0, i1, x);
        nv.update(i0, i1, x);
      }
      // DLOGK(nv.vec);
      // DLOGK(st.node);
      // DLOGK(st.susp);
      ll j = randrange(0, sz);
      ll k = randrange(j, sz);
      // DLOGK(j, k, st.query(j, k), nv.query(j, k));
      assert(st.query(j, k).first == nv.query(j, k));
      ll jj = randrange(0, sz);
      assert(st.get_single(jj).first == nv.query(jj, jj + 1));
      ll lim = randrange(0, 19);
      auto checkLE_st = [&](DAT x) -> bool { return x.first <= lim; };
      auto checkGE_st = [&](DAT x) -> bool { return x.first >= lim; };
      auto checkLE_nv = [&](ll x) -> bool { return x <= lim; };
      auto checkGE_nv = [&](ll x) -> bool { return x >= lim; };
      ll p = randrange(0, sz + 1);
      assert(st.binsearch_r_until(checkLE_st, p) == nv.search_r_until(checkLE_nv, p));
      p = randrange(0, sz + 1);
      assert(st.binsearch_l_until(checkLE_st, p) == nv.search_l_until(checkLE_nv, p));
      p = randrange(0, sz + 1);
      assert(st.binsearch_r_from(checkGE_st, p) == nv.search_r_from(checkGE_nv, p));
      p = randrange(0, sz + 1);
      assert(st.binsearch_l_from(checkGE_st, p) == nv.search_l_from(checkGE_nv, p));
    }
  };
  sub(5);
  sub(8);
}

void test4() {
  auto sub = [&](ll sz) {
    auto ivec = vector<ll>(sz);
    auto add = [](ll x, ll y) -> ll { return min(x, y); };
    auto st = make_seg_tree<ll>(LLONG_MAX, add);
    st.set_data(ivec);
    auto appl_nv = [](ll f, ll x) -> ll { return f; };
    Naive<ll, ll, decltype(add), decltype(appl_nv)> nv(LLONG_MAX, add, appl_nv, ivec);
    ll rep = 1000;
    for (ll r = 0; r < rep; r++) {
      ll i = randrange(0, sz);
      {
        ll x = randrange(0, 4);
        st.set_single(i, x);
        nv.update(i, i + 1, x);
      }
      ll j = randrange(0, sz);
      ll k = randrange(j, sz);
      assert(st.query(j, k) == nv.query(j, k));
      ll lim = randrange(-1, 5);
      auto checkLE = [&](ll x) -> bool { return x <= lim; };
      auto checkGE = [&](ll x) -> bool { return x >= lim; };
      ll p = randrange(0, sz + 1);
      assert(st.binsearch_r_until(checkGE, p) == nv.search_r_until(checkGE, p));
      p = randrange(0, sz + 1);
      assert(st.binsearch_l_until(checkGE, p) == nv.search_l_until(checkGE, p));
      p = randrange(0, sz + 1);
      assert(st.binsearch_r_from(checkLE, p) == nv.search_r_from(checkLE, p));
      p = randrange(0, sz + 1);
      assert(st.binsearch_l_from(checkLE, p) == nv.search_l_from(checkLE, p));
    }
  };
  sub(5);
  sub(8);
}

void test5() {
  using OP = optional<ll>;
  auto sub = [&](ll sz) {
    auto ivec = vector<ll>(sz);
    auto add = [](ll x, ll y) -> ll { return min(x, y); };
    auto comp = [](OP f, OP g) -> OP { return f ? f : g; };
    auto appl_st = [](OP f, ll x) -> ll { return f ? *f : x; };
    auto appl_nv = [&](OP f, ll x) -> ll { return f ? *f : x; };
    auto st = make_seg_tree_lazy<ll, OP>(LLONG_MAX, OP(), add, comp, appl_st, ivec);
    Naive<ll, OP, decltype(add), decltype(appl_nv)> nv(LLONG_MAX, add, appl_nv, ivec);
    ll rep = 1000;
    for (ll r = 0; r < rep; r++) {
      {
        ll i0 = randrange(0, sz);
        ll i1 = randrange(i0, sz);
        ll x = randrange(0, 4);
        st.update(i0, i1, x);
        nv.update(i0, i1, x);
      }
      ll j = randrange(0, sz);
      ll k = randrange(j, sz);
      // DLOGK(j, k, nv.vec, st.node, st.query(j, k), nv.query(j, k));
      assert(st.query(j, k) == nv.query(j, k));

      ll lim = randrange(-1, 5);
      auto checkLE = [&](ll x) -> bool { return x <= lim; };
      auto checkGE = [&](ll x) -> bool { return x >= lim; };
      ll p = randrange(0, sz + 1);
      assert(st.binsearch_r_until(checkGE, p) == nv.search_r_until(checkGE, p));
      p = randrange(0, sz + 1);
      assert(st.binsearch_l_until(checkGE, p) == nv.search_l_until(checkGE, p));
      p = randrange(0, sz + 1);
      assert(st.binsearch_r_from(checkLE, p) == nv.search_r_from(checkLE, p));
      p = randrange(0, sz + 1);
      assert(st.binsearch_l_from(checkLE, p) == nv.search_l_from(checkLE, p));
    }
  };
  sub(5);
  sub(8);
}

void test6() {
  // zero-size init vector
  auto st0 = make_seg_tree<ll>(0LL, plus<ll>(), vector<ll>());
  assert(st0.query(0, 0) == 0);
  // one-size init vector
  auto st1 = make_seg_tree<ll>(0LL, plus<ll>(), vector<ll>({5}));
  assert(st1.query(0, 1) == 5);
  st1.set_single(0, -100);
  assert(st1.query(0, 1) == -100);
}

void test7() {
  using sg1_t = decltype(make_seg_tree_lazy(0, 0, plus<int>(), plus<int>(), plus<int>()));
  vector<sg1_t> sg1(10);
  for (int i = 0; i < 10; i++) {
    vector myv(1 + (i % 3), 0);
    if (i % 3 == 0) {
      sg1[i] = make_seg_tree_lazy(0, 0, plus<int>(), plus<int>(), plus<int>(), myv);
    }else {
      sg1[i] = make_seg_tree_lazy(0, 0, plus<int>(), plus<int>(), plus<int>());
      sg1[i].set_data(myv);
    }
  }
  assert(segtree_data_equals(sg1[4], sg1[7]));
  assert(not segtree_data_equals(sg1[4], sg1[6]));
  assert(segtree_data_equals(sg1[3], sg1[6]));
  assert(not segtree_data_equals(sg1[3], sg1[5]));

  using sg2_t = decltype(make_seg_tree(0, plus<int>()));
  vector<int> init(100); for (int i = 0; i < 100; i++) init[i] = i;
  sg2_t sg2;
  sg2 = make_seg_tree(0, plus<int>());
  sg2.set_data(init);
  auto sg3 = make_seg_tree(0, plus<int>(), init);
  assert(segtree_data_equals(sg2, sg3));

  auto sg4 = make_seg_tree(LLONG_MIN, [](ll x, ll y) -> ll { return max(x, y); });
  using sg4_t = decltype(sg4);
  vector<sg4_t> vec4(2, sg4);
  vec4[0].set_data(vector<ll>(5));
  vec4[1].set_data(vector<ll>(10));
  vec4[0].set_single(2, 10);
  vec4[1].set_single(9, 20);
  assert(vec4[0].query(0, 5) + vec4[1].query(0, 10) == 30);
}

void test8() {
  // seg_single, get_single
  auto mymin = [&](ll x, ll y) -> ll { return min(x, y); };
  auto st = make_seg_tree(LLONG_MAX, mymin, vector<ll>(10, 100));
  st.set_single(5, 80);
  assert(st.get_single(5) == 80);

  ll big = 1e18;
  auto st2 = make_seg_tree_lazy(big, 0LL, mymin, plus<ll>(), plus<ll>(), vector(100, 0LL));
  st2.update(20, 60, 100);
  st2.update(40, 80, 200);
  assert(st2.get_single(0) == 0);
  assert(st2.get_single(20) == 100);
  assert(st2.get_single(50) == 300);
  assert(st2.get_single(60) == 200);
  st2.set_single(45, 150);
  assert(st2.query(40, 50) == 150);

  ll out_rep = 100;
  ll in_rep = 1000;
  ll d_min = -10;
  ll d_max = 10;
  for (ll sz : vector<ll>{8, 13}) {
    auto init_vec = vector<ll>(sz, 0LL);
    for (ll o_r = 0; o_r < out_rep; o_r++) {
      auto st3 = make_seg_tree(big, mymin, init_vec);
      Naive<ll, ll, decltype(mymin), decltype(mymin)> nv3(big, mymin, mymin, init_vec);
      for (ll _r = 0; _r < in_rep; _r++) {
        ll tp = randrange(0, 3);
        if (tp == 0) {
          ll i = randrange(0, sz);
          ll x = randrange(d_min, d_max + 1);
          st3.set_single(i, x);
          nv3.vec[i] = x;
        }else if (tp == 1) {
          ll l = randrange(0, sz);
          ll r = randrange(l + 1, sz + 1);
          assert(st3.query(l, r) == nv3.query(l, r));
        }else if (tp == 2) {
          ll i = randrange(0, sz);
          assert(st3.get_single(i) == nv3.vec[i]);
        }else assert(0);
      }

      auto st4 = make_seg_tree_lazy(big, 0, mymin, plus<int>(), plus<int>(), init_vec);
      Naive<ll, ll, decltype(mymin), decltype(plus<int>())> nv4(big, mymin, plus<int>(), init_vec);
      for (ll _r = 0; _r < in_rep; _r++) {
        ll tp = randrange(0, 4);
        if (tp == 0) {
          ll i = randrange(0, sz);
          ll x = randrange(d_min, d_max + 1);
          st4.set_single(i, x);
          nv4.vec[i] = x;
        }else if (tp == 1) {
          ll l = randrange(0, sz);
          ll r = randrange(l + 1, sz + 1);
          assert(st4.query(l, r) == nv4.query(l, r));
        }else if (tp == 2) {
          ll i = randrange(0, sz);
          assert(st4.get_single(i) == nv4.vec[i]);
        }else if (tp == 3) {
          ll l = randrange(0, sz);
          ll r = randrange(l + 1, sz + 1);
          ll x = randrange(d_min, d_max + 1);
          st4.update(l, r, x);
          nv4.update(l, r, x);
        }else assert(0);
      }
    }
  }
}

void test9() {
  // range_of_node, nodes_for_range
  ll rep = 1000;
  for (ll _r = 0; _r < rep; _r++) {
    unsigned sz = randrange(4, 18);
    unsigned ht = countr_zero(bit_ceil(sz));
    ll i = randrange(1, (1LL << ht) + sz);
    auto [lo, hi] = segtree_range_of_node(ht, i);
    auto vec = segtree_nodes_for_range(ht, lo, hi);
    if (not (ssize(vec) == 1 and vec[0] == i)) {
      assert(ssize(vec) == 1 and vec[0] == i);
    }
  }
  for (ll _r = 0; _r < rep; _r++) {
    unsigned sz = randrange(4, 18);
    unsigned ht = countr_zero(bit_ceil(sz));
    ll lo = randrange(0, sz);
    ll hi = randrange(lo + 1, sz + 1);
    auto vec = segtree_nodes_for_range(ht, lo, hi);
    auto [lo_A, hi_A] = segtree_range_of_node(ht, vec[0]);
    auto [lo_B, hi_B] = segtree_range_of_node(ht, vec.back());
    assert(lo_A == lo and hi_B == hi);
    ll prev = hi_A;
    for (ll i = 1; i < ssize(vec); i++) {
      auto [lo_X, hi_X] = segtree_range_of_node(ht, vec[i]);
      assert(prev == lo_X and lo_X < hi_X);
      prev = hi_X;
    }
  }
  auto st = make_seg_tree_lazy(LLONG_MIN, 0, [&](ll a, ll b) -> ll { return max(a, b); }, plus<int>(), plus<int>());
  for (ll _r = 0; _r < rep; _r++) {
    unsigned sz = randrange(4, 18);
    unsigned ht = countr_zero(bit_ceil(sz));
    st.set_data(vector<ll>(sz, 0LL));
    ll i = randrange(1, (1LL << ht) + sz);
    assert(st.range_of_node(i) == segtree_range_of_node(ht, i));
    ll lo = randrange(0, sz);
    ll hi = randrange(lo + 1, sz + 1);
    assert(st.nodes_for_range(lo, hi) == segtree_nodes_for_range(ht, lo, hi));
  }
}


int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  test1();
  test2();
  test3();
  test4();
  test5();
  test6();
  test7();
  test8();
  test9();

  cout << "Test done." << endl;
  return 0;
}
