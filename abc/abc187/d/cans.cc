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
  ll sa = 0;
  vector<ll> D(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i] >> B[i];
    sa += A[i];
    D[i] = 2 * A[i] + B[i];
  }
  sort(D.begin(), D.end(), greater<ll>());
  ll sd = 0;
  for (ll i = 0; i < N; i++) {
    sd += D[i];
    if (sd - sa > 0) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  assert(0);

  return 0;
}

