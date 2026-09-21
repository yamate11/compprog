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

  ll N, K; cin >> N >> K;
  // @InpVec(N, A) [HG7pKtZP]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [HG7pKtZP]
  // @InpVec(K, B, dec=1) [tnH5D7ZP]
  auto B = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; B[i] = v; }
  // @End [tnH5D7ZP]
  // @InpVec(K, C) [gYCtGN9s]
  auto C = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; C[i] = v; }
  // @End [gYCtGN9s]
  REP(i, 0, K) A[B[i]] = C[i];
  ll ans = 0;
  REP(i, 0, N - 1) ans += abs(A[i + 1] - A[i]);
  cout << ans << "\n";

  return 0;
}

