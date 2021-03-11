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
  vector<vector<ll>> A(H, vector(W, 0LL));
  ll vmin = 1e18;
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      cin >> A[i][j];
      vmin = min(vmin, A[i][j]);
    }
  }
  ll ans = 0;
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      ans += A[i][j] - vmin;
    }
  }
  cout << ans << endl;

  return 0;
}

