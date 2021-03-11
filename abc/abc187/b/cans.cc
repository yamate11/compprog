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
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    for (ll j = i + 1; j < N; j++) {
      ll dx = abs(X[i] - X[j]);
      ll dy = abs(Y[i] - Y[j]);
      if (dy <= dx) ans++;
    }
  }
  cout << ans << endl;

  return 0;
}

