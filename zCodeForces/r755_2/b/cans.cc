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
    ll n, m; cin >> n >> m;
    ll na = n / 3, nb = n % 3, ma = m / 3, mb = m % 3;
    ll base = na * (m - mb) + nb * ma + mb * na;
    ll ext = -1;
    if (nb == 0 || mb == 0) ext = 0;
    else if (nb == 2 && mb == 2) ext = 2;
    else ext = 1;
    cout << base + ext << "\n";

  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

