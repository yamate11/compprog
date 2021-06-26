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
  vector<ll> X(N), Y(N);
  for (ll i = 0; i < N; i++) cin >> X[i] >> Y[i];
  sort(X.begin(), X.end());
  sort(Y.begin(), Y.end());
  ll ans = 0;
  ll m = N / 2;
  for (ll i = 0; i < N; i++) {
    ans += abs(X[i] - X[m]) + abs(Y[i] - Y[m]);
  }
  cout << ans << endl;

  return 0;
}

