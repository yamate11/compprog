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

  auto solve = [&]() -> int {
    ll x1, p1, x2, p2; cin >> x1 >> p1 >> x2 >> p2;
    ll sgn = 1;
    if (p1 < p2) { sgn = -1; swap(x1, x2); swap(p1, p2); }
    ll p = p1 - p2;
    if (p >= 7) return sgn;
    ll k = 1;
    REP(i, p) k *= 10;
    if (x1 * k < x2) return -sgn;
    else if (x1 * k > x2) return sgn;
    return 0;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) {
    ll x = solve();
    if (x < 0) cout << "<";
    else if (x == 0) cout << "=";
    else cout << ">";
    cout << "\n";
  }

  return 0;
}

