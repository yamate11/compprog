#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

using ordered_set = tree<
  ll,
  null_type,
  less<ll>,
  rb_tree_tag,
  tree_order_statistics_node_update
  >;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ordered_set os;
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll t, x; cin >> t >> x;
    if (t == 1) {
      os.insert(x);
    }else if (t == 2) {
      auto it = os.find_by_order(x - 1);
      cout << *it << "\n";
      os.erase(it);
    }
  }

  return 0;
}

