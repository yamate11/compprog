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
    ll N, K, X; cin >> N >> K >> X;
    // @InpVec(N, A) [mFvoY2Lh]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [mFvoY2Lh]

    vector B(N + 1, 0LL);
    REP(i, 0, N) B[i + 1] = B[i] + A[i];
    ll ans;
    if (B[N] >= X) {
      ll i = lower_bound(ALL(B), B[N] - X) - B.begin();
      if (B[N] - X == B[i]) ans = (K - 1) * N + i + 1;
      else                  ans = (K - 1) * N + i;
    }else {
      ll p = X / B[N];
      ll q = X % B[N];
      if (q == 0) {
        ans = (K - p) * N + 1;
      }else {
        ll i = lower_bound(ALL(B), B[N] - q) - B.begin();
        if (B[N] - q == B[i]) ans = (i + 1) + (K - (p + 1)) * N;
        else                  ans = i       + (K - (p + 1)) * N;
      }
    }
    ans = max(0LL, ans);
    cout << ans << "\n";

  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

