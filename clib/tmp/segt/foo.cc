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

// @@ !! LIM()



int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  
  SegTree<DAT, OP, decltype(add), decltype(apply)> st(unit_dat, add, apply, init_vec);
  // or
  st = make_seg_tree(unit_dat, add, apply, init_vec);
  st.update(i, x);
  DAT x = st.query(il, ir);
  DAT x = st[i];

  SegTreeLazy<DAT, OP, decltype(add), decltype(comp), decltype(apply)> st(unit_dat, add, unit_op, comp, apply, init_vec);
  // or
  st = make_seg_tree_lazy(unit_dat, add, unit_op, comp, apply, init_vec);
  st.update(il, ir, x);
  DAT x = st.query(il, ir);
  DAT x = st[i];

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

}

