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
  vector<vector<sta>> fwd(N);
  using stb = pair<ll, ll>;
  vector<stb> edges(M);
  for (ll i = 0; i < M; i++) {
    ll s, t; cin >> s >> t; s--; t--;
    edges[i] = {s, t};
    fwd[s].emplace_back(t, i);
  }

  vector<ll> ans(M);

  auto func = [&](ll j0) -> pair<vector<ll>, vector<ll>> {
    queue<ll> que;
    que.emplace(0);
    vector<ll> dist(N, -1);
    vector<ll> pedge(N);
    dist[0] = 0;
    pedge[0] = -1;
    while (! que.empty()) {
      ll x = que.front(); que.pop();
      for (auto [y, j] : fwd[x]) {
        if (j == j0) continue;
        if (dist[y] >= 0) continue;
        dist[y] = dist[x] + 1;
        pedge[y] = j;
        que.push(y);
      }
    }
    return {move(dist), move(pedge)};
  };
  
  auto [dist_init, pedge_init] = func(-1);
  if (dist_init[N-1] >= 0) {
    for (ll i = 0; i < M; i++) ans[i] = dist_init[N-1];
    for (ll x = N-1; x > 0; ) {
      ll j = pedge_init[x];
      auto [dist, dummy1] = func(j);
      ans[j] = dist[N-1];
      auto [y, dummy2] = edges[j];
      x = y;
    }
  }else {
    for (ll i = 0; i < M; i++) ans[i] = -1;
  }

  for (ll i = 0; i < M; i++) cout << ans[i] << "\n";
  return 0;
}

