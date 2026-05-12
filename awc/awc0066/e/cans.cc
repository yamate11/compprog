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

  ll N, M, S, T; cin >> N >> M >> S >> T; S--; T--;
  // @InpVec(N, C) [rZ6oQNFN]
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
  // @End [rZ6oQNFN]
  // @InpNbrList(N, M, nbr, dec=1) [wBuidxG8]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [wBuidxG8]

  vector tbl(1LL << N, vector(N, pll(0, 0)));
  tbl[1LL << S][S] = pll(1, C[S]);
  REP(x, 0, 1LL << N) REP(i, 0, N) {
    auto [num, sat] = tbl[x][i];
    if (num > 0) {
      for (ll p : nbr[i]) {
        if (not (x >> p & 1)) {
          auto& [n_num, n_sat] = tbl[x | (1LL << p)][p];
          n_num += num;
          n_sat += sat + (num * C[p]);
        }
      }
    }
  }
  ll t_num = 0;
  ll t_sat = 0;
  REP(x, 0, 1LL << N) {
    auto [n, s] = tbl[x][T];
    t_num += n;
    t_sat += s;
  }
  cout << (double)t_sat / t_num << endl;

  return 0;
}

