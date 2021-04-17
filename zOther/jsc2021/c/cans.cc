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

  ll A, B; cin >> A >> B;
  ll ans = 1;
  for (ll x = 1; x <= B; x++) {
    ll z = (B / x) * x;
    ll y = z - x;
    if (A <= y) ans = x;
  }
  cout << ans << endl;

  return 0;
}

