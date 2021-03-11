#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  vector<ll> A(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  if (k == 1) {
    auto it = min_element(A.begin(), A.end());
    cout << *it << endl;
    return 0;
  }
  if (k == 2) {
    ll x = max(A[0], A[n-1]);
    cout << x << endl;
    return 0;
  }
  auto it = max_element(A.begin(), A.end());
  cout << *it << endl;


  return 0;
}

