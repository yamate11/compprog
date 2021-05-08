#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug segTree)

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

// ---- inserted library file segTree.cc

// It seems that we should keep the size power of two,
// considering the binary search.

template <typename DAT, typename OP,
	  typename Fadd, typename Fcomp, typename Fappl> 
struct SegTree {
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
  Fadd add;
  Fcomp comp;
  Fappl appl;
  bool range_update;
    
  SegTree(DAT unit_dat_, OP unit_op_, Fadd add_, Fcomp comp_, Fappl appl_,
	  bool range_update_)
    // , vector<DAT> initdat) 
    : unit_dat(unit_dat_), unit_op(unit_op_), add(add_), comp(comp_),
      appl(appl_), range_update(range_update_) {}

  void set_data(vector<DAT> initdat) {
    if (initdat.size() <= 0) {
      cerr << "the size of initial vector must be >= 1" << endl;
      abort();
    }
    if (initdat.size() == 1) {
      height = 0;
    }else {
      height = sizeof(int) * 8 - __builtin_clz(initdat.size() - 1);
    }
    size = 1 << height;
    node.resize(2*size, unit_dat);
    for (int i = 0; i < (int)initdat.size(); i++) {
      node.at(size + i) = initdat.at(i);
    }
    for (int t = size - 1; t >= 1; t--) {
      node.at(t) = add(node.at(t<<1|0), node.at(t<<1|1));
    }
    susp.resize(size, unit_op);
  }

  void child_updated_sub(int k, int t) {
    node.at(t) = appl(k, susp.at(t),
		      add(node.at(t<<1|0), node.at(t<<1|1)));
  }

  void child_updated(int l, int r) {
    int k = 1;
    r--;
    while (l > 1) {
      l >>= 1;
      r >>= 1;
      k *= 2;
      child_updated_sub(k, l);
      if (l < r) child_updated_sub(k, r);
    }
  }

  void node_op(int i, int k, OP f) {
    node.at(i) = appl(k, f, node.at(i));
    if (i < size) susp.at(i) = comp(f, susp.at(i));
  }

  void push_one(int i, int k) {
    node_op(i<<1|0, k / 2, susp.at(i));
    node_op(i<<1|1, k / 2, susp.at(i));
    susp.at(i) = unit_op;
  }

  void push_upto(int l, int r) {
    for (int s = height; s >= 1; s--) {
      int lz = l >> s;
      int rz = (r-1) >> s;
      int k = 1 << s;
      push_one(lz, k);
      if (lz < rz) push_one(rz, k);
    }
  }

  DAT query(int l, int r) {
    // DLOG("l=", l, "r=", r);
    if (l >= r) return unit_dat;
    DAT ret_l = unit_dat;
    DAT ret_r = unit_dat;
    // DLOG("1: ret_l=", ret_l, "ret_r", ret_r);
    l += size;
    r += size;
    if (range_update) push_upto(l, r);
    while (l < r) {
      if (l & 1) {
	ret_l = add(ret_l, node.at(l));
	// DLOG("l=", l, "ret_l=", ret_l);
	l++;
      }
      if (r & 1) {
	ret_r = add(node.at(r-1), ret_r);
	// DLOG("r=", r, "ret_r=", ret_r);
      }
      l >>= 1;
      r >>= 1;
    }
    DAT ret = add(ret_l, ret_r);
    // DLOG("ret_l=", ret_l, "ret_r", ret_r, "ret", ret);
    return ret;
  }

  void single_update(int i, OP f) {
    update(i, i+1, f);
  }

  void update(int l, int r, OP f) {
    // DLOG("update. 1. node=", node);
    if (l >= r) return;
    if ((! range_update) && (l + 1 < r)) {
      cerr << "FATAL: r - l >= 2 without setting range_update." << endl;
      abort();
    }
    l += size;
    r += size;
    if (range_update) push_upto(l, r);
    // DLOG("update. 2. node=", node);
    int l0 = l, r0 = r;
    int k = 1;
    while (l < r) {
      if (l & 1) {
	node_op(l, k, f);
	l++;
      }
      if (r & 1) {
	node_op(r-1, k, f);
      }
      l >>= 1;
      r >>= 1;
      k *= 2;
    }
    // DLOG("update. 3. node=", node);
    child_updated(l0, r0);
    // DLOG("node=", node);
    // DLOG("susp=", susp);
  }


