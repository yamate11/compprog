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
  string b; cin >> b;
  ll lmin = -1e9, rmin = -1e9, lmax = 1e9, rmax = 1e9;
  for (ll i = 4; i < n; i++) {
    ll vmax = -1e10;
    ll vmin = 1e10;
    for (ll j = i - 4; j <= i; j++) {
      vmax = max(vmax, A[j]);
      vmin = min(vmin, A[j]);
    }
    if (b[i-1] == '0') {
      if (b[i] == '1') {
        lmin = max(lmin, vmax + 1);
      }else {
        lmax = min(lmax, vmax);
      }
    }else if (b[i-1] == '1') {
      if (b[i] == '0') {
        rmax = min(rmax, vmin - 1);
      }else {
        rmin = max(rmin, vmin);
      }
    }else assert(0);
  }
  cout << lmin << " " << rmax << endl;

  return 0;
}

