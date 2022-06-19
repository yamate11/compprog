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

  auto solve = [&]() -> ll {
    ll N; cin >> N;
    vector nbr(N, vector<ll>());
    REP(i, N - 1) {
      ll x, y; cin >> x >> y; x--; y--;
      nbr[x].push_back(y);
      nbr[y].push_back(x);
    }
    if (N == 1) return 0;
    if (N == 2) return 1;
    ll root = 0;
    bool hasBranch = false;
    REP(i, N) if (SIZE(nbr[i]) >= 3) hasBranch = true;
    while (SIZE(nbr[root]) == 1) root++;
    auto dfs = [&](auto rF, ll nd, ll pt) -> ll {
      ll ret = 0;
      bool hasZero = false;
      for (ll cld : nbr[nd]) {
        if (cld == pt) continue;
        ll t = rF(rF, cld, nd);
        if (t == 0) {
          if (hasZero) {
            ret += 1;
          }else {
            hasZero = true;
          }
        }else {
          ret += t;
        }
      }
      return ret;
    };
    ll ans = dfs(dfs, root, -1);
    if (hasBranch and ans == 1) ans = 2;
    return ans;
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) cout << solve() << "\n";

  return 0;
}

