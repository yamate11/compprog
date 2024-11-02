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
    ll N, M, Q; cin >> N >> M >> Q;
    // @InpVec(M, B) [InlRcx5B]
    auto B = vector(M, ll());
    for (int i = 0; i < M; i++) { ll v; cin >> v; B[i] = v; }
    // @End [InlRcx5B]
    // @InpVec(Q, A) [NAq8Meb8]
    auto A = vector(Q, ll());
    for (int i = 0; i < Q; i++) { ll v; cin >> v; A[i] = v; }
    // @End [NAq8Meb8]
    sort(ALL(B));
    REP(i, 0, Q) {
      ll t = upper_bound(ALL(B), A[i]) - B.begin();
      ll ans;
      if (t == 0) ans = B[0] - 1;
      else if (t == M) ans = N - B[M - 1];
      else ans = (B[t] - B[t - 1]) / 2;
      cout << ans << "\n";
    }
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

