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
  vector<bool> v(1000);
  ll ans = 0;
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    if (a > 0 && !v[a]) {
      ans++;
      v[a] = true;
    }
  }
  cout << ans << endl;

  return 0;
}

