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
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i];
  }
  A.push_back(0);
  sort(A.begin(), A.end(), greater<ll>());
  ll ans = 0;
  ll k = 0;
  for (ll i = 0; i+1 <= N; i++) {
    ll fullmax = (K - k) / (i + 1);
    if (A[i] - A[i + 1] <= fullmax) {
      k += (i + 1) * (A[i] - A[i + 1]);
      ans += (i + 1) * (A[i] + A[i + 1] + 1) * (A[i] - A[i + 1]) / 2;
    }else {
      k += (i + 1) * fullmax;
      ans += (i + 1) * (A[i] + A[i] - fullmax + 1) * fullmax / 2;
      ans += (K - k) * (A[i] - fullmax);
      cout << ans << endl;
      return 0;
    }
  }
  cout << ans << endl;
  return 0;
}

