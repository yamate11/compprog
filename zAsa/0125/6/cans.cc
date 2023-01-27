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

  ll W, H; cin >> W >> H;
  // @InpVec(W, P) [mV9rwBJY]
  auto P = vector(W, ll());
  for (int i = 0; i < W; i++) { ll v; cin >> v; P[i] = v; }
  // @End [mV9rwBJY]
  // @InpVec(H, Q) [EP18b7XJ]
  auto Q = vector(H, ll());
  for (int i = 0; i < H; i++) { ll v; cin >> v; Q[i] = v; }
  // @End [EP18b7XJ]
  vector<pll> ord;
  REP(i, 0, W) ord.emplace_back(0, i);
  REP(i, 0, H) ord.emplace_back(1, i);
  sort(ALL(ord), [&](pll o1, pll o2) -> bool {
    auto [d1, i1] = o1;
    auto [d2, i2] = o2;
    ll p1 = d1 == 0 ? P[i1] : Q[i1];
    ll p2 = d2 == 0 ? P[i2] : Q[i2];
    return p1 < p2;
  });
  ll NP = 0;
  ll NQ = 0;
  ll ans = 0;
  for (auto [d, i] : ord) {
    ll val;
    if (d == 0) {
      val = P[i];
      ans += val * (H + 1 - NQ);
      NP++;
    }else {
      val = Q[i];
      ans += val * (W + 1 - NP);
      NQ++;
    }
  }
  cout << ans << endl;

  return 0;
}

