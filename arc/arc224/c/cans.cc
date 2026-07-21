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

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    // @InpNbrList(N, M, nbr, dec=1) [hy9hgZHF]
    auto nbr = vector(N, vector(0, int()));
    for (int i = 0; i < M; i++) {
      int u, v; cin >> u >> v; u -= 1; v -= 1;
      nbr[u].emplace_back(v);
      nbr[v].emplace_back(u);
    }
    // @End [hy9hgZHF]
    vector<ll> A(N, -1LL);
    auto dfs = [&](auto rF, ll nd, ll dp) -> void {
      if (A[nd] >= 0) return;
      A[nd] = dp;
      for (ll peer : nbr[nd]) rF(rF, peer, dp + 1);
    };
    dfs(dfs, 0, 0);
    REPOUT(i, 0, N, A[i], " ");
  };

  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

