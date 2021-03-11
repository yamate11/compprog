#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  ll maxplus = LLONG_MIN, maxminus = LLONG_MIN;
  ll minplus = LLONG_MAX, minminus = LLONG_MAX;
  for (ll i = 0; i < N; i++) {
    ll x, y; cin >> x >> y;
    maxplus = max(maxplus, x + y);
    minplus = min(minplus, x + y);
    maxminus = max(maxminus, x - y);
    minminus = min(minminus, x - y);
  }
  ll ans = max(maxplus - minplus, maxminus - minminus);
  cout << ans << endl;

  return 0;
}

