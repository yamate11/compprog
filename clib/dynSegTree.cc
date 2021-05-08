/*
  Dynmaic Segment Tree

  Typical Usage:

  using DAT = ll;
  using OP = optional<ll>;
  const DAT unit_dat = LLONG_MAX;
  const OP unit_op = nullopt;
  auto xAdd = [](DAT x, DAT y) -> DAT { return min(x, y); };
  auto xAppl = [](int k, OP f, DAT x) -> DAT { return f.value_or(x); };
  auto xComp = [](OP h, OP g) -> OP { return h.has_value() ? h : g; };
  auto st = make_dyn_seg_tree(0, 1e8, unit_dat, unit_op, xAdd, xComp, xAppl);

  st.update(101, 200, 5000);
  ll ans = st.query(0, 1e8);
 */

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- dynSegTree.cc

template<typename DAT, typename OP> 
struct Node {
  // ll lo;
  // ll hi;
  DAT val;
  OP op;
  Node<DAT, OP> *lo_node;
  Node<DAT, OP> *hi_node;
  Node(/*ll lo_, ll hi_,*/ DAT val_, OP op_)
    : /*lo(lo_), hi(hi_),*/ val(val_), op(op_), lo_node(0), hi_node(0) {}

};

template<typename DAT, typename OP,
         typename Fadd, typename Fcomp, typename Fappl>
struct DynSegTree {
  /*int size;*/
  int tot_lo;
  int tot_hi;
  int height;
  Node<DAT, OP>* node;
  DAT unit_dat;
  OP unit_op;
  Fadd add;
  Fcomp comp;
  Fappl appl;

  DynSegTree(ll lo, ll hi, DAT unit_dat_, OP unit_op_,
             Fadd add_, Fcomp comp_, Fappl appl_)
    : tot_lo(lo), tot_hi(hi),
      unit_dat(unit_dat_), unit_op(unit_op_), add(add_), comp(comp_),
      appl(appl_) {
    node = new Node<DAT, OP>(/*lo_, hi_,*/ unit_dat, unit_op);
  }

  /*
  ~DynSegTree() {
    auto sub = [](auto rF, Node<DAT, OP>* nd) -> void {
      if (nd->lo_node) {
        rF(rF, nd->lo_node);
        rF(rF, nd->hi_node);
      }
      delete nd;
    };
    sub(sub, node);
  }
  */

  void push(Node<DAT, OP>* nd, ll lo, ll hi) {
    if (!nd->lo_node) {
      nd->lo_node = new Node<DAT, OP>(unit_dat, nd->op);
    }else {
      nd->lo_node->op = comp(nd->op, nd->lo_node->op);
    }
    if (!nd->hi_node) {
      nd->hi_node = new Node<DAT, OP>(unit_dat, nd->op);
    }else {
      nd->hi_node->op = comp(nd->op, nd->hi_node->op);
    }
    nd->val = appl(hi - lo, nd->op, nd->val);
    nd->op = unit_op;
  }

  DAT node_query(Node<DAT, OP>* nd, ll lo, ll hi, ll left, ll right) {
    if (!nd) return unit_dat;
    if (hi <= left || right <= lo) return unit_dat;
    if (left <= lo && hi <= right) {
      return appl(hi - lo, nd->op, nd->val);
    }
    ll mid = (lo + hi) / 2;
    push(nd, lo, hi);
    DAT val1 = node_query(nd->lo_node, lo, mid, left, right);
    DAT val2 = node_query(nd->hi_node, mid, hi, left, right);
    return appl(hi - lo, nd->op, add(val1, val2));
  }

  DAT query(ll left, ll right) {
    return node_query(node, tot_lo, tot_hi, left, right);
  }

  DAT node_update(Node<DAT, OP>* nd, ll lo, ll hi, ll left, ll right, OP f) {
    if (hi <= left || right <= lo) return appl(hi - lo, nd->op, nd->val);
    if (left <= lo && hi <= right) {
      nd->op = comp(f, nd->op);
      return appl(hi - lo, nd->op, nd->val);
    }
    ll mid = (lo + hi) / 2;
    push(nd, lo, hi);
    DAT val1 = node_update(nd->lo_node, lo, mid, left, right, f);
    DAT val2 = node_update(nd->hi_node, mid, hi, left, right, f);
    nd->val = add(val1, val2);
    // DLOGK(lo, hi, val1, val2, nd->val);
    return nd->val;
  }

  void update(ll left, ll right, OP f) {
    node_update(node, tot_lo, tot_hi, left, right, f);
  }

  /* for debugging */
  void show_nodes() {
    ll seq = 1;
    auto sub = [&](auto rF, ll this_seq,
                   Node<DAT, OP>* nd, ll lo, ll hi) -> void {
      ll ts1 = 0, ts2 = 0;
      if (nd->lo_node) {
        ts1 = seq++;
        ts2 = seq++;
      }
      cerr << "{" << this_seq << "} [" << lo << ", " << hi << ") val="
           << nd->val << ", op=" << nd->op;
      if (ts1 > 0) {
        cerr << ", lo_node=" << ts1 << ", hi_node=" << ts2;
      }
      cerr << endl;
      if (ts1 > 0) {
        ll mid = (lo + hi) / 2;
        rF(rF, ts1, nd->lo_node, lo, mid);
        rF(rF, ts2, nd->hi_node, mid, hi);
      }
    };
    cerr << endl;
    sub(sub, seq++, node, tot_lo, tot_hi);
  }
  
};

