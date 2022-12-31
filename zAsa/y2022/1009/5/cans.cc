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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [58PCTBnK]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [58PCTBnK]
  auto tbl_init = vector(N, vector(1LL << N, 0LL));
  auto tbl = tbl_init;
  tbl[0][1] = 1;
  REP(i, 1, N) {
    auto prev = tbl_init; swap(prev, tbl);
    REP(j, 0, N) {
      REP(x, 0, 1LL << N) if (prev[j][x] > 0) {
        for (ll k : nbr[j]) if (not (x >> k & 1)) tbl[k][x | (1LL << k)] += prev[j][x];
      }
    }
  }
  ll ans = 0;
  REP(i, 0, N) REP(x, 0, 1LL << N) ans += tbl[i][x];
  cout << ans << endl;
  return 0;
}

