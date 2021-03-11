#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    ll n; cin >> n;
    vector<ll> A(4*n);
    for (ll i = 0; i < 4*n; i++) cin >> A[i];
    sort(A.begin(), A.end());
    ll area = -1;
    for (ll i = 0; i < n; i++) {
      ll j = 2 * i;
      if (A[j] != A[j+1]) return false;
      if (A[4*n - j - 2] != A[4*n - j - 1]) return false;
      ll x = A[j] * A[4*n - j - 2];
      if (area < 0) {
	area = x;
      }else {
	if (area != x) return false;
      }
    }
    return true;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << (solve() ? "YES" : "NO") << "\n";

  return 0;
}

