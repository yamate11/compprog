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
    ll N, M; cin >> N >> M;
    // @InpMVec(M, ((L, dec=1), (R, dec=0))) [N6jT0OfP]
    auto L = vector(M, ll());
    auto R = vector(M, ll());
    for (int i = 0; i < M; i++) {
      ll v1; cin >> v1; v1 -= 1; L[i] = v1;
      ll v2; cin >> v2; v2 -= 0; R[i] = v2;
    }
    // @End [N6jT0OfP]

    ll k = 0;
    REP(i, 0, M) k = max(k, R[i] - L[i]);
    vector<ll> ans(N);
    REP(i, 0, N) ans[i] = i % k;
    REPOUT(i, 0, N, ans[i] + 1, " ");
  };


  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

