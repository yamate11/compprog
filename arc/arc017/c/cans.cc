#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X; cin >> N >> X;
  vector<ll> w(N);
  for (ll i = 0; i < N; i++) cin >> w.at(i);
  map<ll, ll> mp;
  ll M = N / 2;
  for (ll x = 0; x < (1LL << M); x++) {
    ll tot = 0;
    for (ll i = 0; i < M; i++) if ((x >> i) & 1LL) tot += w.at(i);
    mp[tot]++;
  }
  ll K = N - M;
  ll ans = 0;
  for (ll x = 0; x < (1LL << K); x++) {
    ll y = x << M;
    ll tot = 0;
    for (ll i = M; i < N; i++) if ((y >> i) & 1LL) tot += w.at(i);
    ll r = X - tot;
    if (r < 0 || mp.find(r) == mp.end()) continue;
    ans += mp[r];
  }
  cout << ans << endl;

  return 0;
}

