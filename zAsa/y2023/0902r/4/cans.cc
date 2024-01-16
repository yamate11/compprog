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
  // @InpNbrList(N, M, nbr, dec=1, read=C) [re2ZLALe]
  struct nbr_t {
    int nd;
    ll C;
    nbr_t() {}
    nbr_t(int nd_, ll C_) : nd(nd_), C(C_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C; C--;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
  }
  // @End [re2ZLALe]
  
  auto ans = vector(N, 0LL);
  auto visited = vector(N, false);
  auto dfs = [&](auto rF, ll nd, ll pt, ll lab) -> void {
    if (visited[nd]) return;
    visited[nd] = true;
    if (nd == 0) ans[nd] = 0;
    else if (pt >= 0 and ans[pt] == lab) ans[nd] = (lab + 1) % N;
    else ans[nd] = lab;
    for (auto peer : nbr[nd]) {
      rF(rF, peer.nd, nd, peer.C);
    }
  };
  dfs(dfs, 0, -1, -1);

  REPOUT(i, 0, N, ans[i] + 1, "\n");

  return 0;
}

