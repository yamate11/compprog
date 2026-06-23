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

// @@ !! LIM(segTree tree)

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

// If a struct has member function "string show() const", operator<< is defined.
template<typename T>
concept HasShow = requires(const T& t) {
  { t.show() } -> same_as<string>;
};
template<HasShow T>
ostream& operator<<(ostream& os, const T& t) {
  return os << t.show();
}

// ---- end f:<<

// ---- inserted library file segTree.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/segTree.cc
// https://github.com/yamate11/compprog-clib/blob/master/segTree.cc

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

void* dummy_comp(void*, void*) { return nullptr; }
template<typename DAT>
DAT dummy_appl(void*, const DAT& y) { return y; }

template<typename DAT>
auto make_seg_tree(DAT unit_dat, auto add, const vector<DAT>& initdat = vector<DAT>()) {
  using ret_t = GenSegTree<DAT, void*, decltype(add), void* (*)(void*, void*), DAT (*)(void*, const DAT&), false>;
  return ret_t(unit_dat, nullptr, add, dummy_comp, dummy_appl<DAT>, initdat);
}

// ---- end segTree.cc

// ---- inserted library file tree.cc
// published at https://github.com/yamate11/compprog-clib/blob/master/tree.cc

struct function_error : runtime_error {
  function_error(const string& msg) : runtime_error(msg) {}
};

struct Tree {

  struct pe_t {
    ll peer;
    ll edge;
    pe_t(ll peer_ = -1, ll edge_ = -1) : peer(peer_), edge(edge_) {}
  };

  using nbr_t = vector<pe_t>;

  template<bool get_peer, bool excl_parent>
  struct nbr_iterator {
    const nbr_t& body;
    ll pe_idx;
    explicit nbr_iterator(const nbr_t& body_, ll pe_idx_) : body(body_), pe_idx(pe_idx_) {}
    auto operator*() const -> typename conditional<get_peer, ll, const pe_t&>::type {
      if constexpr (get_peer) return body[pe_idx].peer;
      else                    return body[pe_idx];
    }
    const nbr_iterator& operator++() {
      pe_idx++;
      return *this;
    }
    bool operator !=(const nbr_iterator& o) const { return pe_idx != o.pe_idx; }
  };

  template<bool get_peer, bool excl_parent = true>
  struct children_view {
    const Tree& tr;
    ll nd;
    children_view(const Tree& tr_, ll nd_) : tr(tr_), nd(nd_) {}
    auto begin() const { return nbr_iterator<get_peer, excl_parent>(tr._nbr[nd], 0); }
    auto end()   const {
      ll excl_last = (excl_parent and nd != tr.root) ? 1 : 0;
      return nbr_iterator<get_peer, excl_parent>(tr._nbr[nd], ssize(tr._nbr[nd]) - (excl_last ? 1 : 0));
    }
  };

  ll numNodes;
  ll root;
  vector<nbr_t> _nbr;    // parent is moved to the rightmost place in _set_parent()
  vector<pair<ll, ll>> _edges;   // (x, y) in _edges => x < y
  vector<ll> _stsize;
  vector<ll> _depth;
  vector<ll> _euler_in;
  vector<ll> _euler_out;
  vector<pair<ll, bool>> _euler_edge;
  bool use_hl_decomp;
  vector<ll> _heavy_head;
  vector<vector<vector<ll>>> _lca_tbl;

  Tree(ll numNodes_, ll root_ = 0, bool use_hl_decomp_ = false)
    : numNodes(numNodes_), root(root_), _nbr(numNodes_), use_hl_decomp(use_hl_decomp_) {
    if (numNodes == 1) _set_parent();
  }

  ll add_edge(ll x, ll y) {
    ll i = ssize(_edges);
    if (i >= numNodes - 1) throw range_error("add_edge");
    _nbr[x].emplace_back(y, i);
    _nbr[y].emplace_back(x, i);
    _edges.emplace_back(min(x, y), max(x, y));
    if (i + 1 == numNodes - 1) _set_parent();
    return i;
  }

  void _set_parent() {   // called from constructor, add_edge() and change_root()

    _depth.resize(numNodes);
    _stsize.resize(numNodes);

    auto dfs = [&](auto rF, ll nd, ll pt) -> void {
      _depth[nd] = pt == -1 ? 0 : _depth[pt] + 1;
      _stsize[nd] = 1;
      ll idx_parent = -1;
      ll sz_nbr = ssize(_nbr[nd]);
      for (ll i = 0; i < sz_nbr; i++) {
        auto [c_id, c_eg] = _nbr[nd][i];
        if (c_id == pt) idx_parent = i;
        else {
          rF(rF, c_id, nd);
          _stsize[nd] += _stsize[c_id];
        }
      }
      if (nd != root) {
        assert(idx_parent >= 0);
        swap(_nbr[nd][idx_parent], _nbr[nd][sz_nbr - 1]);
      }
    };

    dfs(dfs, root, -1);

    if (use_hl_decomp) _set_heavy();
  }

