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
  vector<ll> A(n), B(n);
  for (ll i = 0; i < n; i++) cin >> A[i] >> B[i];
  ll sumb = 0;
  for (ll i = 0; i < n; i++) sumb += B[i];
  ll vlim = 100 * n;
  vector tbl(n + 1, vector(vlim + 1, -1.0));
  tbl[0][0] = 0;
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j <= vlim; j++) {
      if (tbl[i][j] < 0) continue;
      
    }
  }


  return 0;
}

