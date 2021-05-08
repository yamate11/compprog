#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(debug segTree)


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

