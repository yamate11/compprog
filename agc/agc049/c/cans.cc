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
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  for (ll i = 0; i < N; i++) cin >> B[i];

  ll ans = 1e12;
  ll cost = 0;
  ll safeIdx = N;
  for (ll i = N-1; i >= 0; i--) {
    if (B[i] >= A[i]) { // dangerous
      ll x = B[i] - (A[i] - 1); // to be removed
      ans = min(ans, max(cost, x));
      if (safeIdx < N && B[safeIdx] >= A[safeIdx] - A[i]) {
      }else {
	cost ++;
      }
    }else { // safe
      if (safeIdx < N && B[safeIdx] - (A[safeIdx] - A[i]) > B[i]) {
      }else {
	safeIdx = i;
      }
    }
  }
  ans = min(ans, cost);
  cout << ans << endl;

  return 0;
}

