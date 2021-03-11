#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
    if (r1 == r2 && c1 == c2) return 0;
    if (r1 + c1 == r2 + c2) return 1;
    if (r1 - c1 == r2 - c2) return 1;
    for (ll i = -3; i <= 3; i++) {
      for (ll j = -3; j <= 3; j++) {
	if (abs(i) + abs(j) > 3) continue;
	if (r1 + i == r2 && c1 + j == c2) return 1;
      }
    }
    if ((r1 + c1) % 2 == (r2 + c2) % 2) return 2;
    for (ll i = -3; i <= 3; i++) {
      for (ll j = -3; j <= 3; j++) {
	if (abs(i) + abs(j) > 3) continue;
	if (r1 + i + c1 + j == r2 + c2) return 2;
	if (r1 + i - (c1 + j) == r2 - c2) return 2;
      }
    }
    return 3;
  };
  cout << solve() << endl;

  return 0;
}

