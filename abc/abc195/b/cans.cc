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

  ll a, b, w; cin >> a >> b >> w;
  w *= 1000;
  ll vmin = -1;
  ll vmax = -1;
  for (ll x = 1; x <= w; x++) {
    if (x * a <= w && b * x >= w) {
      if (vmin < 0) vmin = x;
      vmax = x;
    }
  }
  if (vmin < 0) {
    cout << "UNSATISFIABLE\n";
  }else {
    cout << vmin << " " << vmax << "\n";
  }
    

  return 0;
}

