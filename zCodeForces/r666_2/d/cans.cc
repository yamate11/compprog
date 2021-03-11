#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll n; cin >> n;
    vector<ll> a(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
      cin >> a[i];
      sum += a[i];
    }
    sort(a.begin(), a.end(), greater<ll>());
    if (sum % 2 == 1) {
      cout << "T\n";
      return;
    }
    if (a[0] > sum / 2) {
      cout << "T\n";
      return;
    }
    cout << "HL\n";
    return;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

