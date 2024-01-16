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
  // @InpGrid(1LL << N, N, C) [UdMRVAoU]
  auto C = vector(1LL << N, vector(N, ll()));
  for (int i = 0; i < 1LL << N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; C[i][j] = v; }
  // @End [UdMRVAoU]
  
  vector tbl(N, vector<ll>(1LL << N));
  REP(k, 1, N) {
    REP(m, 0, 1LL << (N - k - 1)) {
      ll p = m * (1LL << (k + 1));
      ll q = p + (1LL << k);
      ll a = 0;
      REP(j, q, q + (1LL << k)) a = max(a, tbl[k - 1][j] + C[j][k - 1]);
      ll b = 0;
      REP(j, p, p + (1LL << k)) b = max(b, tbl[k - 1][j] + C[j][k - 1]);
      REP(i, 0, 1LL << k) {
        tbl[k][p + i] = tbl[k - 1][p + i] + a;
        tbl[k][q + i] = tbl[k - 1][q + i] + b;
      }
    }
  }
  ll ans = 0;
  REP(i, 0, 1LL << N) ans = max(ans, tbl[N - 1][i] + C[i][N - 1]);
  cout << ans << endl;
  return 0;
}

