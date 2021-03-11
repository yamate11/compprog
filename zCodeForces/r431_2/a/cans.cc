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
    vector<ll> A(n);
    for (ll i = 0; i < n; i++) cin >> A[i];
    if (A[0] % 2 == 0 || A[n - 1] % 2 == 0) return false;
    if (n % 2 == 1) return true;
    return false;
  };

  cout << (solve() ? "Yes" : "No") << endl;

  return 0;
}

