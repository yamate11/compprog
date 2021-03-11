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

  const ll big = 1e16;
  ll N, M; cin >> N >> M;
  using sta = pair<ll, ll>;
  vector<vector<sta>> nxt(N + 1);
  vector<ll> self(N + 1, big);
  for (ll i = 0; i < M; i++) {
    ll a, b, c; cin >> a >> b >> c;
    if (a == b) self[a] = min(self[a], c);
    else        nxt[a].emplace_back(b, c);
  }
  vector<vector<ll>> dist(N + 1, vector<ll>(N + 1, big));
  using stb = pair<ll, ll>;
  for (ll i = 1; i <= N; i++) {
    priority_queue<stb, vector<stb>, greater<stb>> pque;
    dist[i][i] = 0;
    pque.emplace(0, i);
    while (!pque.empty()) {
      auto [t, j] = pque.top(); pque.pop();
      if (t > dist[i][j]) continue;
      for (auto [k, s] : nxt[j]) {
        if (dist[i][k] <= t + s) continue;
        dist[i][k] = t + s;
        pque.emplace(t + s, k);
      }
    }
  }
  for (ll i = 1; i <= N; i++) {
    ll vmin = big;
    for (ll j = 1; j <= N; j++) {
      if (j == i) vmin = min(vmin, self[i]);
      else vmin = min(vmin, dist[i][j] + dist[j][i]);
    }
    if (vmin >= big) cout << -1 << "\n";
    else cout << vmin << "\n";
  }


  return 0;
}

