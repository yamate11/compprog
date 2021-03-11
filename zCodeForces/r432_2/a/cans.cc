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
    ll n, k, t; cin >> n >> k >> t;
    if (t <= k) return t;
    if (t <= n) return k;
    return n + k - t;
  };
  cout << solve() << endl;

  return 0;
}

