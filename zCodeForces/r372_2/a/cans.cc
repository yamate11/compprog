#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, c; cin >> n >> c;
  ll cnt = 0;
  ll prev = -1;
  for (ll i = 0; i < n; i++) {
    ll t; cin >> t;
    if (t - prev > c) cnt = 0;
    cnt++;
    prev = t;
  }
  cout << cnt << endl;

  return 0;
}

