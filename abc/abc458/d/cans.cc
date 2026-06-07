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

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// @@ !! LIM()

using elem_t = pair<int, int>;   // ここを，要素の型にする
using pbds_set = tree<
  elem_t,
  null_type,
  less<elem_t>,
  rb_tree_tag,
  tree_order_statistics_node_update
  >;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  pbds_set ss;

  ll X; cin >> X;
  ll Q; cin >> Q;
  ss.insert(pll(X, 0));
  REP(q, 0, Q) {
    ll a, b; cin >> a >> b;
    ss.insert(pll(a, q + 1));
    ss.insert(pll(b, -(q + 1)));
    pll p = *ss.find_by_order(q + 1);
    cout << p.first << "\n";
  }
  

  return 0;
}

