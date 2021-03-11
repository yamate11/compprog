#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  vector<vector<ll>> nxt(N);
  for (ll i = 0; i < M; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    nxt[v].push_back(u);
  }
  ll K; cin >> K;
  vector<ll> P(K);
  for (ll i = 0; i < K; i++) {
    ll p; cin >> p; p--;
    P[i] = p;
  }
  // ll start = P[0];
  ll goal = P[K-1];

  using sta = tuple<ll, ll, ll>; // (dist, to, from)
  queue<sta> que;
  vector<ll> dist(N, ll(1e6));
  vector<set<ll>> from(N);

  dist[goal] = 0;
  que.emplace(0, goal, goal);
  while (!que.empty()) {
    auto [d, t, f] = que.front(); que.pop();
    if (dist[t] < d) continue;
    ll newD = d + 1;
    for (ll newT : nxt[t]) {
      if (dist[newT] < newD) continue;
      from[newT].insert(t);
      if (dist[newT] == newD) continue;
      dist[newT] = newD;
      que.emplace(newD, newT, t);
    }
  }
  
  ll vmax = 0;
  ll vmin = 0;
  for (ll i = 0; i < K-1; i++) {
    auto theset = from[P[i]];
    auto it = theset.find(P[i+1]);
    if (it == theset.end()) {
      vmax ++;
      vmin ++;
    }else if (theset.size() > 1) {
      vmax ++;
    }
  }
  cout << vmin << " " << vmax << endl;


  return 0;
}

