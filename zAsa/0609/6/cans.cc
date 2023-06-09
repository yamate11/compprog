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
  // @InpNbrList(N, M, nbr, dec=1) [AYQBDrg4]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [AYQBDrg4]
  vector<bool> visited(N);
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    if (visited[nd]) return;
    visited[nd] = true;
    if (pt >= 0) cout << pt + 1 << " " << nd + 1 << "\n";
    for (ll cld : nbr[nd]) rF(rF, cld, nd);
  };
  dfs(dfs, 0, -1);
  vector<bool> taken(N);
  queue<ll> que;
  que.push(0);
  taken[0] = true;
  while (not que.empty()) {
    ll nd = que.front(); que.pop();
    for (ll cld : nbr[nd]) {
      if (not taken[cld]) {
        taken[cld] = true;
        que.push(cld);
        cout << nd + 1 << " " << cld + 1 << "\n";
      }
    }
  }

  return 0;
}

