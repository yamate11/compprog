#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> v(N);
  for (ll i = 0; i < N; i++) {
    cin >> v.at(i);
  }
  ll ans = LLONG_MAX;
  for (ll x = -100; x <= 100; x++) {
    ll sum = 0;
    for (ll i = 0; i < N; i++) {
      ll d = v.at(i) - x;
      sum += d * d;
    }
    ans = min(ans, sum);
  }
  cout << ans << endl;

  return 0;
}

