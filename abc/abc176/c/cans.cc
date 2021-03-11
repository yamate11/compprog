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
  ll cur = 0;
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    if (a < cur) {
      ans += cur - a;
    }else {
      cur = a;
    }
  }
  cout << ans << endl;
  return 0;

}

