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
    ll N, H; cin >> N >> H;
    vector<ll> A(N); REP(i, N) cin >> A[i];
    sort(ALL(A), greater<ll>());
    ll x = A[0] + A[1];
    ll k = (H / x) * 2;
    ll y = H % x;
    k += (y == 0) ? 0 : (y <= A[0]) ? 1 : 2;
    cout << k << "\n";
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

