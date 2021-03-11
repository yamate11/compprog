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
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  ll ans = 0;
  for (ll l = 0; l < N; l++) {
    ll x = A[l];
    for (ll r = l; r < N; r++) {
      x = min(x, A[r]);
      ans = max(ans, x * (r - l + 1));
    }
  }
  cout << ans << endl;

  return 0;
}

