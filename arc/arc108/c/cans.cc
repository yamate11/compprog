#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  using sta = pair<ll, ll>;
  vector<vector<sta>> nbr(N);
  for (ll i = 0; i < M; i++) {
    ll u, v, c; cin >> u >> v >> c; u--; v--;
    nbr[u].emplace_back(v, c);
    nbr[v].emplace_back(u, c);
  }
  vector<ll> ans(N);
  vector<bool> visited(N);
  vector<bool> used(N + 1);
  auto dfs = [&](auto rF, ll n, ll col) -> void {
    if (visited[n]) return;
    ans[n] = col;
    if (col >= 0) used[col] = true;
    visited[n] = true;
    for (auto [m, c] : nbr[n]) {
      ll newCol = c == col ? -1 : c;
      rF(rF, m, newCol);
    }
  };
  dfs(dfs, 0, -1);

  ll col = 1;
  for ( ; col <= N; col++) {
    if (!used[col]) break;
  }
  for (ll i = 0; i < N; i++) {
    cout << (ans[i] >= 0 ? ans[i] : col) << "\n";
  }

  return 0;
}

