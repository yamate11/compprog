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
    ll N; cin >> N;
    vector<ll> A(N), B(N);
    for (ll i = 0; i < N; i++) cin >> A[i];
    for (ll i = 0; i < N; i++) cin >> B[i];
    using sta = pair<ll, ll>;
    vector<sta> bi;
    bi.emplace_back(B[0], 0);
    ll last = B[0];
    for (ll i = 1; i < N; i++) {
      if (last < B[i]) {
        bi.emplace_back(B[i], i);
        last = B[i];
      }
    }
    ll ans = 1e10;
    for (ll i = 0 ; i < N; i++) {
      sta comp(A[i], 0);
      auto it = lower_bound(bi.begin(), bi.end(), comp);
      auto [x, idx] = *it;
      ans = min(ans, i + idx);
    }
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

