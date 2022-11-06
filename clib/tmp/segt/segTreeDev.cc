#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

/*
  Segment Tree (non-recursive version; including laziness)

  Typical Usage:

  SegTree<DAT, OP, decltype(add), decltype(apply)> st(unit_dat, add, apply, init_vec);
  // or
  st = make_seg_tree(unit_dat, add, apply, init_vec);

  st.update(i, x);
  DAT x = st.query(il, ir);
  DAT x = st[i];

  SegTreeLazy<DAT, OP, decltype(add), decltype(comp), decltype(apply)> st(unit_dat, add, unit_op, comp, apply, init_vec);
  // or
  st = make_seg_tree_lazy(unit_dat, add, unit_op, comp, apply, init_vec);

  // It must be hold:
  //       - apply(h, add(x, y)) = add(apply(h, x), apply(h, y)) 
  //       - apply(unit_op, x) = x

  st.update(il, ir, x);
  DAT x = st.query(il, ir);
  DAT x = st[i];


  Binary Search:
  
  auto check = [&](DAT x) -> bool { ...; };
  ll ir = st.binsearch_r_min(check, il);
    // ir = min ir s.t. check(st.query(il, ir)) == true; or ir = SZ + 1 if not exists
    //    check(st.query(il, ir)) == true and ir <= ir' => check(st.query(il, ir')) == true
  ll ir = st.binsearch_r_max(check, il);
    // ir = max ir s.t. check(st.query(il, ir)) == true; or ir = il - 1 if not exists
    //    check(st.query(il, ir)) == true and ir' <= ir => check(st.query(il, ir')) == true
  ll il = st.binsearch_l_min(check, ir);
    // il = min il s.t. check(st.query(il, ir)) == true; or il = ir + 1 if not exists
    //    check(st.query(il, ir)) == true and il <= il' => check(st.query(il', ir)) == true
  ll il = st.binsearch_l_max(check, ir);
    // il = max il s.t. check(st.query(il, ir)) == true; or il = -1 if not exists
    //    check(st.query(il, ir)) == true and il' <= il => check(st.query(il', ir)) == true

 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN(f:<<) ---- segTree.cc

// It seems that we should keep the size power of two,
// considering the binary search.

template <typename DAT, typename OP,
	  typename ADD_t, typename COMP_t, typename APPL_t, bool lazy> 
struct GenSegTree {
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
    
  GenSegTree(DAT unit_dat_, OP unit_op_, ADD_t add_, COMP_t comp_, APPL_t appl_, const vector<DAT>& initdat)
    : orig_size(initdat.size()), unit_dat(unit_dat_), unit_op(unit_op_),
      add(add_), comp(comp_), appl(appl_) { _set_data(initdat); }

  void _set_data(const vector<DAT>& initdat) {
    if (initdat.size() <= 0) {
      cerr << "the size of initial vector must be >= 1" << endl;
      abort();
    }
    if (initdat.size() == 1) height = 0;
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

  template<bool xx = lazy> enable_if_t<! xx> update(int i, DAT t) {
    ll x = size + i;
    node[x] = t;
    for (x >>= 1; x >= 1; x >>= 1) node[x] = add(node[x<<1|0], node[x<<1|1]);
  }

  template<bool xx = lazy> enable_if_t<xx> update(int l, int r, OP f) {
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

  void _gen_update(int l, int r, OP f) {
    if (l >= r) return;
    l += size;
    r += size;
    if constexpr(lazy) push_upto(l, r);
    int l0 = l, r0 = r;
    while (l < r) {
      if (l & 1) {
	if constexpr(lazy) node_op(l, f);
	l++;
      }
      if (r & 1) {
	if constexpr(lazy) node_op(r-1, f);
      }
      l >>= 1;
      r >>= 1;
    }
    child_updated(l0, r0);
  }

  const DAT& operator[](int i) const { return node[size + i]; }

  int binsearch_r_max(const auto& check, int l) {
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
        if (x == 1) return orig_size;
        x++;
      }
      x >>= 1;
    }
    while (x < size) {
      if constexpr(lazy) push_one(x);
      x <<= 1;
      DAT t = add(val, node[x]);
      if (check(t)) {
        x++;
        val = t;
      }
    }
    return min(x - size, orig_size);
  }

  int binsearch_r_min(const auto& check, int l) { return binsearch_r_max([&](ll x) { return not check(x); }, l) + 1; }

  int binsearch_l_min(const auto& check, int r) {
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

  int binsearch_l_max(const auto& check, int r) { return binsearch_l_min([&](ll x) { return not check(x); }, r) - 1; }

};

template<typename DAT, typename OP>
auto mk_seg_tree_lazy(DAT unit_dat, OP unit_op, auto add, auto comp, auto appl, const vector<DAT>& initdat) {
// -> GenSegTree<DAT, OP, decltype(add), decltype(comp), decltype(appl), true> {
  using ret_t = GenSegTree<DAT, OP, decltype(add), decltype(comp), decltype(appl), true>;
  return ret_t(unit_dat, unit_op, add, comp, appl, initdat);
}

template<typename DAT>
auto mk_seg_tree(DAT unit_dat, auto add, const vector<DAT>& initdat) {
  //  -> GenSegTree<DAT, void *, decltype(add), decltype(comp), decltype(appl), true> {
  auto dummy_comp = [](void* x, void* y) -> void* { return nullptr; };
  auto dummy_appl = [](void* f, DAT x) -> DAT { return DAT(); };
  using ret_t = GenSegTree<DAT, void*, decltype(add), decltype(dummy_comp), decltype(dummy_appl), false>;
  return ret_t(unit_dat, nullptr, add, dummy_comp, dummy_appl, initdat);
}

/*
template<typename DAT, typename OP>
auto make_seg_tree(DAT unit_dat, OP unit_op,
		   auto add, auto comp, auto appl,
		   bool range_update)
  -> SegTree<DAT, OP, decltype(add), decltype(comp), decltype(appl)> {
  return SegTree(unit_dat, unit_op, add, comp, appl, range_update);
}
*/

// @@ !! END ---- segTree.cc

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    using OP = optional<ll>;

    auto add = [&](ll x, ll y) -> ll { return min(x, y); };
    auto comp = [&](OP h, OP g) -> OP { return h.has_value() ? h : g; };
    auto apply = [&](OP f, ll x) -> ll { return f.value_or(x); };

    vector<ll> init_vec{5, 1, 2, 3, 7};
    auto st = mk_seg_tree_lazy(LLONG_MAX, OP(), add, comp, apply, init_vec);

    assert(st.query(0, 5) == 1);
    assert(st[2] == 2);
    st.update(1, 4, 10);
    assert(st.query(0, 5) == 5);
  }
  {
    auto add = [&](ll x, ll y) -> ll { return min(x, y); };

    vector<ll> init_vec{5, 1, 2, 3, 7};
    auto st = mk_seg_tree(LLONG_MAX, add, init_vec);

    assert(st.query(0, 5) == 1);
    assert(st[2] == 2);
    st.update(1, 10);
    assert(st.query(0, 5) == 2);
  }

}

