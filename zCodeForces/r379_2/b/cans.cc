#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll k2, k3, k5, k6; cin >> k2 >> k3 >> k5 >> k6;
  ll x = min(k2, min(k5, k6));
  ll y = min(k3, k2 - x);
  cout << 256 * x + 32 * y << endl;


  return 0;
}

