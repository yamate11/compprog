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
    ll N, X; cin >> N >> X;
    vector<ll> A(N);
    bool same = true;
    bool none = true;
    ll sum = 0;
    for (ll i = 0; i < N; i++) {
      cin >> A[i];
      if (A[i] != X) same = false;
      if (A[i] == X) none = false;
      sum += A[i];
    }
    if (same) {
      cout << 0 << endl;
      return;
    }
    if (sum == N * X || none == false) {
      cout << 1 << endl;
      return;
    }
    cout << 2 << endl;
    return;

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

