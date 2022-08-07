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
    vector<ll> ans(N);
    ll x = N - 1;
    for (;;) {
      ll y = llround(ceil(sqrt(x)));
      if (y*y == x) {
        REP(i, x + 1) ans[i] = x - i;
        break;
      }else {
        REP2(i, y*y - x, x + 1) ans[i] = y*y - i;
        x = y*y - x - 1;
      }
    }
    for (ll a : ans) cout << a << " ";
    cout << "\n";

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

