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
  // @InpVec(N, A, type=string) [YrpjXPAO]
  auto A = vector(N, string());
  for (int i = 0; i < N; i++) { string v; cin >> v; A[i] = v; }
  // @End [YrpjXPAO]
  auto B = A;
  REP(j, 0, N - 1) B[0][j + 1] = A[0][j];
  REP(i, 0, N - 1) B[i + 1][N - 1] = A[i][N - 1];
  REP(j, 1, N) B[N - 1][j - 1] = A[N - 1][j];
  REP(i, 1, N) B[i - 1][0] = A[i][0];
  REP(i, 0, N) cout << B[i] << "\n";

  return 0;
}

