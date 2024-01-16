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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, Q; cin >> N >> Q;
  using sta = tuple<ll, ll, ll>;
  vector<sta> XST;
  REP(i, 0, N) {
    ll s, t, x; cin >> s >> t >> x;
    XST.emplace_back(x, s, t);
  }
  sort(ALL(XST));
  // @InpVec(Q, D) [At22IdnF]
  auto D = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; D[i] = v; }
  // @End [At22IdnF]

  vector<ll> ans(Q, -1LL);
  set<pll> ss;
  REP(i, 0, Q) ss.emplace(D[i], i);
  for (auto [x, s, t] : XST) {
    auto it1 = ss.lower_bound(pll(s - x, -1LL));
    auto it2 = ss.lower_bound(pll(t - x, -1LL));
    for (auto it = it1; it != it2; ) {
      auto [_y, i] = *it;
      ans[i] = x;
      it = ss.erase(it);
    }
  }
  REPOUT(i, 0, Q, ans[i], "\n");

  return 0;
}

