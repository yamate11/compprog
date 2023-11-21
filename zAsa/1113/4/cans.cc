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
  // @InpVec(N, A) [CsQ27RxP]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [CsQ27RxP]

  REP(i, K + 1, N) A[i] = max(A[i - 1], A[i]);
  ll big = 1e18;
  ll ans = big;
  REP(i, 0, K) {
    ll t = upper_bound(A.begin() + K, A.end(), A[i]) - A.begin();
    if (t == N) continue;
    t -= K;
    ll s = K - 1 - i;
    ans = min(ans, t + s + 1);
  }
  if (ans == big) ans = -1;
  cout << ans << endl;
  return 0;
}

