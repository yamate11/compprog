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

  using sta = pair<ll, ll>;
  vector<sta> ans;
  

  auto solve =
    [&]() -> bool {
    
      ll N; cin >> N;
      vector<ll> A(N + 1), B(N + 1), P(N + 1);
      vector<bool> done(N + 1);
      vector<bool> flag1(N + 1);

      for (ll i = 1; i <= N; i++) cin >> A[i];
      for (ll i = 1; i <= N; i++) cin >> B[i];
      for (ll i = 1; i <= N; i++) cin >> P[i];
      for (ll i = 1; i <= N; i++) {
        ll j = P[i];
        if (i == j) {
          done[i] = true;
        }else {
          if (B[j] >= A[i]) return false;
        }
      }
      auto phase1 =
        [&](ll i0) -> void {
          ll i = i0;
          ll amax = 0;
          ll arg = -1;
          vector<ll> xs;
          while (true) {
            done[i] = true;
            xs.push_back(i);
            if (A[i] > amax) {
              amax = A[i];
              arg = i;
            }
            i = P[i];
            if (i == i0) break;
          }
          for (ll x : xs) {
            if (x == arg) continue;
            ans.emplace_back(arg, x);
          }
        };

      for (ll i = 1; i <= N; i++) {
        if (done[i]) continue;
        phase1(i);
      }
      return true;
    };

  if (!solve()) {
    cout << -1 << endl;
    return 0;
  }
  cout << ans.size() << endl;
  for (auto [i, j] : ans) {
    cout << i << " " << j << "\n";
  }
  

  return 0;
}

