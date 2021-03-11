#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m, p; cin >> n >> m >> p;
  ll u = -1, v = -1;
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    if (u < 0 && a % p != 0) u = i;
  }
  for (ll i = 0; i < m; i++) {
    ll a; cin >> a;
    if (v < 0 && a % p != 0) v = i;
  }
  cout << u + v << endl;

  return 0;
}

