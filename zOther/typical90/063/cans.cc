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
  vector<vector<ll>> P(H, vector<ll>(W));
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) cin >> P[i][j];
  }
  ll ans = 0;
  for (ll x = 1; x < (1LL << H); x++) {
    ll cmax = 0;
    vector<ll> rec(H * W + 1);
    for (ll j = 0; j < W; j++) {
      ll val = -1;
      for (ll i = 0; i < H; i++) {
        if (!((x >> i) & 1)) continue;
        if (val < 0) {
          val = P[i][j];
        }else if (P[i][j] != val) {
          val = -2;
          break;
        }
      }
      if (val > 0) {
        rec[val]++;
        cmax = max(cmax, rec[val]);
      }
    }
    ans = max(ans, cmax * __builtin_popcountll(x));
  }
  cout << ans << endl;

  return 0;
}

