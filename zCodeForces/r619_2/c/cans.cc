#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    auto func = [&](ll n) -> ll { return n * (n + 1) / 2; };
    ll p = (N - M) / (M + 1);
    ll q = (N - M) % (M + 1);
    ll ans = func(N) - q * func(p + 1) - (M+1 - q) * func(p);
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

