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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, P, dec=1) [BnwSoHNK]
    auto P = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
    // @End [BnwSoHNK]
    vector<ll> ans;
    auto chg = [&](ll i) -> void {
      ans.push_back(i);
      swap(P[i], P[i + 1]);
    };
    ll x = N - 1;
    for (; x >= 0; x--) {
      if (P[x] == x) continue;
      ll i = 0; for (; P[i] != x; i++);
      ll par = SIZE(ans) % 2;
      if (i % 2 != par) {
        if (i + 2 <= x) chg(i + 1);
        else if (i - 3 >= 0) chg(i - 3);
        else if (i - 1 >= 0) {
          chg(--i);
          chg(i + 1);
        }else { // x == 1, i == 0, par == 1
          chg(1);
          x = 3;
          continue;
        }
      }
      REP(j, i, x) chg(j);
    }
    cout << SIZE(ans) << "\n";
    REPOUT(i, 0, SIZE(ans), 1 + ans[i], " ");
  };

  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

