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
  // @InpNbrList(N, M, nbr, dec=1) [oi71iuam]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [oi71iuam]

  auto pout = [&](ll a, ll b) -> void {
    cout << a + 1 << " " << b + 1 << "\n";
  };

  {
    auto visited = vector(N, false);
    auto dfs = [&](auto rF, ll nd, ll pt) -> void {
      if (visited[nd]) return;
      visited[nd] = true;
      if (pt >= 0) pout(pt, nd);
      for (ll cld : nbr[nd]) rF(rF, cld, nd);
    };
    dfs(dfs, 0, -1);
  }

  {
    auto seen = vector(N, false);
    queue<ll> que;
    seen[0] = true;
    que.push(0);
    while (not que.empty()) {
      ll nd = que.front(); que.pop();
      for (ll cld : nbr[nd]) {
        if (seen[cld]) continue;
        seen[cld] = true;
        pout(nd, cld);
        que.push(cld);
      }
    }
  }
    
  return 0;
}

