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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpVec(N, A) [MrxxNnFK]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [MrxxNnFK]
    vector C(N + 1, 0LL);
    REP(i, 0, N) C[A[i]]++;
    vector D(N + 2, 0LL);
    REP(i, 0, N + 1) D[i + 1] = D[i] + C[i];
    ll ans = 0;
    REP(i, 0, N + 1) {
      if (C[i] >= 3) ans += C[i] * (C[i] - 1) * (C[i] - 2) / 6;
      if (C[i] >= 2) ans += C[i] * (C[i] - 1) / 2 * D[i];
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

