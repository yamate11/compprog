#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, L; cin >> n >> L;
  vector<ll> A(2 * n), B(2 * n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  for (ll i = 0; i < n; i++) cin >> B[i];
  for (ll i = 0; i < n; i++) A[n + i] = A[i] + L;
  for (ll i = 0; i < n; i++) {
    bool ok = true;
    for (ll j = 0; j < n; j++) {
      if (B[j] - A[i + j] != B[0] - A[i + 0]) {
	ok = false;
	break;
      }
    }
    if (ok) {
      cout << "YES\n";
      return 0;
    }
  }
  cout << "NO\n";
  return 0;
}