  void mature_check() const {
#if DEBUG
    if (ssize(_edges) != numNodes - 1) throw function_error("Not enough edges have been added.");
#endif    
  }

  pe_t parent_pe(ll nd) const {
    mature_check();
    return nd == root ? pe_t(-1, -1) : _nbr[nd][ssize(_nbr[nd]) - 1];
  }
  ll parent(ll nd) const { return nd == root ? -1 : parent_pe(nd).peer; }
  ll num_children(ll nd) const {
    mature_check();
    return ssize(_nbr[nd]) - (nd == root ? 0 : 1);
  }
  pe_t child_pe(ll nd, ll idx) const {
    mature_check();
    return _nbr[nd][idx];
  }
  ll child(ll nd, ll idx) const { return child_pe(nd, idx).peer; }
  ll child_edge(ll nd, ll idx) const { return child_pe(nd, idx).edge; }
  auto children_pe(ll nd) const {
    mature_check();
    return children_view<false, true>(*this, nd);
  }
  auto children(ll nd) const {
    mature_check();
    return children_view<true, true>(*this, nd);
  }
  auto neighbor_pe(ll nd) const {
    mature_check();
    return children_view<false, false>(*this, nd);
  }
  auto neighbor(ll nd) const {
    mature_check();
    return children_view<true, false>(*this, nd);
  }

  ll stsize(ll nd) const {
    mature_check();
    return _stsize[nd];
  }

  ll depth(ll nd) const {
    mature_check();
    return _depth[nd];
  }

  ll _enc_node_pair(ll x, ll y) const { return (x + 1) * (numNodes + 1) + (y + 1); }

  ll edge_idx(ll x, ll y) const {
    auto [py, ey] = parent_pe(y);
    if (x == py) return ey;
    auto [px, ex] = parent_pe(x);
    if (y == px) return ex;
    return -1LL;
  }

  pair<ll, ll> nodes_of_edge(ll e, ll mode = 0) const {
    if (mode == -1) {
      return _edges[e];
    }else {
      const auto& [x, y] = _edges[e];
      if ((x == parent(y)) == (mode == 0)) return {x, y};
      else return {y, x};
    }
  }

  void _set_euler() {
    if (not _euler_in.empty()) return;

    mature_check();
    _euler_in.resize(numNodes);
    _euler_out.resize(numNodes);
    _euler_edge.resize(2 * numNodes);
    ll euler_idx = 0;

    auto dfs = [&](auto rF, ll nd) -> void {
      ll edge = nd == root ? numNodes - 1 : edge_idx(nd, parent(nd));
      _euler_edge[euler_idx] = {edge, 0};
      _euler_in[nd] = euler_idx;
      euler_idx++;
      for (ll c : children(nd)) rF(rF, c);
      _euler_edge[euler_idx] = {edge, 1};
      _euler_out[nd] = euler_idx;
      euler_idx++;
    };
    dfs(dfs, root);

  };

  ll euler_in(ll nd) {
    _set_euler();
    return _euler_in[nd];
  }

  ll euler_out(ll nd) {
    _set_euler();
    return _euler_out[nd];
  }

  tuple<ll, ll, ll> euler_elem(ll idx) {
    _set_euler();

    if (idx == 0) return {numNodes - 1, -1, root};
    else if (idx == 2 * numNodes - 1) return {numNodes - 1, root, -1};
    else {
      auto [e, b] = _euler_edge[idx];
      auto [x, y] = nodes_of_edge(e, b);
      return {e, x, y};
    }
  }
  ll euler_elem_edge(ll idx) { return get<0>(euler_elem(idx)); }
  ll euler_elem_from(ll idx) { return get<1>(euler_elem(idx)); }
  ll euler_elem_to(ll idx) { return get<2>(euler_elem(idx)); }

