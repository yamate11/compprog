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
    ll a; cin >> a;
    if (a == 0) {
      cout << 1 << "\n";
      return;
    }

    ll x = __builtin_popcountll(a);
    cout << (1LL << x) << "\n";

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

