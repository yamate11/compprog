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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  // @InpVec(N, X) [b3fDJGke]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [b3fDJGke]
  ll p0 = 0;
  for (; p0 < N and X[p0] < 0; p0++);
  if (p0 == N) {
    cout << -X[N - K] << endl;
    return 0;
  }else if (p0 == 0) {
    cout << X[K - 1] << endl;
    return 0;
  }
  ll ans = 1e18;
  if (p0 + K - 1 < N) ans = min(ans, X[p0 + K - 1]);
  if (p0 - K >= 0)    ans = min(ans, -X[p0 - K]);
  REP(i, 1, K) {
    ll j = K - i;
    if (p0 + i - 1 < N and p0 - j >= 0) {
      ll t = 2 * X[p0 + i - 1] + (-X[p0 - j]);
      ans = min(ans, t);
    }
    if (p0 - i >= 0 and p0 + j - 1 < N) {
      ll s = 2 * (-X[p0 - i]) + X[p0 + j - 1];
      ans = min(ans, s);
    }
  }
  cout << ans << endl;

  return 0;
}

