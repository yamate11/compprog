#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, m; cin >> n >> m;
  vector<ll> A(n), B(m);
  for (ll i = 0; i < n; i++) cin >> A[i];
  for (ll i = 0; i < m; i++) cin >> B[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < m; j++) {
      if (B[j] == A[i]) {
        cout << A[i] << endl;
        return 0;
      }
    }
  }
  ll x = min(A[0], B[0]);
  ll y = max(A[0], B[0]);
  cout << x * 10 + y << endl;


  return 0;
}

