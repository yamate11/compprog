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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    vector<ll> L(N), R(N);
    for (ll i = 0; i < N; i++) cin >> L[i] >> R[i];
    vector<vector<ll>> memo(101, vector<ll>(101, -1));
    auto func = [&](auto rF, ll l, ll r) -> ll {
      ll& ret_val = memo[l][r];
      if (ret_val < 0) {
        vector<bool> rec(110);
        for (ll i = 0; i < N; i++) {
          if (l <= L[i] && R[i] <= r) {
            ll g1 = rF(rF, l, L[i]);
            ll g2 = rF(rF, R[i], r);
            rec[g1 ^ g2] = true;
          }
        }
        for (ll g = 0; true; g++) {
          if (!rec[g]) {
            ret_val = g;
            break;
          }
        }
      }
      return ret_val;
    };

    ll g = func(func, 1, 100);
    if (g == 0) cout << "Bob\n";
    else cout << "Alice\n";
  };

  ll T; cin >> T;
  for (; T > 0; T--) solve();

  return 0;
}