  // Returns the least r >= l s.t. check(Add(v[l], ..., v[r-1])) == true,
  //    where check :: DAT -> bool
  // If there is no such r, returns -1.
  int binsearch_l(const auto& check, int l) {
    // DLOG("binsearch_l; l=", l);
    int x = l + size;
    DAT val = unit_dat;
    if (check(val)) return l;
    // DLOG("pt1");
    if (range_update) push_upto(x, x+1);
    int k = 1;
    while (true) {
      DAT t = add(val, node.at(x));
      if (check(t)) break;
      if (x & 1) {
	val = t;
	x++;
	if (__builtin_popcount(x) == 1) return -1;
      }
      x >>= 1;
      k <<= 1;
      // DLOG("  x=", x, "val=", val);
    }
    // DLOG("pt2; x=", x, "k=", k);
    while (k > 1) {
      if (range_update) push_one(x, k);
      DAT t = add(val, node.at(x<<1|0));
      if (check(t)) {
	x = (x<<1|0);
      }else {
	x = (x<<1|1);
	val = t;
      }
      k >>= 1;
    }
    // DLOG("pt3; x=", x, "k=", k);
    return x + 1 - size;
  }

};

template<typename DAT, typename OP>
auto make_seg_tree(DAT unit_dat, OP unit_op,
		   auto add, auto comp, auto appl,
		   bool range_update)
  -> SegTree<DAT, OP, decltype(add), decltype(comp), decltype(appl)> {
  return SegTree(unit_dat, unit_op, add, comp, appl, range_update);
}

// ---- end segTree.cc

// @@ !! LIM -- end mark --


mt19937 rng;

template <typename DAT, typename OP,
	  typename Fadd, typename Fcomp, typename Fappl> 
struct Naive {
  int size;
  vector<DAT> vec;
  DAT unit_dat;
  Fadd add;
  Fappl appl;

  Naive(const SegTree<DAT, OP, Fadd, Fcomp, Fappl>& segt)
    : unit_dat(segt.unit_dat), add(segt.add), appl(segt.appl) {}

  void set_data(vector<DAT> initdat) {
    size = initdat.size();
    vec = initdat;
  }

  DAT query(int l, int r) {
    DAT ret = unit_dat;
    for (int i = l; i < r; i++) ret = add(ret, vec.at(i));
    return ret;
  }

  void update(int l, int r, OP f) {
    for (int i = l; i < r; i++) vec.at(i) = appl(1, f, vec.at(i));
  }

  int search(const auto& check, int l) {
    ll val = unit_dat;
    for (ll i = l; i < size; i++) {
      if (check(val)) return i;
      val = add(val, vec.at(i));
    }
    if (check(val)) return size;
    return -1;
  }
};

struct RandSpec {
  int rep1;     // segment tree creation time
  int rep2;     // num of update/query pairs in a run
  int vecsize;
  ll val_min;
  ll val_max;
  ll op_min;
  ll op_max;
};

template <typename DAT, typename OP,
	  typename Fadd, typename Fcomp, typename Fappl, typename FF> 
