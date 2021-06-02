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
  map<ll, ll> mp;
  ll sum = 0;
  mp[0] = 1;
  for (ll i = 0; i < N; i++) {
    ll a; cin >> a;
    if (i % 2 == 0) sum += a;
    else sum -= a;
    mp[sum]++;
  }
  ll ans = 0;
  for (auto [_, k] : mp) {
    ans += k * (k - 1) / 2;
  }
  cout << ans << endl;

  return 0;
}

