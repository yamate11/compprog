#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M, X; cin >> N >> M >> X;
  vector<ll> H(N);
  for (ll i = 0; i < N; i++) cin >> H[i];
  using sta = pair<ll, ll>;
  vector<vector<sta>> nbr(N);
  for (ll i = 0; i < M; i++) {
    ll a, b, t; cin >> a >> b >> t; a--; b--;
    if (H[a] >= t) nbr[a].emplace_back(b, t);
    if (H[b] >= t) nbr[b].emplace_back(a, t);
  }
  ll big = 1e15;
  vector<ll> dist(N, big);
  dist[0] = 0;
  using stb = pair<ll, ll>;
  priority_queue<stb, vector<stb>, greater<stb>> pque;
  pque.emplace(0, 0);
  while (!pque.empty()) {
    auto [d, n] = pque.top(); pque.pop();
    if (dist[n] < d) continue;
    if (n == N-1) {
      cout << d + H[N-1] - (X - d) << endl;
      return 0;
    }
    for (auto [m, t] : nbr[n]) {
      ll z = X - d - t - H[m];
      ll newD = z > 0 ? d + t + z : d + t;
      if (newD < dist[m]) {
	dist[m] = newD;
	pque.emplace(newD, m);
      }
    }
  }
  cout << -1 << endl;

  return 0;
}

