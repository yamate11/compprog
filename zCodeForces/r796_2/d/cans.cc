#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
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

    

  auto solve = [&]() -> void {
    ll N, K; cin >> N >> K;
    vector<ll> A(N); REP(i, N) cin >> A[i];
    if (K <= N) {
      ll s = 0; 
      REP(i, K) s += A[i];
      ll v = s;
      REP2(i, K, N) {
        s += A[i] - A[i - K];
        v = max(v, s);
      }
      cout << v + K * (K - 1) / 2 << "\n";
    }else {
      ll s = 0;
      REP(i, N) s += A[i];
      s += (K - 1) * N;
      s -= N * (N - 1) / 2;
      cout << s << "\n";
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

