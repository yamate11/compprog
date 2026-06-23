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

// @@ !! LIM(segTree power)

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

// ---- inserted library file segTree.cc

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

  const DAT& at(int i) {
    if constexpr(lazy) push_upto(size + i, size + i + 1);
    return node[size + i];
  }

  const DAT& set_single(int i, const DAT& t) {
    ll x = size + i;
    if constexpr(lazy) push_upto(x, x + 1);
    node[x] = t;
    for (x >>= 1; x >= 1; x >>= 1) node[x] = add(node[x<<1|0], node[x<<1|1]);
    return t;
  }

  struct STSubst {
    GenSegTree& st;
    int i;
    STSubst(GenSegTree& st_, int i_) : st(st_), i(i_) {}
    const DAT& operator=(const DAT& t) { return st.set_single(i, t); }
  };

  // Reference for Substitution
  STSubst rs(int i) { return STSubst(*this, i); }

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
      os << st.at(i);
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

  vector<DAT> vec_view() {
    vector<DAT> ret(orig_size);
    for (int i = 0; i <  orig_size; i++) ret[i] = at(i);
    return ret;
  };

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

// ---- inserted library file algOp.cc

// Common definitions
//    zero, one, inverse

template<typename T>
const T zero(const T& t) {
  if constexpr (is_integral_v<T> || is_floating_point_v<T>) { return (T)0; }
  else { return t.zero(); }
}

template<typename T>
const T one(const T& t) {
  if constexpr (is_integral_v<T> || is_floating_point_v<T>) { return (T)1; }
  else { return t.one(); }
}

template<typename T>
const T inverse(const T& t) {
  if constexpr (is_floating_point_v<T>) { return 1.0 / t; }
  else { return t.inverse(); }
}

#ifdef BOOST_MP_CPP_INT_HPP
template<> const cpp_int zero(const cpp_int& t) { return cpp_int(0); }
template<> const cpp_int one(const cpp_int& t) { return cpp_int(1); }
#endif // BOOST_MP_CPP_INT_HPP

// begin -- detection ideom
//    cf. https://blog.tartanllama.xyz/detection-idiom/

namespace tartan_detail {
  template <template <class...> class Trait, class Enabler, class... Args>
  struct is_detected : false_type{};

  template <template <class...> class Trait, class... Args>
  struct is_detected<Trait, void_t<Trait<Args...>>, Args...> : true_type{};
}

template <template <class...> class Trait, class... Args>
using is_detected = typename tartan_detail::is_detected<Trait, void, Args...>::type;

// end -- detection ideom


template<typename T>
// using subst_add_t = decltype(T::subst_add(declval<typename T::value_type &>(), declval<typename T::value_type>()));
using subst_add_t = decltype(T::subst_add);
template<typename T>
using has_subst_add = is_detected<subst_add_t, T>;

template<typename T>
using add_t = decltype(T::add);
template<typename T>
using has_add = is_detected<add_t, T>;

template<typename T>
using subst_mult_t = decltype(T::subst_mult);
template<typename T>
using has_subst_mult = is_detected<subst_mult_t, T>;

template<typename T>
using mult_t = decltype(T::mult);
template<typename T>
using has_mult = is_detected<mult_t, T>;

template<typename T>
using subst_subt_t = decltype(T::subst_subt);
template<typename T>
using has_subst_subt = is_detected<subst_subt_t, T>;

template<typename T>
using subt_t = decltype(T::subt);
template<typename T>
using has_subt = is_detected<subt_t, T>;

template <typename Opdef>
struct MyAlg {
  using T = typename Opdef::value_type;
  using value_type = T;
  T v;
  MyAlg() {}
  MyAlg(const T& v_) : v(v_) {}
  MyAlg(T&& v_) : v(move(v_)) {}
  bool operator==(MyAlg o) const { return v == o.v; }
  bool operator!=(MyAlg o) const { return v != o.v; }
  operator T() const { return v; }
  MyAlg zero() const { return MyAlg(Opdef::zero(v)); }
  MyAlg one() const { return MyAlg(Opdef::one(v)); }
  MyAlg inverse() const { return MyAlg(Opdef::inverse(v)); }
  MyAlg operator/=(const MyAlg& o) { return *this *= o.inverse(); }
  MyAlg operator/(const MyAlg& o) const { return (*this) * o.inverse(); }
  MyAlg operator-() const { return zero() - *this; }

