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

  ll N, K; cin >> N >> K;
  ll ans = 0;
  auto f = [&](ll t) -> ll {
    if (t <= 1) return 0;
    if (t > 2 * N) return 0;
    if (t <= N + 1) return t - 1;
    return N - (t - (N + 1));
  };

  for (ll x = 2; x + K <= 2 * N; x++) {
    ans += f(x) * f(x + K);
  }
  cout << ans << endl;

  return 0;
}

