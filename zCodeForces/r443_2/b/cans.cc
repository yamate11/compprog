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
  if (k >= n) {
    cout << n << endl;
    return 0;
  }
  ll s = 0;
  ll w = A[0];
  for (ll i = 1; i < n; i++) {
    if (A[i] == n) {
      cout << n << endl;
      return 0;
    }
    if (w < A[i]) {
      w = A[i];
      s = 1;
    }else {
      s++;
      if (s >= k) {
        cout << w << endl;
        return 0;
      }
    }
  }
  assert(0);

  return 0;
}

