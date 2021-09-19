#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<ll> A(N), B(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  for (ll i = 0; i < N; i++) cin >> B[i];
  ll base = 0;
  for (ll i = 0; i < N; i++) base += A[i] * B[i];
  ll dmax = 0;
  for (ll k = 0; k < N; k++) {
    ll d = 0;
    for (ll i = 1; true; i++) {
      ll p = k - i;
      ll q = k + i;
      if (p < 0 || q >= N) break;
      d += A[p] * B[q] + A[q] * B[p] - A[p] * B[p] - A[q] * B[q];
      dmax = max(dmax, d);
    }
  }
  for (ll k = 0; k+1 < N; k++) {
    ll d = 0;
    for (ll i = 0; true; i++) {
      ll p = k - i;
      ll q = k+1 + i;
      if (p < 0 || q >= N) break;
      d += A[p] * B[q] + A[q] * B[p] - A[p] * B[p] - A[q] * B[q];
      dmax = max(dmax, d);
    }
  }
  cout << base + dmax << endl;

  return 0;
}

