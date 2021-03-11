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
  vector<ll> X(n), H(n);
  for (ll i = 0; i < n; i++) cin >> X[i] >> H[i];
  ll cnt = 0;
  ll bnd = -1e10;
  for (ll i = 0; i < n; i++) {
    if (bnd < X[i] - H[i]) {
      cnt++;
      bnd = X[i];
    }else if (i == n - 1 || X[i] + H[i] < X[i+1]) {
      cnt++;
      bnd = X[i] + H[i];
    }else {
      bnd = X[i];
    }
  }
  cout << cnt << endl;

  return 0;
}

