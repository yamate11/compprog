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
  if (n > k * (k - 1)) {
    cout << "NO\n";
    return 0;
  }
  vector<ll> X(n), Y(n);
  for (ll i = 0; i < n; i++) {
    X[i] = i % k;
  }
  for (ll i = 1; i < k; i++) {
    for (ll j = 0; j < k; j++) {
      ll idx = (i - 1) * k + j;
      if (idx >= n) break;
      Y[idx] = (i + j) % k;
    }
  }
  cout << "YES\n";
  for (ll i = 0; i < n; i++) {
    cout << X[i] + 1 << " " << Y[i] + 1 << "\n";
  }

  return 0;
}

