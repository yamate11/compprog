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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

using ordered_set = tree<
  pll,
  null_type,
  less<pll>,
  rb_tree_tag,
  tree_order_statistics_node_update
  >;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  // @InpVec(N, A) [UHGOED5h]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [UHGOED5h]
  // @InpNbrList(N, N - 1, nbr, dec=1) [d1YNFTJs]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [d1YNFTJs]

  ordered_set os;

  auto dfs = [&](auto rF, ll nd, ll dp, ll pt) -> ll {
    ll ret = -1;
    os.insert(pll(A[nd], nd));
    if (nd != 0 and SIZE(nbr[nd]) == 1) {
      ll sz = SIZE(os);
      if (sz % 2 == 0) {
        auto [v, _i] = *os.find_by_order(sz / 2 - 1);
        auto [w, _j] = *os.find_by_order(sz / 2);
        ret = (v + w) / 2;
      }else {
        auto [v, _i] = *os.find_by_order(sz / 2);
        ret = v;
      }
    }else {
      bool first = true;
      for (ll cld : nbr[nd]) {
        if (cld == pt) continue;
        ll v = rF(rF, cld, dp + 1, nd);
        if (first) {
          ret = v;
          first = false;
        }else if (dp % 2 == 0) {
          ret = max(ret, v);
        }else {
          ret = min(ret, v);
        }
      }
    }
    os.erase(pll(A[nd], nd));
    return ret;
  };
  ll ans = dfs(dfs, 0, 0, -1);
  cout << ans << endl;
  return 0;
}

