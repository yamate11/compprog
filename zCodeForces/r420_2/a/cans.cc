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
  vector A(n, vector(n, 0LL));
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) cin >> A[i][j];
  }
  for (ll i = 0; i < n; i++) {
    for (ll j = 0; j < n; j++) {
      if (A[i][j] == 1) continue;
      bool found = false;
      for (ll k = 0; k < n; k++) {
        if (k == i) continue;
        for (ll l = 0; l < n; l++) {
          if (l == j) continue;
          if (A[i][j] == A[i][l] + A[k][j]) {
            found = true;
            break;
          }
        }
        if (found) break;
      }
      if (!found) {
        cout << "No\n";
        return 0;
      }
    }
  }
  cout << "Yes\n";


  return 0;
}

