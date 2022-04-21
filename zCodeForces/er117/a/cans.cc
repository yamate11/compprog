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
    ll x, y; cin >> x >> y;
    if ((x + y) % 2 != 0) {
      cout << "-1 -1\n";
      return;
    }
    if (x >= y) {
      ll x0 = (x + y) / 2;
      cout << x0 << " 0\n";
      return;
    }else {
      ll y0 = (x + y) / 2;
      cout << "0 " << y0 << "\n";
      return;
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

