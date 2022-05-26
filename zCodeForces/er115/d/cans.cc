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
    ll N; cin >> N;
    vector<ll> A(N), B(N), SA(N + 1), SB(N + 1);
    REP(i, N) {
      ll a, b; cin >> a >> b;
      A[i] = a;
      B[i] = b;
      SA[a]++;
      SB[b]++;
    }
    ll subt = 0;
    REP(i, N) {
      subt += (SA[A[i]] - 1) * (SB[B[i]] - 1);
    }
    ll ans = N * (N - 1) * (N - 2) / 6 - subt;
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

