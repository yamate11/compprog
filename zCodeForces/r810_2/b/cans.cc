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

  const ll big = 1e9;
  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    vector<ll> A(N); REP(i, N) cin >> A[i];
    vector nbr(N, vector<ll>());
    REP(i, M) {
      ll x, y; cin >> x >> y; x--; y--;
      nbr[x].push_back(y);
      nbr[y].push_back(x);
    }
    ll ans = big;
    if (M % 2 == 0) {
      cout << 0 << "\n";
      return;
    }
    REP(i, N) {
      if (SIZE(nbr[i]) % 2 == 1) {
        ans = min(ans, A[i]);
      }else {
        for (ll j : nbr[i]) {
          if (SIZE(nbr[j]) % 2 == 0) ans = min(ans, A[i] + A[j]);
        }
      }
    }
    cout << ans << "\n";

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

