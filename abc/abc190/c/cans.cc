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
  vector<ll> A(M), B(M);
  for (ll i = 0; i < M; i++) {
    cin >> A[i] >> B[i];
  }
  ll K; cin >> K;
  vector<ll> C(K), D(K);
  for (ll i = 0; i < K; i++) cin >> C[i] >> D[i];
  
  ll ans = 0;
  for (ll x = 0; x < (1 << K); x++) {
    vector<bool> dish(N + 1);
    for (ll i = 0; i < K; i++) {
      if ((x >> i) & 1) dish[C[i]] = true;
      else              dish[D[i]] = true;
    }
    ll cnt = 0;
    for (ll i = 0; i < M; i++) {
      if (dish[A[i]] && dish[B[i]]) cnt++;
    }
    ans = max(ans, cnt);
  }
  cout << ans << endl;

  return 0;
}

