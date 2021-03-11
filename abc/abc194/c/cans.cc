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
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  ll s1 = 0;
  ll s2 = 0;
  for (ll i = 0; i < N; i++) {
    s1 += A[i];
    s2 += A[i] * A[i];
  }
  ll ans = (N - 1) * s2 - (s1 * s1 - s2);
  cout << ans << endl;

  return 0;
}

