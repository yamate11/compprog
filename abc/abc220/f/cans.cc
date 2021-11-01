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

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N; cin >> N;
  vector<vector<ll>> nbr(N);
  for (ll i = 0; i < N-1; i++) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  vector<ll> subsize(N);
  ll cnt = 0;
  auto dfs = [&](auto rF, ll nd, ll pt, ll lev) -> ll {
    cnt += lev;
    ll ret = 1;
    for (ll c : nbr[nd]) {
      if (c == pt) continue;
      ret += rF(rF, c, nd, lev + 1);
    }
    subsize[nd] = ret;
    return ret;
  };
  dfs(dfs, 0, -1, 0);
  vector<ll> ans(N);
  ans[0] = cnt;
  auto dfs2 = [&](auto rF, ll nd, ll pt, ll v) -> void {
    ll newV = v;
    if (nd != 0) {
      newV = v - subsize[nd] + (N - subsize[nd]);
      ans[nd] = newV;
    }
    for (ll c : nbr[nd]) {
      if (c == pt) continue;
      rF(rF, c, nd, newV);
    }
  };
  dfs2(dfs2, 0, -1, cnt);
  for (ll i = 0; i < N; i++) cout << ans[i] << "\n";

  return 0;
}

