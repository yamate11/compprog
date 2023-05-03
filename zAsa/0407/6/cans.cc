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

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [gDzUngbA]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [gDzUngbA]

  vector tbl(1LL << N, vector<ll>(N, 99LL));
  tbl[0][0] = 0;
  queue<pll> que;
  REP(i, 0, N) {
    que.emplace(1LL << i, i);
    tbl[1LL << i][i] = 1;
  }
  while (not que.empty()) {
    auto [x, i] = que.front(); que.pop();
    for (ll j : nbr[i]) {
      ll newx = x ^ (1LL << j);
      if (tbl[newx][j] > tbl[x][i] + 1) {
        tbl[newx][j] = tbl[x][i] + 1;
        que.emplace(newx, j);
      }
    }
  }
  ll ans = 0;
  REP(x, 0, 1LL << N) {
    ans += *min_element(ALL(tbl[x]));
  }
  cout << ans << endl;

  return 0;
}

