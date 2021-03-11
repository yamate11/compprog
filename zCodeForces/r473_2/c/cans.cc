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
  if (n <= 5) {
    cout << "-1\n";
  }else {
    ll t = n / 2 + 1;
    for (ll i = 2; i <= t; i++) cout << "1 " << i << "\n";
    for (ll i = t + 1; i <= n; i++) cout << "2 " << i << "\n";
  }
  for (ll i = 1; i <= n - 1; i++) cout << i << " " << i + 1 << "\n";
  return 0;
}

