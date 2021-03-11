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
  if (n == 1) {
    cout << A[0] << endl;
    return 0;
  }
  ll vmin = LLONG_MAX;
  ll vmax = LLONG_MIN;
  ll sum = 0;
  for (ll i = 0; i < n; i++) {
    sum += abs(A[i]);
    vmin = min(vmin, A[i]);
    vmax = max(vmax, A[i]);
  }
  if (vmin >= 0) sum -= 2 * vmin;
  if (vmax <= 0) sum += 2 * vmax;
  cout << sum << endl;

  return 0;
}

