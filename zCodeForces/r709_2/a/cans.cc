#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll a, b; cin >> a >> b;
    return a * b;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << "\n";

  return 0;
}

