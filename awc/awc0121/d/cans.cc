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

  ll N, D; cin >> N >> D;
  // @InpVec(N, A) [9S1DkhQ1]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [9S1DkhQ1]
  // @InpVec(N, C) [W02pZjGP]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [W02pZjGP]

  auto B = A;
  REPrev(i, N - 2, 0) {
    if (B[i] < B[i + 1] - D) {
      B[i] = B[i + 1] - D;
    }
  }
  REP(i, 1, N) {
    if (B[i] < B[i - 1] - D) {
      B[i] = B[i - 1] - D;
    }
  }
  ll ans = 0;
  REP(i, 0, N) ans += C[i] * (B[i] - A[i]);
  cout << ans << endl;

  return 0;
}

