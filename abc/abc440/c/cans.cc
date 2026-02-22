#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
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
    ll N, W; cin >> N >> W;
    // @InpVec(N, C) [E7kEog10]
    auto C = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
    // @End [E7kEog10]

    vector<ll> vec(2*W * 2);
    REP(i, 0, N) {
      ll j = i % (2*W);
      vec[j] += C[i];
      vec[2*W + j] += C[i];
    }
    vector<ll> S(2*W * 2 + 1);
    REP(i, 0, 2*W * 2) S[i + 1] = S[i] + vec[i];
    ll big = 1e18;
    ll ans = big;
    REP(i, 0, 2*W) ans = min(ans, S[i + W] - S[i]);
    cout << ans << "\n";

    

  };

  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

