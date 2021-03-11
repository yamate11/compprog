#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> a(14);
  for (ll i = 0; i < 14; i++) cin >> a[i];
  ll ans = 0;
  for (ll i = 0; i < 14; i++) {
    if (a[i] == 0) continue;
    auto b(a);
    ll p = b[i] / 14;
    ll q = b[i] % 14;
    b[i] = 0;
    for (ll j = 1; j <= q; j++) b[(i + j) % 14]++;
    ll cnt = 0;
    for (ll j = 0; j < 14; j++) {
      if ((b[j] + p) % 2 == 0) cnt += b[j] + p;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}

