#include <bits/stdc++.h>
#include <cassert>
using namespace std;
using ll = long long int;
using pll = pair<ll, ll>;
// #include <atcoder/all>
// using namespace atcoder;
#define REP(i, a, b) for (ll i = (a); i < (b); i++)
#define REPrev(i, a, b) for (ll i = (a); i >= (b); i--)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> void {
    ll l, r; cin >> l >> r;
    ll x = r - l + 1;
    ll y = r - 2 * l + 1;
    if (y <= 0) {
      cout << 0 << "\n";
      return;
    }
    ll ans = x * y - ((r - l) * (r - l + 1) / 2 - l * (l - 1) / 2);
    cout << ans << "\n";
  };

  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

