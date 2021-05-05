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
  ll lim = 1010;
  auto tbl = vector(lim, vector(lim, 0LL));
  for (ll i = 0; i < N; i++) {
    ll lx, ly, rx, ry; cin >> lx >> ly >> rx >> ry;
    tbl[lx][ly]++;
    tbl[lx][ry]--;
    tbl[rx][ly]--;
    tbl[rx][ry]++;
  }
  auto ans = vector(N + 1, 0LL);
  auto diffs = vector(lim, 0LL);
  for (ll i = 0; i < lim; i++) {
    for (ll j = 0; j < lim; j++) diffs[j] += tbl[i][j];
    ll w = 0;
    for (ll j = 0; j < lim; j++) {
      w += diffs[j];
      ans[w]++;
    }
  }
  for (ll i = 1; i <= N; i++) cout << ans[i] << "\n";

  return 0;
}

