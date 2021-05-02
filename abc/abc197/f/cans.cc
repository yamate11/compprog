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
  auto onelen = vector(N + 1, vector(N + 1, false));
  auto nbr = vector(N + 1, vector(26, vector<ll>()));
  for (ll i = 0; i < M; i++) {
    ll a, b; char c; cin >> a >> b >> c;
    nbr[a][c - 'a'].push_back(b);
    nbr[b][c - 'a'].push_back(a);
    onelen[a][b] = true;
    onelen[b][a] = true;
  }
  using sta = pair<ll, ll>;
  auto edge = vector(N+1, vector(N+1, vector<sta>()));
  for (ll i = 1; i <= N; i++) {
    for (ll j = i + 1; j <= N; j++) {
      for (ll c = 0; c < 26; c++) {
        for (ll x : nbr[i][c]) {
          for (ll y : nbr[j][c]) {
            edge[i][j].emplace_back(x, y);
          }
        }
      }
    }
  }
  const ll big = 1e10;
  ll ans = big;
  auto dist = vector(N+1, vector(N+1, big));
  using stb = tuple<ll, ll>;
  queue<stb> que;
  que.emplace(1, N);
  dist[1][N] = 0;
  while (!que.empty()) {
    auto [x, y] = que.front(); que.pop();
    ll d = dist[x][y];
    if (d >= ans) break;
    if (onelen[x][y]) {
      ans = d + 1;
      break;
    }
    for (auto [p, q] : edge[x][y]) {
      if (p == q) {
        ans = min(ans, d + 2);
      }else {
        if (p > q) swap(p, q);
        if (d + 2 < dist[p][q]) {
          dist[p][q] = d + 2;
          que.emplace(p, q);
        }
      }
    }
  }
  if (ans == big) {
    cout << -1 << endl;
  }else {
    cout << ans << endl;
  }

  return 0;
}

