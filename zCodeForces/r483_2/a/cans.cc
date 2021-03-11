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
  ll ans;
  if (n % 2 == 1) ans = A[n / 2];
  else ans = A[(n - 1) / 2];
  cout << ans << endl;


  return 0;
}

