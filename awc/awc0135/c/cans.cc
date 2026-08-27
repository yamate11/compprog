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

  ll N, M; cin >> N >> M;
  // @InpGrid(N, M, A) [8a3KXIL9]
  auto A = vector(N, vector(M, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [8a3KXIL9]

  vector B(N, vector(M, 0LL));
  REPrev(i, N - 1, 0) REPrev(j, M - 1, 0) {
    if (i == N - 1 and j == M - 1) {
      B[i][j] = A[i][j];
    }else if (i == N - 1) {
      B[i][j] = A[i][j] + B[i][j + 1];
    }else if (j == M - 1) {
      B[i][j] = A[i][j] + B[i + 1][j];
    }else {
      B[i][j] = A[i][j] + max(B[i + 1][j], B[i][j + 1]);
    }
  }
  cout << B[0][0] << "\n";

  return 0;
}

