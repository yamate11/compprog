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
  for (ll i = 0 ; i < n; i++) cin >> A[i];
  ll cnt = 0;
  for (ll i = 1; i < n-1; i++) {
    if (A[i-1] == 1 && A[i] == 0 && A[i+1] == 1) {
      cnt++;
      A[i+1] = 0;
    }
  }
  cout << cnt << endl;

  return 0;
}

