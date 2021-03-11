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

  ll prod = 0;
  for (ll i = 0; i < N; i++) prod += A[i] * B[i];
  if (prod == 0) {
    cout << "Yes\n";
  }else {
    cout << "No\n";
  }

  return 0;
}

