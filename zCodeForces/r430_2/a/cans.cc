#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll l, r, x, y, k; cin >> l >> r >> x >> y >> k;
  if (r < x * k || y * k < l) {
    cout << "NO\n";
  }else {
    ll t = l / k;
    if (k * t < l && r < k * (t + 1)) {
      cout << "NO\n";
    }else {
      cout << "YES\n";
    }
  }

  return 0;
}

