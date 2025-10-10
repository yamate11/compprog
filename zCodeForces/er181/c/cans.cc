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

  auto g = [&](ll x, ll d) -> ll {
    return x / d;
  };

  auto f = [&](ll x) -> ll {
    ll ng = g(x, 2) + g(x, 3) + g(x, 5) + g(x, 7) - g(x, 2*3) - g(x, 2*5) - g(x, 2*7) - g(x, 3*5) - g(x, 3*7) - g(x, 5*7)
      + g(x, 2*3*5) + g(x, 2*3*7) + g(x, 2*5*7) + g(x, 3*5*7) - g(x, 2*3*5*7);
    return x - ng;
  };

  auto solve = [&]() -> void {
    ll l, r; cin >> l >> r;
    cout << f(r) - f(l - 1) << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

