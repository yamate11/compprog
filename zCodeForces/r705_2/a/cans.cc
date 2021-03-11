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
    ll n, k; cin >> n >> k;
    vector<ll> A;
    for (ll i = (k + 1) / 2; i < k; i++) A.push_back(i);
    for (ll i = k + 1; i <= n; i++) A.push_back(i);
    cout << A.size() << "\n";
    for (ll i = 0; i < (ll)A.size(); i++) {
      if (i > 0) cout << " ";
      cout << A[i];
    }
    cout << "\n";

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

