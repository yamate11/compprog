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
  sort(A.begin(), A.end());
  for (ll i = 0; i < N; i++) {
    if (A[i] != i + 1) {
      cout << "No\n";
      return 0;
    }
  }
  cout << "Yes\n";

  return 0;
}

