#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#include <atcoder/math>
using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll N, S, K; cin >> N >> S >> K;
    auto [y, z] = crt(vector<ll>({0, -S}), vector<ll>({K, N}));
    if (y == 0 && z == 0) return -1;
    return y / K;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << "\n";


  return 0;
}

