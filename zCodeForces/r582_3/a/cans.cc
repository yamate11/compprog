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
  ll even = 0;
  ll odd = 0;
  for (ll i = 0; i < n; i++) {
    ll x; cin >> x;
    if (x % 2 == 0) even++;
    else odd++;
  }
  cout << min(even, odd) << endl;


  return 0;
}

