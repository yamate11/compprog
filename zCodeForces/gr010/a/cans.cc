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
    for (ll i = 0; i < n-1; i++) {
      if (A[i] != A[i+1]) return 1;
    }
    return n;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << endl;

  return 0;
}

