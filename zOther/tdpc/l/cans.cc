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
  auto F = vector(N, vector(N, 0LL));
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) cin >> F[i][j];
  }
  auto cur = vector<ll>(1);
  cur[0] = 0;
  for (ll i = 1; i < N; i++) {
    auto acc = vector<ll>(i + 1, 0LL);
    for (ll j = i - 1; j >= 0; j--) acc[j] = acc[j + 1] + F[j][i];
    auto pmax = vector<ll>(i);
    pmax[0] = cur[0];
    for (ll j = 1; j < i; j++) pmax[j] = max(pmax[j - 1], cur[j]);
    cur = vector<ll>(i + 1);
    for (ll j = 0; j < i; j++) {
      cur[j] = acc[j] + pmax[j];
    }
    cur[i] = pmax[i-1];
  }
  ll ans = cur[0];
  for (ll i = 0; i < N; i++) ans = max(ans, cur[i]);
  cout << ans * 2 << endl;

  return 0;
}

