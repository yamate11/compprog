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
    vector<ll> A(3);
    for (ll i = 0; i < 3; i++) cin >> A[i];
    sort(A.begin(), A.end());
    ll s = A[2] - A[0];
    if (s <= 2) s = 0;
    else s = (s - 2) * 2;
    cout << s << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

