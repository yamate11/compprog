#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll K, M; cin >> K >> M;
  string S; cin >> S;
  ll N; cin >> N;
  vector<ll> A(N), B(N), C(N);
  for (ll i = 0; i < N; i++) {
    cin >> A[i] >> B[i] >> C[i];
  }
  for (ll k = 0; k < K; k++) {
    ll pos = k;
    for (ll i = N - 1; i >= 0; i--) {
      ll len = B[i] - A[i];
      if (C[i] <= pos && pos < C[i] + len) pos = A[i] + pos - C[i];
      else if (C[i] + len <= pos) pos -= len;
    }
    cout << S[pos];
  }
  cout << "\n";

  return 0;
}

