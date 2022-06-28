#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM()

using pll = pair<ll, ll>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, X; cin >> N >> X;
  vector<ll> num(N + 1);
  num[0] = 1;
  REP(i, N) num[i + 1] = 2 * num[i] + 3;
  map<pll, ll> tbl;
  auto func = [&](auto rF, ll n, ll x) -> ll {
    assert(0 < x and x <= num[n]);

    auto calc = [&]() -> ll {
      ll cum = 0;
      if (x == 1) return cum;
      if (x <= 1 + num[n - 1]) {
        cum += rF(rF, n - 1, x - 1);
        return cum;
      }
      cum += rF(rF, n - 1, num[n - 1]);
      cum += 1;
      if (x == 1 + num[n - 1] + 1) {
        return cum;
      }
      if (x <= 1 + num[n - 1] + 1 + num[n - 1]) {
        cum += rF(rF, n - 1, x - (1 + num[n - 1] + 1));
        return cum;
      }
      cum += rF(rF, n - 1, num[n - 1]);
      return cum;
    };

    if (n == 0) return 1;
    auto it = tbl.find(pll(n, x));
    if (it != tbl.end()) return it->second;
    ll ans = calc();
    tbl[pll(n, x)] = ans;
    return ans;

  };
  cout << func(func, N, X) << endl;

  return 0;
}

