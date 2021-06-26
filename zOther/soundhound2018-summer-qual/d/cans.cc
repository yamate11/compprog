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

  using sta = pair<ll, ll>;

  ll N, M, S, T; cin >> N >> M >> S >> T;
  vector<vector<sta>> nbrA(N + 1), nbrB(N + 1);
  for (ll i = 0; i < M; i++) {
    ll u, v, a, b; cin >> u >> v >> a >> b;
    nbrA[u].emplace_back(v, a);
    nbrB[u].emplace_back(v, b);
    nbrA[v].emplace_back(u, a);
    nbrB[v].emplace_back(u, b);
  }
  auto dijkstra = [&](const auto& nbr, ll st) -> vector<ll> {
    vector<ll> dist(N + 1, LLONG_MAX);
    priority_queue<sta, vector<sta>, greater<sta>> pque;
    dist[st] = 0;
    pque.emplace(0, st);
    while (!pque.empty()) {
      auto [d, x] = pque.top(); pque.pop();
      if (dist[x] < d) continue;
      for (auto [y, e] : nbr[x]) {
        ll dNew = d + e;
        if (dist[y] > dNew) {
          dist[y] = dNew;
          pque.emplace(dNew, y);
        }
      }
    }
    return dist;
  };    
  auto distA = dijkstra(nbrA, S);
  auto distB = dijkstra(nbrB, T);
  vector<sta> cost;
  for (ll i = 1; i <= N; i++) {
    cost.emplace_back(distA[i] + distB[i], i);
  }
  sort(cost.begin(), cost.end());
  const ll orig = 1'000'000'000'000'000;
  ll idx = 0;
  for (ll i = 0; i < N; i++) {
    while (true) {
      auto [c, e] = cost[idx];
      if (e > i) {
        cout << orig - c << "\n";
        break;
      }
      idx++;
    }
  }
  return 0;
}