  void _set_heavy() {
    if (not _heavy_head.empty()) return;

    mature_check();
    if (not _euler_in.empty()) {
      throw function_error("_set_heavy() was called too late.  Consider `use_hl_decomp` parameter of the Tree constructor.");
    }
    _heavy_head.resize(numNodes);

    auto dfs = [&](auto rF, ll nd, ll head) -> void {
      _heavy_head[nd] = head;
      if (ll nc = num_children(nd); nc == 0) return;
      else {
        ll i0 = -1, vmax = 0;
        for (ll i = 0; i < nc; i++) if (ll v = stsize(child(nd, i)); v > vmax) { vmax = v; i0 = i; }
        if (i0 > 0) swap(_nbr[nd][0], _nbr[nd][i0]);
        rF(rF, child(nd, 0), head);
        for (ll i = 1; i < nc; i++) rF(rF, child(nd, i), child(nd, i));
      }
    };
    dfs(dfs, root, root);
  }

  ll heavy_head(ll x) {
    _set_heavy();
    return _heavy_head[x];
  }

  template<bool constr_path>
  auto _hl_follow(ll x, ll y) {
    _set_heavy();
    assert(x != y);
    ll hx = heavy_head(x);
    ll hy = heavy_head(y);
    vector<pll> vx{{hx, x}};
    vector<pll> vy{{hy, y}};

    auto op = [&](ll& h, auto& v) {
      ll p = parent(h);
      h = heavy_head(p);
      if constexpr (constr_path) v.emplace_back(h, p);
      else                      v[0] = {h, p};
    };

    while (hx != hy) {
      if (depth(hx) < depth(hy)) op(hy, vy);
      else op(hx, vx);
    }

    auto [_dummy_x, tx] = vx.back(); vx.pop_back();
    auto [_dummy_y, ty] = vy.back(); vy.pop_back();

    if constexpr (constr_path) {

      vector<pair<ll, ll>> ret;
      auto append_ret = [&](const auto& vec) -> void {
        for (int i = ssize(vec) - 1; i >= 0; i--) {
          auto [h, t] = vec[i];
          ret.emplace_back(euler_in(h), euler_in(t) + 1);
        }
      };

      if (tx == ty) {
        if (not vx.empty() and not vy.empty() and euler_in(vx.back().first) > euler_in(vy.back().first)) swap(vx, vy);
        append_ret(vx);
        append_ret(vy);
      }else {
        if (depth(tx) < depth(ty)) {
          swap(tx, ty);
          swap(vx, vy);
        }
        ret.emplace_back(euler_in(ty) + 1, euler_in(tx) + 1);
        append_ret(vx);
        append_ret(vy);
      }
      return ret;

    }else {
      return depth(tx) < depth(ty) ? tx : ty;
    }
  }

  vector<pair<ll, ll>> hl_path(ll x, ll y) {
    _set_heavy(); // this should be called even if x == y
    return (x == y) ? vector<pair<ll,ll>>{} : _hl_follow<true>(x, y);
  }

  // Lowest Common Ancestor
  ll lca(ll x, ll y) {
    _set_heavy(); // this should be called even if x == y
    return (x == y) ? x : _hl_follow<false>(x, y);
  }

  // the path between two nodes (list of nodes, including x and y)
  vector<ll> nnpath(ll x, ll y) {
    vector<ll> ret;
    ll c = lca(x, y);
    for ( ; x != c; x = parent(x)) ret.push_back(x);
    ret.push_back(c);
    ll len = (ll)ret.size();
    for ( ; y != c; y = parent(y)) ret.push_back(y);
    reverse(ret.begin() + len, ret.end());
    return ret;
  }

  ll ancestor_at_depth(ll x, ll dp) {
    if (depth(x) < dp) return -1;
    while (true) {
      ll h = heavy_head(x);
      if (depth(h) <= dp) return euler_elem_to(euler_in(h) + dp - depth(h));
      x = parent(h);
    }
  }


  tuple<ll, ll, ll, ll, ll> diameter() {
    if (numNodes == 1) return {0, 0, 0, 0, 0};
    if (numNodes == 2) return {1, 0, 1, 0, 1};
    mature_check();
    ll nd0 = max_element(_depth.begin(), _depth.end()) - _depth.begin();
    vector<ll> parent2(numNodes);
    auto dfs2 = [&](auto rF, ll nd, ll dp, ll pt) -> pair<ll, ll> {
      parent2[nd] = pt;
      pair<ll, ll> ret(dp, nd);
      for (auto [cld, _e] : _nbr[nd]) {
        if (cld == pt) continue;
        auto c_val = rF(rF, cld, dp + 1, nd);
        if (ret.first < c_val.first) ret = c_val;
      }
      return ret;
    };
    auto [dp, nd1] = dfs2(dfs2, nd0, 0, -1);
    ll ct0, ct1;
    {
      ll x = nd1;
      for (ll i = 0; i < dp / 2; i++) x = parent2[x];
      if (dp % 2 == 0) ct0 = ct1 = x;
      else {
        ct1 = x;
        ct0 = parent2[x];
      }
    }
    return {dp, nd0, nd1, ct0, ct1};
  }

