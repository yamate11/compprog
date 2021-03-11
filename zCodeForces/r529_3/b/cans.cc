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
  ll x = A[n-1] - A[1];
  ll y = A[n-2] - A[0];
  cout << min(x, y) << endl;

  return 0;
}

