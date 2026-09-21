#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using u64 = unsigned long long;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto mask = [&](ll k) -> ll { return (1LL << k) - 1; };

  auto solve = [&]() -> void {
    ll x, y; cin >> x >> y;
    ll k = 30;
    for (; k >= 0 and (mask(k) & x) + (mask(k) & y) < (1LL << k); k--);
    if (k < 0) {
      cout << x + y << " " << 0 << "\n";
      return;
    }
    ll y0 = y - (mask(k) & y) + (1LL << k);
    cout << x + y << " " << y0 - y << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

