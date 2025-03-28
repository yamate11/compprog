#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll N; cin >> N;
    vector<ll> A(N);
    for (ll i = 0; i < N; i++) cin >> A[i];
    if (A[0] + A[1] <= A[N-1]) {
      cout << "1 2 " << N << endl;
    }else {
      cout << -1 << endl;
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

