#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

using pll = pair<ll, ll>;
using myset = tree<
  pll,
  null_type,
  greater<pll>,
  rb_tree_tag,
  tree_order_statistics_node_update
  >;


int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> C(N);
  vector<ll> X(N);
  REP(i, N) cin >> C[i];
  REP(i, N) cin >> X[i];
  vector<myset> bycol(N + 1);
  myset total;
  ll ans = 0;
  REP(i, N) {
    ll c = C[i];
    ll x = X[i];
    ans += total.order_of_key(pll(x, N + 10)) - bycol[c].order_of_key(pll(x, N + 10));
    total.insert(pll(x, i));
    bycol[c].insert(pll(x, i));
  }
  cout << ans << endl;

  return 0;
}

