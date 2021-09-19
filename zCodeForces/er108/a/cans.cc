#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    ll r, b, d; cin >> r >> b >> d;
    if (r > b) swap(r, b);
    return (1 + d) * r >= b;

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "YES" : "NO") << "\n";

  return 0;
}

