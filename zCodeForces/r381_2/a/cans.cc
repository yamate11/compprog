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
    ll n, a, b, c; cin >> n >> a >> b >> c;
    if (n % 4 == 0) return 0;
    if (n % 4 == 1) return min(a * 3, min(a + b, c));
    if (n % 4 == 2) return min(a * 2, min(b, c * 2));
    if (n % 4 == 3) return min(a, min(b + c, c * 3));
    assert(0);
  };
  cout << solve() << endl;

  return 0;
}

