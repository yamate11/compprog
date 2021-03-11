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

  const ll big = 1e10;
  ll ans = big;
  ll N; cin >> N;
  vector<ll> A(N), P(N), X(N);
  for (ll i = 0; i < N; i++) cin >> A[i] >> P[i] >> X[i];
  for (ll i = 0; i < N; i++) {
    if (X[i] - A[i] > 0) ans = min(ans, P[i]);
  }


  if (ans == big) {
    cout << -1 << endl;
  }else {
    cout << ans << endl;
  }

  return 0;
}

