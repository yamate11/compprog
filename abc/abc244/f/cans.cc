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

  ll N, M; cin >> N >> M;
  vector<vector<ll>> nbr(N);
  REP(i, M) {
    ll u, v; cin >> u >> v; u--; v--;
    nbr[u].push_back(v);
    nbr[v].push_back(u);
  }
  ll big = 1e9;
  vector tbl(1LL << N, vector<ll>(N, big));
  using sta = tuple<ll, ll, ll>; // parities, end_point, length
  queue<sta> que;
  REP(i, N) {
    tbl[0][i] = 0;
    tbl[1LL << i][i] = 1;
    que.emplace(1LL << i, i, 1);
  }
  while (not que.empty()) {
    auto [par, e, l] = que.front(); que.pop();
    for (ll x : nbr[e]) {
      ll new_par = par ^ (1LL << x);
      if (tbl[new_par][x] < big) continue;
      tbl[new_par][x] = l + 1;
      que.emplace(new_par, x, l + 1);
    }
  }
  ll ans = 0;
  REP(x, 1LL << N) {
    ll v = big;
    REP(i, N) v = min(v, tbl[x][i]);
    ans += v;
  }
  cout << ans << endl;

  return 0;
}

