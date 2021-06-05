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
  vector<vector<vector<sta>>> nbr(2);
  nbr[0].resize(M);
  nbr[1].resize(N + 1);
  for (ll i = 0; i < M; i++) {
    ll k; cin >> k;
    for (ll j = 0; j < k; j++) {
      ll r; cin >> r;
      nbr[0][i].emplace_back(1, r);
      nbr[1][r].emplace_back(0, i);
    }
  }
  ll big = 1e10;
  vector<vector<ll>> dist(2);
  dist[0].resize(M, big);
  dist[1].resize(N + 1, big);
  using stb = tuple<ll, ll, ll>;
  queue<stb> que;
  dist[1][1] = 0;
  que.emplace(1, 1, 0);
  while (!que.empty()) {
    auto [t, i, d] = que.front(); que.pop();
    for (auto [nt, ni] : nbr[t][i]) {
      ll nd = d + 1;
      if (nd < dist[nt][ni]) {
        dist[nt][ni] = nd;
        que.emplace(nt, ni, nd);
      }
    }
  }
  for (ll i = 1; i <= N; i++) {
    ll d = dist[1][i];
    if (d == big) { cout << -1 << "\n"; }
    else { cout << d / 2 << "\n"; }
  }

  return 0;
}

