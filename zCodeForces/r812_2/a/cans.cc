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
    ll xmax = 0, xmin = 0, ymax = 0, ymin = 0;
    REP(i, N) {
      ll x, y; cin >> x >> y;
      xmax = max(xmax, x);
      xmin = min(xmin, x);
      ymax = max(ymax, y);
      ymin = min(ymin, y);
    }
    cout << (xmax - xmin + ymax - ymin) * 2 << "\n";

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

