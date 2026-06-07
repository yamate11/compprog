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

  auto solve = [&]() -> void {
    ll n2, n3, n4; cin >> n2 >> n3 >> n4;
    ll ans = 0;
    auto f = [&](ll& x, ll num_x, ll& y, ll num_y) -> void {
      ll t = min(x / num_x, y / num_y);
      x -= t * num_x;
      y -= t * num_y;
      ans += t;
    };
    f(n3, 2, n4, 1);
    f(n3, 2, n2, 2);
    f(n4, 2, n2, 1);
    f(n4, 1, n2, 3);
    ll dummy = 1LL << 60;
    f(n2, 5, dummy, 1);
    cout << ans << "\n";
  };

  ll T; cin >> T;
  REP(t, 0, T) solve();

  return 0;
}