void cmp_naive(SegTree<DAT, OP, Fadd, Fcomp, Fappl>& st,
	       const RandSpec& rs, auto ll2OP, optional<FF> opt_check) {
  assert(rs.vecsize >= 2);
  Naive naive(st);
  uniform_int_distribution<ll>
    dist_d(rs.val_min, rs.val_max), dist_o(rs.op_min, rs.op_max),
    dist_i(0, rs.vecsize), dist_i1(0, rs.vecsize-1);
  auto rnd2 = [&](bool wide_range) -> pair<int, int> {
    if (wide_range) {
      int x = 0, y = 0;
      while (x == y) {
	x = dist_i(rng);
	y = dist_i(rng);
      }
      if (x > y) swap(x, y);
      return {x, y};
    }else {
      int x = dist_i1(rng);
      return {x, x+1};
    }
  };
  for (int r1 = 0; r1 < rs.rep1; r1++) {
    vector<DAT> vec(rs.vecsize);
    for (int i = 0; i < rs.vecsize; i++) vec.at(i) = dist_d(rng);
    st.set_data(vec);
    naive.set_data(vec);
    // DLOG("vec=", vec);
    for (int r2 = 0; r2 < rs.rep2; r2++) {
      if (r2 > 0) {
	auto [i, j] = rnd2(st.range_update);
	OP f = ll2OP(dist_o(rng));
	st.update(i, j, f);
	naive.update(i, j, f);
      }
      if (true) {
	auto [i, j] = rnd2(true);
	DAT d_st = st.query(i, j);
	DAT d_nv = naive.query(i, j);
	if (d_st != d_nv) {
	  cerr << "query: SegTree and Naive retuns different results:" <<
	    "i = " << i << ", j = " << j << ", d_st = " << d_st <<
	    ", d_naive = " << d_nv << endl;
	  abort();
	}
      }
      if (opt_check.has_value()) {
	const auto& check = opt_check.value();
	int k = dist_i1(rng);
	int i_st = st.binsearch_l(check, k);
	int i_nv = naive.search(check, k);
	if (i_st != i_nv) {
	  cerr << "binsearch: SegTree and Naive behave differently: " <<
	    "k = " << k << ", i_st = " << i_st << ", i_naive = " <<
	    i_nv << endl;
	  abort();
	}
      }
    }
  }
}

// Just an easy testing
void test1() {
  using DAT = ll;
  using OP = optional<ll>;
  const DAT unit_dat = LLONG_MAX;
  const OP unit_op = nullopt;
  auto xAdd = [](DAT x, DAT y) -> DAT { return min(x, y); };
  auto xAppl = [](int k, OP f, DAT x) -> DAT { return f.value_or(x); };
  auto xComp = [](OP h, OP g) -> OP { return h.has_value() ? h : g; };
  auto st = make_seg_tree(unit_dat, unit_op, xAdd, xComp, xAppl, false);

  vector<DAT> init_vec;
  for (ll i = 0; i < 4; i++) init_vec.push_back(i + 100);
  st.set_data(init_vec);
  
  assert(st.query(0, 4) == 100);
  assert(st.query(1, 2) == 101);
  // DLOG("b12");
  st.update(1, 2, 10);
  // DLOG("b13");
  assert(st.query(0, 4) == 10);

  auto check1 = [&](DAT x) -> bool { return x <= 10; };
  assert(st.binsearch_l(check1, 0) == 2);
  assert(st.binsearch_l(check1, 1) == 2);
  assert(st.binsearch_l(check1, 2) == -1);

  init_vec.push_back(104);
  init_vec.push_back(105);
  init_vec.push_back(106);
  st.set_data(init_vec);
  assert(st.query(0, 7) == 100);
  assert(st.query(4, 7) == 104);
  st.update(5, 6, 10);
  assert(st.query(1, 6) == 10);

  // interval update
  auto st3 = make_seg_tree(unit_dat, unit_op, xAdd, xComp, xAppl, true);
  st3.set_data(init_vec);
  st3.update(0, 3, 20);
  assert(st3.query(1, 4) == 20);
  st3.update(3, 6, 10);
  assert(st3.query(1, 4) == 10);

  // num of elements == 1
  vector<DAT> iv2({100});
  auto st4 = make_seg_tree(unit_dat, unit_op, xAdd, xComp, xAppl, false);
  st4.set_data(vector<DAT>({100}));
  assert(st4.query(0, 1) == 100);
  st4.update(0, 1, 50);
  assert(st4.query(0, 1) == 50);
}

