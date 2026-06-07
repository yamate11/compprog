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
    ll n, m; cin >> n >> m;
    vector A(n, 0LL);
    ll s = 0;
    for (ll i = 0; i < n; i++) {
      cin >> A[i];
      s += A[i];
    }
    cout << min(s, m) << "\n";
    
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

