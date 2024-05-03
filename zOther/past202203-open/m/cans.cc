#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  using ordered_set = tree<
    pll,
    null_type,
    less<pll>,
    rb_tree_tag,
    tree_order_statistics_node_update
    >;
  ordered_set os;
  
  ll N, Q; cin >> N >> Q;
  // @InpVec(N, P) [2BTjlunc]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [2BTjlunc]
  REP(i, 0, N) os.insert(pll(P[i], i));

  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll a, x; cin >> a >> x; a--;
      os.erase(pll(P[a], a));
      P[a] = x;
      os.insert(pll(P[a], a));
    }else if (tp == 2) {
      ll a; cin >> a; a--;
      ll m = os.order_of_key(pll(P[a], a));
      cout << 1 + N - (m + 1) << "\n";
    }else if (tp == 3) {
      ll r; cin >> r;
      ll m = N - r;
      auto [p, a] = *os.find_by_order(m);
      cout << a + 1 << "\n";
    }else assert(0);
  }

  return 0;
}

