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

  auto f = [&](ll x, ll y) -> ll {
    auto g = [&](ll p) -> ll {
      return countr_zero(bit_ceil((u64)p));
    };
    return g(x) + g(y);
  };

  auto solve = [&]() -> ll {
    ll n, m, a, b; cin >> n >> m >> a >> b; a--; b--;
    ll x1 = f(a + 1, m);
    ll x2 = f(n - a, m);
    ll x3 = f(n, b + 1);
    ll x4 = f(n, m - b);
    ll ans = 1 + min(x1, min(x2, min(x3, x4)));
    return ans;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

