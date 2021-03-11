#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll s, d; cin >> s >> d;
    for (ll x = s; true; x += d) {
      if (x <= ans) continue;
      ans = x;
      break;
    }
  }
  cout << ans << endl;

  return 0;
}