template<typename DAT, typename OP>
auto make_dyn_seg_tree(ll lo_, ll hi_, DAT unit_dat, OP unit_op,
                       auto add, auto comp, auto appl)
  -> DynSegTree<DAT, OP, decltype(add), decltype(comp), decltype(appl)> {
  return DynSegTree(lo_, hi_, unit_dat, unit_op, add, comp, appl);
}

// @@ !! END ---- doubling.cc

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    using DAT = ll;
    using OP = optional<ll>;
    const DAT unit_dat = LLONG_MAX;
    const OP unit_op = nullopt;
    auto xAdd = [](DAT x, DAT y) -> DAT { return min(x, y); };
    auto xComp = [](OP h, OP g) -> OP { return h.has_value() ? h : g; };
    auto xAppl = [](int k, OP f, DAT x) -> DAT { return f.value_or(x); };
    auto dst = make_dyn_seg_tree(0, 64, unit_dat, unit_op, xAdd, xComp, xAppl);

    dst.update(11, 12, 100);
    // dst.show_nodes();
    dst.update(20, 21, 200);
    // dst.show_nodes();
    assert(dst.query(0, 64) == 100);
    assert(dst.query(0, 15) == 100);
    assert(dst.query(15, 30) == 200);
    dst.update(30, 50, 500);
    assert(dst.query(40, 42) == 500);
  }

  random_device rand_dev;
  mt19937 rng(rand_dev());
  auto get_pqx = [&](ll sz) -> tuple<ll, ll, ll> {
    uniform_int_distribution<ll> dist1(0, sz);
    ll p, q;
    while (true) {
      p = dist1(rng);
      q = dist1(rng);
      if (p > q) swap(p, q);
      if (p < q) break;
    }
    uniform_int_distribution<ll> dist2(-1e9, 1e9);
    // uniform_int_distribution<ll> dist2(0, 5);
    ll x = dist2(rng);
    return {p, q, x};
  };

  ll rep1 = 500;
  ll rep2 = 500;

  auto run_test = [&](auto unit_dat, auto unit_op,
                      auto xAdd, auto xComp, auto xAppl) -> void {
    for (ll sz: vector<ll>({10, 1000})) {
      uniform_int_distribution<ll> dist(0, sz);
      vector<ll> cmp(sz);
      for (ll i = 0; i < rep1; i++) {
        // DLOG("---start");
        auto dst = make_dyn_seg_tree(0, sz, unit_dat, unit_op,
                                     xAdd, xComp, xAppl);
        for (ll j = 0; j < sz; j++) cmp[j] = unit_dat;
        for (ll j = 0; j < rep2; j++) {
          auto [p, q, x] = get_pqx(sz);
          dst.update(p, q, x);
          // DLOGK(p, q, x);
          for (ll k = p; k < q; k++) cmp[k] = xAppl(1, x, cmp[k]);
          auto [p2, q2, x2] = get_pqx(sz);
          ll y = dst.query(p2, q2);
          ll y_cmp = unit_dat;
          for (ll k = p2; k < q2; k++) y_cmp = xAdd(y_cmp, cmp[k]);
          // DLOGK(p2, q2, y, y_cmp);
          assert(y == y_cmp);
        }
      }
    }
  };

  {
    using DAT = ll;
    using OP = optional<ll>;
    const DAT unit_dat = LLONG_MAX;
    const OP unit_op = nullopt;
    auto xAdd = [](DAT x, DAT y) -> DAT { return min(x, y); };
    auto xComp = [](OP h, OP g) -> OP { return h.has_value() ? h : g; };
    auto xAppl = [](int k, OP f, DAT x) -> DAT { return f.value_or(x); };
    run_test(unit_dat, unit_op, xAdd, xComp, xAppl);
  }

  {
    using DAT = ll;
    using OP = ll;
    const DAT unit_dat = 0;
    const OP unit_op = 0;
    auto xAdd = [](DAT x, DAT y) -> DAT { return x + y; };
    auto xAppl = [](int k, OP f, DAT x) -> DAT { return k * f + x; };
    auto xComp = [](OP h, OP g) -> OP { return h + g; };
    run_test(unit_dat, unit_op, xAdd, xComp, xAppl);
  }

  {
    using DAT = ll;
    using OP = optional<ll>;
    const DAT unit_dat = 0;
    const OP unit_op = nullopt;
    auto xAdd = [](DAT x, DAT y) -> DAT { return x + y; };
    auto xAppl = [](int k, OP f, DAT x) -> DAT {
      return f.has_value() ? k * f.value() : x;
    };
    auto xComp = [](OP h, OP g) -> OP { return h.has_value() ? h : g; };
    run_test(unit_dat, unit_op, xAdd, xComp, xAppl);
  }


  return 0;
}

