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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using ordered_set = tree<
  ll,
  null_type,
  less<ll>,
  rb_tree_tag,
  tree_order_statistics_node_update
  >;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  ordered_set os;

  REP(i, 1, N + 1) os.insert(i);
  vector<ll> ans;
  ll z = 1;
  REPrev(i, N, 1) {
    ll x = i * z;
    ll y = x / K;
    z = x % K;
    if (z == 0) {
      auto it = os.find_by_order(y - 1);
      ans.push_back(*it);
      os.erase(it);
      vector<ll> rem;
      for (ll j : os) rem.push_back(j);
      reverse(ALL(rem));
      for (ll j : ans) cout << j << "\n";
      REPOUT(j, 0, SIZE(rem), rem[j], "\n");
      return 0;
    }
    auto it = os.find_by_order(y);
    ans.push_back(*it);
    os.erase(it);
  }
  assert(0);

  return 0;
}

