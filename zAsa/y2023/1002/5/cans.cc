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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "" : (sep)); cout << "\n"

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, u, v; cin >> N >> u >> v; u--; v--;
  auto nbr = vector(N, vector<ll>());
  REP(i, 0, N - 1) {
    ll a, b; cin >> a >> b; a--; b--;
    nbr[a].push_back(b);
    nbr[b].push_back(a);
  }
  auto dp = vector(N, 0LL);
  auto ht = vector(N, 0LL);
  auto parent = vector(N, -1LL);
  auto dfs = [&](auto rF, ll nd, ll pt, ll d) -> void {
    parent[nd] = pt;
    dp[nd] = d;
    ll h = 0;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd, d + 1);
      h = max(h, ht[cld] + 1);
    }
    ht[nd] = h;
  };
  dfs(dfs, v, -1, 0);
  ll e = (dp[u] - 1) / 2;
  ll p = u;
  REP(i, 0, e) p = parent[p];
  ll ans = dp[p] + ht[p] - 1;
  cout << ans << endl;

  return 0;
}

