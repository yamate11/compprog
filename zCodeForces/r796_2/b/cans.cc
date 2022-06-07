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
    vector<ll> A(N); REP(i, N) cin >> A[i];
    ll pow2 = 1e18;
    ll numEven = 0;
    REP(i, N) {
      ll cnt = 0;
      ll a = A[i];
      while (a % 2 == 0) {
        a /= 2;
        cnt++;
      }
      if (cnt > 0) numEven++;
      pow2 = min(pow2, cnt);
    }
    ll ans = 0;
    if (numEven == 0) ans = 0;
    else if (pow2 == 0) ans = numEven;
    else ans = pow2 + numEven - 1;
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

