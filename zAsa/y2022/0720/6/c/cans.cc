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

  ll N; cin >> N;
  vector nbr(N, vector<ll>());
  REP(i, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  auto dfs = [&](auto rF, ll nd, ll pt) -> pll {
    ll maxd = 0;
    ll arg = nd;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      auto [dd, newArg] = rF(rF, cld, nd);
      if (dd + 1 > maxd) {
        maxd = dd + 1;
        arg = newArg;
      }
    }
    return {maxd, arg};
  };
  auto [d, p] = dfs(dfs, 0, -1);
  auto [d2, p2] = dfs(dfs, p, -1);
  cout << p + 1 << " " << p2 + 1 << endl;

  return 0;
}

