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
  // @InpVec(N, F) [qs56ehZZ]
  auto F = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; F[i] = v; }
  // @End [qs56ehZZ]

  ll big = 1LL << 60;
  vector<ll> A(N + 1);
  A[0] = -big;
  REP(i, 0, N) A[i + 1] = max(A[i], F[i]);
  vector<ll> B(N + 1);
  B[N] = -big;
  REPrev(i, N - 1, 0) B[i] = max(B[i + 1], F[i]);
  vector<ll> C(N + 1);
  C[0] = 0;
  REP(i, 0, N) C[i + 1] = C[i] + F[i];
  double ans = big;
  REP(i, 0, N - K + 1) {
    double a = max((double)A[i], max((double)B[i + K], (double)(C[i + K] - C[i]) / K));
    ans = min(ans, a);
  }
  cout << ans << endl;

  return 0;
}

