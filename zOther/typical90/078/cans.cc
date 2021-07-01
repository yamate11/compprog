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
  vector<vector<ll>> nbr(N + 1);
  for (ll i = 0; i < M; i++) {
    ll a, b; cin >> a >> b;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  ll ans = 0;
  for (ll i = 1; i <= N; i++) {
    ll cnt = 0;
    for (ll x : nbr[i]) {
      if (x < i) cnt++;
    }
    if (cnt == 1) ans++;
  }
  cout << ans << endl;

  return 0;
}

