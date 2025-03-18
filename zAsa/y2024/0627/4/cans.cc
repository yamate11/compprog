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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [0VTt1Vpl]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [0VTt1Vpl]
  queue<ll> que;
  ll big = 1e18;
  vector dist(N, big);
  vector<ll> ans(N);
  que.push(0);
  dist[0] = 0;
  while (not que.empty()) {
    ll x = que.front(); que.pop();
    for (ll y : nbr[x]) {
      if (dist[y] == big) {
        dist[y] = dist[x] + 1;
        ans[y] = x;
        que.push(y);
      }
    }
  }
  cout << "Yes\n";
  REP(i, 1, N) cout << ans[i] + 1 << "\n";

  return 0;
}

