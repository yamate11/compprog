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

  ll N, C, T, K; cin >> N >> C >> T >> K;
  // @InpVec(N, A) [yvq0OkmM]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [yvq0OkmM]
  vector<ll> B(N + 1);
  REP(i, 0, N) B[i + 1] = B[i] + A[i];
  ll ans = 0;
  ll j = 0;
  REP(i, 0, N) {
    if (j < i) j = i;
    for (; j <= N and C * (B[j] - B[i]) <= T; j++);
    ans += max(0LL, j - i - K);
  }
  cout << ans << "\n";

  return 0;
}

