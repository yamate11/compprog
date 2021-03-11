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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) cin >> A[i];
    if (N % 2 == 1) {
      cout << "Second\n";
      return;
    }
    sort(A.begin(), A.end());
    for (ll i = 0; i < N / 2; i++) {
      if (A[2*i] != A[2*i + 1]) {
	cout << "First\n";
	return;
      }
    }
    cout << "Second\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

