#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  vector<ll> A(6);
  for (ll i = 0; i < 6; i++) cin >> A[i];
  ll s = 0;
  for (ll i = 0; i < 6; i++) s += A[i];
  for (ll i = 0; i < 6; i++) {
    for (ll j = i + 1; j < 6; j++) {
      for (ll k = j + 1; k < 6; k++) {
        if (2 * (A[i] + A[j] + A[k]) == s) {
          cout << "YES\n";
          return 0;
        }
      }
    }
  }
  cout << "NO\n";

  return 0;
}

