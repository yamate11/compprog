#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    sum += a;
  }
  for (ll t = 0; true; t++) {
    if (2 * sum >= (n + t) * (2 * k - 1)) {
      cout << t << endl;
      return 0;
    }
    sum += k;
  }


  return 0;
}

