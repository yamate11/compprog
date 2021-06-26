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

  ll N; cin >> N;
  // vector<ll> A(N);
  map<ll, ll> mp;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    mp[a]++;
  }
  ll cnt = 0;
  for (auto [a, n] : mp) {
    cnt += n * (n - 1) / 2;
  }
  ll ans = N * (N - 1) / 2 - cnt;
  cout << ans << endl;

  return 0;
}

