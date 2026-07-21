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

  auto solve = [&]() -> ll {
    ll x, y, k; cin >> x >> y >> k;

    auto f = [&](ll t) -> vector<ll> {
      vector<ll> ret;
      while (t > 0) {
        ll p = t / k;
        ll q = t % k;
        ret.push_back(q);
        t = p;
      }
      ranges::reverse(ret);
      return ret;
    };
    auto vecX = f(x);
    auto vecY = f(y);
    if (x == 0 and y == 0) return 0;
    if (x == 0) return ssize(vecY);
    if (y == 0) return ssize(vecX);
    ll i = 0;
    while (i < ssize(vecX) and i < ssize(vecY) and vecX[i] == vecY[i]) i++;
    return ssize(vecX) - i + ssize(vecY) - i;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

