#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  const ll lim = 1e5;
  ll n; cin >> n;
  vector<bool> vec(2 * lim + 1);
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    vec[a + lim] = true;
  }
  ll ans = 0;
  for (ll i = 0; i < 2 * lim + 1; i++) if (vec[i] && i != lim) ans++;
  cout << ans << endl;


  return 0;
}

