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

  ll H, W; cin >> H >> W;
  ll ans;
  if (H == 1) ans = W;
  else if (W == 1) ans = H;
  else ans = ((H + 1) / 2) * ((W + 1) / 2);
  cout << ans << endl;

  return 0;
}

