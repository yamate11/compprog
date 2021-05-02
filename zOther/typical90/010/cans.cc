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

  ll N; cin >> N;
  auto sum = vector(3, vector(N + 1, 0LL));
  for (ll i = 1; i <= N; i++) {
    ll c, p; cin >> c >> p;
    sum[3-c][i] = sum[3-c][i-1];
    sum[c][i] = sum[c][i-1] + p;
  }
  ll Q; cin >> Q;
  for (ll q = 0; q < Q; q++) {
    ll l, r; cin >> l >> r;
    cout << sum[1][r] - sum[1][l-1] << " " << sum[2][r] - sum[2][l-1] << "\n";
  }

  return 0;
}

