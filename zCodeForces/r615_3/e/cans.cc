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
  vector<vector<ll>> A(N, vector(M, 0LL));
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < M; j++) {
      ll x; cin >> x; x--;
      A[i][j] = x;
    }
  }
  auto getja = [&](ll j) -> ll {
    vector<ll> cost(N);
    for (ll i = 0; i < N; i++) cost[i] = i + N;
    ll ret = N;
    for (ll i = 0; i < N; i++) {
      ll p = (A[i][j] - j) / M;
      ll q = (A[i][j] - j) % M;
      if (q == 0 && 0 <= p && p < N) {
	ll idx = (N + i - p) % N;
	cost[idx]--;
	ret = min(ret, cost[idx]);
      }
    }
    return ret;
  };

  ll ans = 0;
  for (ll j = 0; j < M; j++) ans += getja(j);
  cout << ans << endl;

  return 0;
}

