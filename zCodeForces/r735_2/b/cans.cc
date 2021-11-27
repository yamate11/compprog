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
    vector<ll> A(N + 1); REP2(i, 1, N+1) cin >> A[i];
    ll vmax = N * (N - 1) - K * (A[N] | A[N-1]);
    REP2R(i, N, 1) {
      if (i * (i - 1) <= vmax) break;
      REP2R(j, i-1, 1) {
        ll t = i * j;
        if (t <= vmax) break;
        ll v = t - K * (A[i] | A[j]);
        vmax = max(vmax, v);
      }
    }
    cout << vmax << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

