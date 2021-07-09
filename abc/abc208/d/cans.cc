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
  const ll big = 1e10;
  auto dist = vector(N, vector(N, big));
  ll cur = 0;
  for (ll i = 0; i < N; i++) dist[i][i] = 0;
  for (ll i = 0; i < M; i++) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    dist[a][b] = c;
    cur += c;
  }
  ll ans = 0;
  for (ll k = 0; k < N; k++) {
    for (ll i = 0; i < N; i++) {
      for (ll j = 0; j < N; j++) {
        ll d = dist[i][k] + dist[k][j];
        if (d < dist[i][j]) {
          if (dist[i][j] >= big) cur += d;
          else cur -= (dist[i][j] - d);
          dist[i][j] = d;
        }
      }
    }
    ans += cur;
  }
  cout << ans << endl;

  return 0;
}

