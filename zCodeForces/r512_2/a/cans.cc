#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, d; cin >> n >> d;
  ll m; cin >> m;
  vector<ll> X(m), Y(m);
  for (ll i = 0; i < m; i++) cin >> X[i] >> Y[i];
  for (ll i = 0; i < m; i++) {
    ll p = X[i] + Y[i];
    ll q = X[i] - Y[i];
    if (d <= p && p <= 2*n - d && -d <= q && q <= d) {
      cout << "YES\n";
    }else {
      cout << "NO\n";
    }
  }


  return 0;
}

