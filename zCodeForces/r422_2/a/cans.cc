#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll a, b; cin >> a >> b;
  ll c = min(a, b);
  ll ans = 1;
  for (ll t = 1; t <= c; t++) {
    ans *= t;
  }
  cout << ans << endl;

  return 0;
}

