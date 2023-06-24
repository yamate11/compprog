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

  ll N; cin >> N;
  // @InpVec(N, A) [rVL9oVqc]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [rVL9oVqc]

  vector<ll> S(N + 1); REP(i, 0, N) S[i + 1] = S[i] + A[i];
  vector<ll> T(N + 1); REP(i, 0, N) T[i + 1] = T[i] + S[i + 1];
  vector<ll> V(N);
  V[0] = A[0];
  REP(i, 1, N) V[i] = max(A[i], V[i - 1]);

  REP(k, 0, N) {
    cout << T[k + 1] + (k + 1) * V[k] << "\n";
  }
  return 0;


  // ll sum = A[0] * 2;
  // ll vm = A[0] * 2;
  // cout << sum << "\n";
  // REP(k, 1, N) {
  //   if (vm >= A[k]) {
  //     sum = (sum + A[k]) + k * vm;
  //     vm = 2 * vm;
  //   }else {
  //     sum = T[k] + S[k + 1] + k * A[k];
  //     vm = S[k + 1] + A[k];
  //   }
  //   cout << sum << "\n";
  // }

  return 0;
}

