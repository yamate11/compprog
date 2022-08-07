#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  vector<ll> B(N + 1), C(N + 1);
  REP(i, N) {
    B[i + 1] = B[i] + A[i];
    C[i + 1] = C[i] + max(A[i], 0LL);
  }
  ll ans = 0;
  REP(i, N+1 - K) {
    ll base = C[N] - (C[i + K] - C[i]);
    ll val1 = base + (B[i + K] - B[i]);
    ll value = max(base, val1);
    ans = max(ans, value);
  }
  cout << ans << endl;

  return 0;
}

