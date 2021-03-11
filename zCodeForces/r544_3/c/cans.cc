#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n; cin >> n;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  sort(A.begin(), A.end());
  ll ans = 0;
  ll q = 0;
  for (ll p = 0; p < n; p++) {
    for (; q < n && A[q] <= A[p] + 5; q++);
    ans = max(ans, q - p);
  }
  cout << ans << endl;

  return 0;
}

