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
  for (ll i = 0; i + 2 < n; i++) {
    if (A[i+2] < A[i] + A[i+1]) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";

  return 0;
}

