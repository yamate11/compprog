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
  ll ans = 1LL << 40;
  for (ll x = 0; x < (1LL<<(N-1)); x++) {
    ll y = x | (1LL<<(N-1));
    ll val = 0;
    ll cur = 0;
    for (ll i = 0; i < N; i++) {
      cur |= A[i];
      if ((y >> i) & 1) {
        val ^= cur;
        cur = 0;
      }
    }
    ans = min(ans, val);
  }
  cout << ans << endl;

  return 0;
}

