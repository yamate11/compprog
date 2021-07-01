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
  auto A = vector(H, vector(W, 0LL));
  auto B = vector(H, vector(W, 0LL));
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) cin >> A[i][j];
  }
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) cin >> B[i][j];
  }
  ll cnt = 0;
  for (ll i = 0; i+1 < H; i++) {
    for (ll j = 0; j+1 < W; j++) {
      ll diff = B[i][j] - A[i][j];
      for (ll k = 0; k < 2; k++) {
        for (ll l = 0; l < 2; l++) A[i+k][j+l] += diff;
      }
      cnt += abs(diff);
    }
  }
  for (ll i = 0; i < H; i++) {
    if (A[i][W-1] != B[i][W-1]) {
      cout << "No\n";
      return 0;
    }
  }
  for (ll i = 0; i < W; i++) {
    if (A[H-1][i] != B[H-1][i]) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n" << cnt << "\n";

  return 0;
}

