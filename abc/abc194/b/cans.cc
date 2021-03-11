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
  for (ll i = 0; i < N; i++) cin >> A[i] >> B[i];
  ll vmin = LLONG_MAX;
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) {
      ll v = -1;
      if (i == j) v = A[i] + B[i];
      else v = max(A[i], B[j]);
      vmin = min(vmin, v);
    }
  }
  cout << vmin << endl;

  return 0;
}

