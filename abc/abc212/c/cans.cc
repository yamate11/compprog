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

  ll N, M; cin >> N >> M;
  vector<ll> A(N), B(M);
  for (ll i = 0; i < N; i++) cin >> A[i];
  for (ll i = 0; i < M; i++) cin >> B[i];
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  ll p = 0;
  ll q = 0;
  ll ans = 1e10;
  while (true) {
    if (p >= N || q >= M) break;
    ans = min(ans, abs(A[p] - B[q]));
    if (A[p] < B[q]) p++;
    else q++;
  }
  cout << ans << endl;

  return 0;
}

