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
  // @InpNbrList(N, M, nbr, dec=1) [RjDpIYET]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [RjDpIYET]

  auto report = [&](ll i, ll j) -> void {
    cout << i + 1 << " " << j + 1 << "\n";
  };

  vector<bool> visited(N, false);
  auto dfs = [&](auto rF, ll nd) -> void {
    visited[nd] = true;
    for (ll p : nbr[nd]) {
      if (not visited[p]) {
        report(nd, p);
        rF(rF, p);
      }
    }
  };
  dfs(dfs, 0);
  
  visited = vector<bool>(N, false);
  queue<ll> que;
  que.push(0);
  visited[0] = true;
  while (not que.empty()) {
    ll nd = que.front(); que.pop();
    for (ll p : nbr[nd]) {
      if (not visited[p]) {
        visited[p] = true;
        report(nd, p);
        que.push(p);
      }
    }
  }


  return 0;
}

