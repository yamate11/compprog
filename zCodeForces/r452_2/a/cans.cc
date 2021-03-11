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
  ll cnt1 = 0, cnt2 = 0;
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    if (a == 1) cnt1++;
    else if (a == 2) cnt2++;
    else assert(0);
  }
  ll ans = 0;
  if (cnt2 < cnt1) {
    ans += cnt2;
    cnt1 -= cnt2;
    ans += cnt1 / 3;
  }else {
    ans = cnt1;
  }
  cout << ans << endl;

  return 0;
}