// Update: substitution
// Query: minimum
void test2(const RandSpec& rs) {
  using DAT = ll;
  using OP = optional<ll>;
  const DAT unit_dat = LLONG_MAX;
  const OP unit_op = nullopt;
  auto xAdd = [](DAT x, DAT y) -> DAT { return min(x, y); };
  auto xAppl = [](int k, OP f, DAT x) -> DAT { return f.value_or(x); };
  auto xComp = [](OP h, OP g) -> OP { return h.has_value() ? h : g; };
  auto st = make_seg_tree(unit_dat, unit_op, xAdd, xComp, xAppl, false);

  auto ll2OP = [](int x) -> OP { return {x}; };
  auto check = [](DAT x) -> bool { return x < -5; };
  cmp_naive(st, rs, ll2OP, optional(check));
  auto st2 = make_seg_tree(unit_dat, unit_op, xAdd, xComp, xAppl, true);
  cmp_naive(st, rs, ll2OP, optional(check));
}

// Update: increment
// Query: sum
void test3(const RandSpec& rs) {
  using DAT = ll;
  using OP = ll;
  const DAT unit_dat = 0;
  const OP unit_op = 0;
  auto xAdd = [](DAT x, DAT y) -> DAT { return x + y; };
  auto xAppl = [](int k, OP f, DAT x) -> DAT { return k * f + x; };
  auto xComp = [](OP h, OP g) -> OP { return h + g; };
  auto st = make_seg_tree(unit_dat, unit_op, xAdd, xComp, xAppl, false);

  auto ll2OP = [](int x) -> OP { return x; };
  typedef bool (*dummy_t)(DAT);
  optional<dummy_t> dummy(nullopt);
  cmp_naive(st, rs, ll2OP, dummy);
  auto st2 = make_seg_tree(unit_dat, unit_op, xAdd, xComp, xAppl, true);
  cmp_naive(st, rs, ll2OP, dummy);
}
void test3a(const RandSpec& rs) {
  using DAT = ll;
  using OP = ll;
  const DAT unit_dat = 0;
  const OP unit_op = 0;
  auto xAdd = [](DAT x, DAT y) -> DAT { return x + y; };
  auto xAppl = [](int k, OP f, DAT x) -> DAT { return k * f + x; };
  auto xComp = [](OP h, OP g) -> OP { return h + g; };
  auto st = make_seg_tree(unit_dat, unit_op, xAdd, xComp, xAppl, false);

  auto ll2OP = [](int x) -> OP { return x; };
  auto check = [](DAT x) -> bool { return x >= 40; };
  cmp_naive(st, rs, ll2OP, optional(check));
  auto st2 = make_seg_tree(unit_dat, unit_op, xAdd, xComp, xAppl, true);
  cmp_naive(st, rs, ll2OP, optional(check));
}

// Update: substitution
// Query: sum
void test4(const RandSpec& rs) {
  using DAT = ll;
  using OP = optional<ll>;
  const DAT unit_dat = 0;
  const OP unit_op = nullopt;
  auto xAdd = [](DAT x, DAT y) -> DAT { return x + y; };
  auto xAppl = [](int k, OP f, DAT x) -> DAT {
    return f.has_value() ? k * f.value() : x;
  };
  auto xComp = [](OP h, OP g) -> OP { return h.has_value() ? h : g; };
  auto st = make_seg_tree(unit_dat, unit_op, xAdd, xComp, xAppl, false);

  auto ll2OP = [](int x) -> OP { return x; };
  typedef bool (*dummy_t)(DAT);
  optional<dummy_t> dummy(nullopt);
  cmp_naive(st, rs, ll2OP, dummy);
  auto st2 = make_seg_tree(unit_dat, unit_op, xAdd, xComp, xAppl, true);
  cmp_naive(st, rs, ll2OP, dummy);
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  rng.seed(time(0));
  // rng.seed(0);

  RandSpec rs;
  rs.rep1 = 100;
  rs.rep2 = 100;
  rs.vecsize = 52;
  // rs.vecsize = 4;
  rs.val_min = -10;
  rs.val_max = 10;
  rs.op_min = -15;
  rs.op_max = 15;

  RandSpec rsPos;
  rsPos.rep1 = 100;
  rsPos.rep2 = 100;
  rsPos.vecsize = 52;
  // rsPos.vecsize = 4;
  rsPos.val_min = 1;
  rsPos.val_max = 20;
  rsPos.op_min = 1;
  rsPos.op_max = 30;

  test1();
  test2(rs);
  test3(rs);
  test3a(rsPos);
  test4(rs);

  cout << "Test done." << endl;
  return 0;
}