  MyAlg& operator +=(const MyAlg& o) { 
    if constexpr (has_subst_add<Opdef>::value) {
      Opdef::subst_add(v, o.v);
      return *this;
    }else if constexpr (has_add<Opdef>::value) {
      v = Opdef::add(v, o.v);
      return *this;
    }else static_assert("either subst_add or add is needed.");

  }
  MyAlg operator +(const MyAlg& o) const { 
    if constexpr (has_add<Opdef>::value) {
      return MyAlg(Opdef::add(v, o.v));
    }else if constexpr (has_subst_add<Opdef>::value) {
      MyAlg ret(v);
      Opdef::subst_add(ret.v, o.v);
      return ret;
    }else static_assert("either subst_add or add is needed.");
  }
  MyAlg& operator *=(const MyAlg& o) { 
    if constexpr (has_subst_mult<Opdef>::value) {
      Opdef::subst_mult(v, o.v);
      return *this;
    }else if constexpr (has_mult<Opdef>::value) {
      v = Opdef::mult(v, o.v);
      return *this;
    }else static_assert("either subst_mult or mult is needed.");

  }
  MyAlg operator *(const MyAlg& o) const { 
    if constexpr (has_mult<Opdef>::value) {
      return MyAlg(Opdef::mult(v, o.v));
    }else if constexpr (has_subst_mult<Opdef>::value) {
      MyAlg ret(v);
      Opdef::subst_mult(ret.v, o.v);
      return ret;
    }else static_assert("either subst_mult or mult is needed.");
  }
  MyAlg& operator -=(const MyAlg& o) { 
    if constexpr (has_subst_subt<Opdef>::value) {
      Opdef::subst_subt(v, o.v);
      return *this;
    }else if constexpr (has_subt<Opdef>::value) {
      v = Opdef::subt(v, o.v);
      return *this;
    }else static_assert("either subst_subt or subt is needed.");

  }
  MyAlg operator -(const MyAlg& o) const { 
    if constexpr (has_subt<Opdef>::value) {
      return MyAlg(Opdef::subt(v, o.v));
    }else if constexpr (has_subst_subt<Opdef>::value) {
      MyAlg ret(v);
      Opdef::subst_subt(ret.v, o.v);
      return ret;
    }else static_assert("either subst_subt or subt is needed.");
  }
  friend istream& operator >>(istream& is, MyAlg& t)       { is >> t.v; return is; }
  friend ostream& operator <<(ostream& os, const MyAlg& t) { os << t.v; return os; }
};





// ---- end algOp.cc

// ---- inserted library file power.cc

template<typename T>
T power(const T& a, ll b) {
  auto two_pow = a;
  auto ret = one<T>(a);
  while (b > 0) {
    if (b & 1LL) ret *= two_pow;
    two_pow *= two_pow;
    b >>= 1;
  }
  return ret;
}

// a >= 0, b >= 0;  If overflow, returns -1.
ll llpower(ll a, ll b) {  
  if (b == 0) return 1;   // 0^0 == 1
  if (b == 1) return a;
  if (a == 0) return 0;
  if (a == 1) return 1;
  if (a == 2) {
    if (b >= 63) return -1;
    else return 1LL << b;
  }
  if (b == 2) {
    ll ret;
    if (__builtin_smulll_overflow(a, a, &ret)) return -1;
    return ret;
  }
  ll two_pow = a;
  ll ret = 1;
  assert(b > 0);
  while (true) {
    if (b & 1LL) {
      if (__builtin_smulll_overflow(ret, two_pow, &ret)) return -1;
    }
    b >>= 1;
    if (b == 0) break;
    if (__builtin_smulll_overflow(two_pow, two_pow, &two_pow)) return -1;
  }
  return ret;
}

// a >= 0;   Returns x s.t. x*x <= a < (x+1)*(x+1)
ll llsqrt(ll a) {
  ll x = llround(sqrt((double)a));
  ll y;
  if (__builtin_smulll_overflow(x, x, &y) or a < y) return x - 1;
  else return x;
}

// a >= 0, m >= 2;  Returns x s.t. x^m <= a < (x + 1)^m
ll llroot(ll a, ll m) {
  ll x = llround(pow(a, 1.0 / m));
  ll y = llpower(x, m);
  if (y == -1 or a < y) return x - 1;
  else return x;
}

//  base >= 2, a >= 1;  Returns x s.t. base^{x} <= a < base^{x + 1}
ll lllog(ll base, ll a) {
  ll x = llround(log(a) / log(base));
  ll y = llpower(base, x);
  if (y == -1 or a < y) return x - 1;
  else return x;
}


// ---- end power.cc

// @@ !! LIM -- end mark --

using Real = long double;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [LPqEJtKn]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [LPqEJtKn]
  Real x; cin >> x;
  
  using sta = pair<Real, ll>;
  vector<sta> init_vec(N);
  REP(i, 0, N) init_vec[i] = sta(A[i], 1);
  auto myadd = [&](sta a, sta b) -> sta {
    sta ret;
    ret.first = a.first + power<Real>(x, a.second) * b.first;
    ret.second = a.second + b.second;
    return ret;
  };
  sta sta_unit(0.0, 0);
  auto st = make_seg_tree(sta_unit, myadd, init_vec);

  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll l, r; cin >> l >> r; l--;
    cout << st.query(l, r).first << "\n";
  }

  return 0;
}

