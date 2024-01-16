#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using pair_t = pair<int, int>;
  using ordered_set = tree<
    pair_t,
    null_type,
    less<pair_t>,
    rb_tree_tag,
    tree_order_statistics_node_update
    >;

  ordered_set os;
  ll Q; cin >> Q;
  REP(q, 0, Q) {
    ll t, x; cin >> t >> x;
    if (t == 1) {
      os.insert(pair_t(x, q));
    }else if (t == 2) {
      x--;
      auto it = os.find_by_order(x);
      auto [v, dummy] = *it;
      cout << v << "\n";
      os.erase(it);
    }else assert(0);
  }

  return 0;
}

