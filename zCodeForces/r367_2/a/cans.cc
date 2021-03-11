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
  ll n; cin >> n;
  double ans = 1e10;
  for (ll i = 0; i < n; i++) {
    ll x, y, v; cin >> x >> y >> v;
    x -= a;
    y -= b;
    double t = sqrt(double(x * x) + y * y) / double(v);
    ans = min(ans, t);
  }
  cout << ans << endl;


  return 0;
}

