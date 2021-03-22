#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<vector<ll>> C(N, vector(N, 0LL));
  for (ll i = 0; i < N; i++) {
    for (ll j = 0; j < N; j++) cin >> C[i][j];
  }
  ll dmin = LLONG_MAX;
  ll darg = -1;
  for (ll i = 0; i < N; i++) {
    ll d = C[i][0] - C[0][0];
    for (ll j = 1; j < N; j++) {
      if (d != C[i][j] - C[0][j]) {
        cout << "No\n";
        return 0;
      }
    }
    if (d < dmin) {
      dmin = d;
      darg = i;
    }
  }
  vector<ll> A(N), B(N);
  for (ll j = 0; j < N; j++) B[j] = C[darg][j];
  for (ll i = 0; i < N; i++) A[i] = C[i][0] - C[darg][0];
  cout << "Yes\n";
  for (ll i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
  for (ll i = 0; i < N; i++) {
    if (i > 0) cout << " ";
    cout << B[i];
  }
  cout << endl;

  return 0;
}

