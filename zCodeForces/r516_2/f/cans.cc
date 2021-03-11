#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, l, r, k; cin >> n >> l >> r >> k;
  ll m = (n + r + 1 - l) % n;
  if ((k - m) / n < ll(1e7)) {
  }else {
    for (ll beta = 0; beta <= m; beta++) {
      k - m - beta
    }
  }

  return 0;
}

