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

using pair_t = pair<string, int>;
using ordered_set = tree<
  pair_t,
  null_type,
  less<pair_t>,
  rb_tree_tag,
  tree_order_statistics_node_update
  >;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, S, type=string) [M4rSGrj3]
  auto S = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; S[i] = v; }
  // @End [M4rSGrj3]

  ordered_set os;
  REP(i, 0, N) os.insert(pair_t(S[i], i));

  REP(_q, 0, Q) {
    ll x; cin >> x; x--;
    string t; cin >> t;
    auto it = os.find_by_order(x);
    auto [_d, j] = *it;
    os.erase(it);
    os.insert(pair_t(t, j));
  }
  vector<string> ans(N);
  for (auto [s, i] : os) ans[i] = s;
  REPOUT(i, 0, N, ans[i], " ");


  return 0;
}

