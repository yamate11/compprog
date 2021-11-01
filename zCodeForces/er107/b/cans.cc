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
    ll a,b,c; cin >> a >> b >> c;
    ll aa = 1;
    for (ll i = 0; i < a - c; i++) aa *= 10;
    ll bb = 1;
    for (ll i = 0; i < b - c; i++) bb *= 10;
    ll cc = 1;
    for (ll i = 0; i < c - 1; i++) cc *= 10;
    ll p = 1, q = 1;
    for (; p < aa; p *= 2);
    for (; q < bb; q *= 3);
    cout << p * cc << " " << q * cc << "\n";

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

