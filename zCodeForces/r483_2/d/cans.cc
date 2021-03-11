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
  vector<vector<ll>> V(n, vector<ll>(n));
  vector<vector<ll>> M(n, vector<ll>(n));
  for (ll i = 0; i < n; i++) {
    ll a; cin >> a;
    A[i] = V[0][i] = M[0][i] = a;
  }
  for (ll i = 1; i < n; i++) {
    for (ll j = 0; j < n - i; j++) {
      V[i][j] = V[i-1][j] ^ V[i-1][j+1];
      M[i][j] = max(V[i][j], max(M[i-1][j], M[i-1][j+1]));
    }
  }
  ll q; cin >> q;
  for (ll _q = 0; _q < q; _q++) {
    ll l, r; cin >> l >> r; l--;
    cout << M[r - l - 1][l] << endl;
  }


  return 0;
}