  pair<ll, ll> centroids() {
    auto dfs = [&](auto rF, ll nd) -> pair<ll, ll> {
      for (ll c : children(nd)) {
        ll a = 2 * stsize(c);
        if (a > numNodes) return rF(rF, c);
        if (a == numNodes) return make_pair(nd, c);
      }
      return make_pair(nd, -1);
    };
    return dfs(dfs, root);
  }

  void change_root(ll newRoot) {
    _stsize.clear();
    _depth.clear();
    _euler_in.clear();
    _euler_out.clear();
    _lca_tbl.clear();

    root = newRoot;
    _set_parent();
  }

  string show() { // for debug
    string ret;
    for (int nd = 0; nd < numNodes; nd++) {
      string sc;
      for (int c : children(nd)) sc += format("{:2d} ", c);
      ret += format("{:1} {:2d}: {}\n", nd == root ? "R" : "", nd, sc);
    }
    string se;
    for (int e = 0; e < numNodes - 1; e++) {
      auto [a, b] = nodes_of_edge(e);
      se += format("({}: {}-{}) ", e, a, b);
    }
    ret += se;
    return ret;
  }


};

// const Tree::pe_t end_object{-1, -1};

template <typename M>
auto reroot(Tree& tree, const M& unit, auto add, auto mod1, auto mod2) {
  using A = decltype(mod2(M(), 0));
  vector<A> result(tree.numNodes);
  vector<vector<M>> sum_left(tree.numNodes);
  vector<vector<M>> sum_right(tree.numNodes);
  
  auto dfs1 = [&](const auto& recF, ll nd) -> A {
    ll k = tree.num_children(nd);
    vector<M> ws(k);
    for (ll i = 0; i < k; i++) {
      ll c = tree.child(nd, i);
      ws[i] = mod1(recF(recF, c), nd, c);
    }
    sum_left[nd].resize(k + 1, unit);
    sum_right[nd].resize(k + 1, unit);
    for (ll i = 0; i < k; i++) sum_left[nd][i + 1] = add(sum_left[nd][i], ws[i]);
    for (ll i = k - 1; i >= 0; i--) sum_right[nd][i] = add(sum_right[nd][i + 1], ws[i]);
    return mod2(sum_right[nd][0], nd);
  };
  dfs1(dfs1, tree.root);

  auto dfs2 = [&](const auto& recF, ll nd, const M& t) -> void {
    result[nd] = mod2(add(sum_right[nd][0], t), nd);
    ll k = tree.num_children(nd);
    for (ll i = 0; i < k; i++) {
      ll c = tree.child(nd, i);
      M excl_c = add(sum_left[nd][i], sum_right[nd][i + 1]);
      M m_for_c = add(excl_c, t);
      A v_for_c = mod2(m_for_c, nd);
      M pass_c = mod1(v_for_c, c, nd);
      recF(recF, c, pass_c);
    }
  };
  dfs2(dfs2, tree.root, unit);
  
  return result;
}

template <typename M>
vector<M> reroot(Tree& tree, const M& unit, auto add, auto mod1) {
  return reroot<M>(tree, unit, add, mod1, [](const M& m, ll) -> M { return m; });
}

// ---- end tree.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  Tree tr(N, 0, true);
  vector W(N - 1, 0LL);
  REP(i, 0, N - 1) {
    ll u, v, w; cin >> u >> v >> w; u--; v--;
    tr.add_edge(u, v);
    W[i] = w;
  }
  vector init_vec(2*N, 0LL);
  REP(i, 0, 2*N) {
    auto [e, x, y] = tr.euler_elem(i);
    if (e < N - 1) {
      if (x == tr.parent(y)) init_vec[i] = W[e];
      else init_vec[i] = -W[e];
    }
  }
  auto st = make_seg_tree(0LL, plus<ll>(), init_vec);
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    auto f = [&](ll a, ll b) -> ll {
      ll ret = st.query(tr.euler_in(a) + 1, tr.euler_in(b) + 1);
      return ret;
    };
    if (tp == 1) {
      ll i, w; cin >> i >> w; i--;
      W[i] = w;
      auto [x, y] = tr.nodes_of_edge(i);
      st.rs(tr.euler_in(y)) = w;
      st.rs(tr.euler_out(y)) = -w;
    }else if (tp == 2) {
      ll u, v; cin >> u >> v; u--; v--;
      ll z = tr.lca(u, v);
      ll ans = f(z, u) + f(z, v);
      cout << ans << "\n";
    }
             
  }

  return 0;
}

