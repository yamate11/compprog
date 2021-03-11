#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> x(3);
  for (ll i = 0; i < 3; i++) cin >> x[i];
  sort(x.begin(), x.end());
  ll a = x[2];
  ll b = x[0] + x[1];
  ll ans;
  if (a < b) ans = 0;
  else ans = a - b + 1;
  cout << ans << endl;

  return 0;
}

