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
  // @InpGrid(N, M, A) [yhPBbM7j]
  auto A = vector(N, vector(M, ll()));
  for (int i = 0; i < N; i++) for (int j = 0; j < M; j++) { ll v; cin >> v; A[i][j] = v; }
  // @End [yhPBbM7j]

  vector<bitset<2000>> vec(N);
  REP(i, 0, M) {
    vector<bitset<2000>> perNum(1000);
    REP(j, 0, N) perNum[A[j][i]][j] = true;
    REP(j, 0, N) vec[j] ^= perNum[A[j][i]];
  }
  ll ans = 0;
  REP(i, 0, N) REP(j, i + 1, N) if (vec[i][j]) ans++;
  cout << ans << endl;
  return 0;
}

