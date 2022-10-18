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

  ll N; cin >> N;
  string S; cin >> S;
  // @InpVec(N + 1, A) [wmFAPpsA]
  auto A = vector(N + 1, ll());
  for (int i = 0; i < N + 1; i++) { ll v; cin >> v; A[i] = v; }
  // @End [wmFAPpsA]
  ll K = 1e10;
  REP(i, 0, N) K = min(K, abs(A[i + 1] - A[i]));
  vector B(K, vector(N + 1, 0LL));
  ll r = A[0] % K;
  REP(k, 0, K) B[k][0] = k < r ? (A[0] / K + 1) : (A[0] / K);
  REP(i, 1, N + 1) {
    ll d = A[i] - A[i-1];
    REP(k, 0, K) B[k][i] = B[k][i - 1];
    if (d > 0) {
      REP(k, r, K) B[k][i]++;
      d -= K - r;
      REP(k, 0, K) B[k][i] += d / K;
      r = d % K;
      REP(k, 0, r) B[k][i]++;
    }else {
      d = -d;
      REP(k, 0, r) B[k][i]--;
      d -= r;
      REP(k, 0, K) B[k][i] -= d / K;
      if (d % K == 0) {
        r = 0;
      }else {
        r = K - (d % K);
        REP(k, r, K) B[k][i]--;
      }
    }
  }
  cout << K << "\n";
  /*
  REP(k, 0, K) {
    REP(i, 0, N + 1) cout << B[k][i] << " ";
    cout << "\n";
  }
  */
  REP(k, 0, K) REPOUT(i, 0, N + 1, B[k][i], "\n");

  return 0;
}

