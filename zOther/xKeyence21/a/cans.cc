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
  vector<ll> A(N), B(N), C(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  for (ll i = 0; i < N; i++) cin >> B[i];
  ll maxA = 0;
  for (ll i = 0; i < N; i++) {
    maxA = max(maxA, A[i]);
    ll x = maxA * B[i];
    if (i == 0) C[i] = x;
    else C[i] = max(C[i - 1], x);
  }
  for (ll i = 0; i < N; i++) {
    cout << C[i] << "\n";
  }

  return 0;
}

