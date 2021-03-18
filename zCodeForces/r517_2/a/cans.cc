#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll w, h, k; cin >> w >> h >> k;
  ll ans = 0;
  for (ll i = 0; i < k; i++) {
    ll sz = 2 * (w + h - 2);
    ans += sz;
    w -= 4;
    h -= 4;
  }
  cout << ans << endl;

  return 0;
}

