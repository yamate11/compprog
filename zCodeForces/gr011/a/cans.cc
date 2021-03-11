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
    ll n; cin >> n;
    vector<ll> A(n);
    ll sum = 0;
    for (ll i = 0; i < n; i++) {
      cin >> A[i];
      sum += A[i];
    }
    if (sum == 0) {
      cout << "NO\n";
      return;
    }
    cout << "YES\n";
    if (sum > 0) {
      sort(A.begin(), A.end(), greater<ll>());
    }else {
      sort(A.begin(), A.end());
    }
    for (ll i = 0; i < n; i++) {
      if (i != 0) cout << " ";
      cout << A[i];
    }
    cout << "\n";
    
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

