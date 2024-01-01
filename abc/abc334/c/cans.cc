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

  ll N, K; cin >> N >> K;
  // @InpVec(K, A) [5icYUSwU]
  auto A = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; A[i] = v; }
  // @End [5icYUSwU]

  if (K % 2 == 0) {
    ll ans = 0;
    REP(i, 0, K/2) ans += A[2*i + 1] - A[2*i];
    cout << ans << endl;
    return 0;
  }
  vector P(K, 0LL), Q(K, 0LL);
  P[0] = 0;
  REP(i, 0, K/2) {
    P[2 * (i + 1)] = P[2 * i] + A[2 * i + 1] - A[2 * i];
  }
  Q[K - 1] = 0;
  REP(i, 0, K/2) {
    Q[K - 1 - 2 * (i + 1)] = Q[K - 1 - 2 * i] + A[K - 1 - 2 * i] - A[K - 1 - 2 * i - 1];
  }
  ll ans = 1e18;
  REP(i, 0, K + 1) {
    if (i % 2 == 0) ans = min(ans, P[i] + Q[i]);
  }
  cout << ans << endl;
  return 0;
}

