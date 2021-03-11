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

  ll L; cin >> L;
  ll ans = 1;
  vector<ll> rem(12);
  for (ll j = 2; j <= 11; j++) rem[j] = j;
  for (ll i = 0; i < 11; i++) {
    ll x = L - 1 - i;
    for (ll j = 2; j <= 11; j++) {
      if (rem[j] == 1) continue;
      ll g = gcd(rem[j], x);
      x /= g;
      rem[j] /= g;
    }
    ans *= x;
  }
  cout << ans << endl;

  return 0;
}

