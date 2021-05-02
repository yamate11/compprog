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
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      cin >> A[i][j];
    }
  }

  auto row = vector(H, 0LL);
  auto col = vector(W, 0LL);
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      row[i] += A[i][j];
      col[j] += A[i][j];
    }
  }
  for (ll i = 0; i < H; i++) {
    for (ll j = 0; j < W; j++) {
      cout << row[i] + col[j] - A[i][j]<< " ";
    }
    cout << "\n";
  }

  return 0;
}

