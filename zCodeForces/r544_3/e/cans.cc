#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(f:updMaxMin)
// --> f:updMaxMin
// ---- inserted function updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end updMaxMin
// @@ !! LIM  -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll n, k; cin >> n >> k;
  vector<ll> A(n), B(n);
  for (ll i = 0; i < n; i++) cin >> A[i];
  sort(A.begin(), A.end());
  ll q = 0;
  for (ll p = 0; p < n; p++) {
    while (q < n && A[q] <= A[p] + 5) q++;
    B[p] = q;
  }
  vector tbl(k + 1, vector(n + 1, 0LL));
  for (ll i = 1; i <= k; i++) {
    for (ll j = n - 1; j >= 0; j--) {
      tbl[i][j] = (B[j] - j)  + tbl[i-1][B[j]];
      updMax(tbl[i][j], tbl[i][j+1]);
    }
  }
  cout << tbl[k][0] << endl;

  return 0;
}

