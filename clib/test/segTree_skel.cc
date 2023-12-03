#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
using pll = pair<ll, ll>;

// @@ !! LIM(debug segTree)

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
    assert(st[2] == 2);
    st.update(1, 10);
    assert(st[1] == 10);
    assert(st.query(0, 2) == 5);
    assert(st.query(0, 5) == 2);
    st.update(2, 20);
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
    assert(st[2] == 2);
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
    st3.update(4, 0);
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
        st.update(i, x);
        nv.update(i, i + 1, x);
      }
      ll j = randrange(0, sz);
      ll k = randrange(j, sz);
      assert(st.query(j, k) == nv.query(j, k));
      ll jj = randrange(0, sz);
      assert(st[jj] == nv.query(jj, jj + 1));
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
      assert(st[jj].first == nv.query(jj, jj + 1));
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
        st.update(i, x);
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
  st1.update(0, -100);
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
  vec4[0].update(2, 10);
  vec4[1].update(9, 20);
  assert(vec4[0].query(0, 5) + vec4[1].query(0, 10) == 30);
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

  cout << "Test done." << endl;
  return 0;
}

