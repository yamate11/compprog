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
    ll a, b, c, n; cin >> a >> b >> c >> n;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    ll x = c - a + c - b;
    n -= x;
    return (n >= 0 && n % 3 == 0);
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "YES\n" : "NO\n");

  return 0;
}

