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
  // @InpGrid(N, M, A) [YCKxHfEn]
  auto A = vector(N, vector(M, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [YCKxHfEn]

  vector B(N + 1, vector(M, 0LL));
  REP(i, 0, N) REP(j, 0, M) B[i + 1][j] = A[i][j];
  REP(i, 1, N + 1) REP(j, 0, M) B[i][j] += B[i - 1][j];

  ll big = 1LL << 60;
  ll ans = -big;
  REP(i0, 0, N) REP(i1, i0 + 1, N + 1) {
    vector<ll> C(M + 1, 0LL);
    REP(j, 0, M) C[j + 1] = C[j] + (B[i1][j] - B[i0][j]);
    auto D = C;
    REPrev(j, M - 1, 0) D[j] = max(C[j], D[j + 1]);
    ll vmax = -big;
    REP(j, 0, M) {
      vmax = max(vmax, D[j + 1] - C[j]);
    }
    ans = max(ans, vmax);
  }
  cout << ans << endl;
  return 0;
}

