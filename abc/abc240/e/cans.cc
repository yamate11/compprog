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
  REP(i, N-1) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  vector<ll> L(N), R(N);
  auto dfs = [&](auto rF, ll nd, ll pt, ll start) -> ll {
    ll cnt = 0;
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      ll r = rF(rF, cld, nd, start + cnt);
      cnt += r;
    }
    if (cnt == 0) cnt = 1;
    L[nd] = start;
    R[nd] = start + cnt - 1;
    return cnt;
  };
  dfs(dfs, 0, -1, 1);
  REP(i, N) cout << L[i] << " " << R[i] << "\n";

  return 0;
}

