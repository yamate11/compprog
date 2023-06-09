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
  vector<ll> A(N);
  for (ll i = 0; i < N; i++) cin >> A[i];
  ll ans = 0;
  for (ll p = 0; p < N; ) {
    ll q = p;
    for (; q+1 < N && A[q] < A[q+1]; q++);
    ll sz = q - p + 1;
    ans += sz * (sz + 1) / 2;
    p = q + 1;
  }
  cout << ans << endl;

  return 0;
}

