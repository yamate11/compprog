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
  vector<ll> A(N), S(N+1), T(N+1), P(N+1);
  for (ll i = 0; i < N; i++) cin >> A[i];
  for (ll i = 0; i < N; i++) S[i+1] = S[i] + A[i];
  T[0] = 0;
  for (ll i = 1; i <= N; i++) T[i] = T[i-1] + S[i];
  P[0] = 0;
  for (ll i = 1; i <= N; i++) P[i] = max(P[i-1], S[i]);
  ll ans = 0;
  for (ll i = 0; i < N; i++) {
    ans = max(ans, T[i] + P[i + 1]);
  }
  cout << ans << endl;
  return 0;
}

