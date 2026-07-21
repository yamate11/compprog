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
  // @InpNbrList(N, M, fwd, dir=True, dec=1, bwd=bwd) [pbbiro5F]
  auto fwd = vector(N, vector(0, int()));
  auto bwd = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    fwd[u].emplace_back(v);
    bwd[v].emplace_back(u);
  }
  // @End [pbbiro5F]

  vector<bool> rble(N, false);
  ll Q; cin >> Q;
  REP(_q, 0, Q) {
    ll tp; cin >> tp;
    if (tp == 1) {
      ll v; cin >> v; v--;
      auto dfs = [&](auto rF, ll nd) -> void {
        if (rble[nd]) return;
        rble[nd] = true;
        for (ll peer : bwd[nd]) rF(rF, peer);
      };
      dfs(dfs, v);
    }else if (tp == 2) {
      ll v; cin >> v; v--;
      cout << (rble[v] ? "Yes\n" : "No\n");
    }
  }

  return 0;
}

