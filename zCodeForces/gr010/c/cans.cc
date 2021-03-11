#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> ll {
    ll n; cin >> n;
    vector<ll> A(n);
    for (ll i = 0; i < n; i++) cin >> A[i];
    ll sum = 0;
    for (ll i = 1; i < n; i++) {
      if (A[i-1] > A[i]) sum += A[i-1] - A[i];
    }
    return sum;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << endl;

  return 0;
}

