#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll big = 1e10;
  ll N, M, K; cin >> N >> M >> K;
  using sta = pair<ll, ll>;
  vector<vector<sta>> nbr(N);
  vector<ll> vecA(M), vecB(M), vecL(M);
  for (ll i = 0; i < M; i++) {
    ll a, b, l; cin >> a >> b >> l; a--; b--;
    nbr[a].emplace_back(l, b);
    nbr[b].emplace_back(l, a);
    vecA[i] = a;
    vecB[i] = b;
    vecL[i] = l;
  }
  vector<ll> dist(N, big);
  using stb = pair<ll, ll>;
  priority_queue<stb, vector<stb>, greater<stb>> pque;
  for (ll i = 0; i < K; i++) {
    ll s; cin >> s; s--;
    dist[s] = 0;
    pque.emplace(0, s);
  }
  while (!pque.empty()) {
    auto [d, a] = pque.top(); pque.pop();
    if (dist[a] < d) continue;
    for (auto [len, nxt] : nbr[a]) {
      ll newD = d + len;
      if (dist[nxt] <= newD) continue;
      dist[nxt] = newD;
      pque.emplace(newD, nxt);
    }
  }
  ll ans = 0;
  for (ll i = 0; i < N; i++) ans = max(ans, dist[i]);
  for (ll i = 0; i < M; i++) {
    ll a = vecA[i], b = vecB[i], l = vecL[i];
    if (dist[a] > dist[b]) swap(a, b);
    if (dist[b] == dist[a] + l) continue;
    l -= dist[b] - dist[a];
    ll dd = dist[b] + (l + 1) / 2;
    ans = max(ans, dd);
  }
  cout << ans << endl;
  

  return 0;
}

