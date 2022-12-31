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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto out = [&](ll i, ll j) -> void {
    cout << i + 1 << " " << j + 1 << "\n";
  };

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1) [VfHP6War]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [VfHP6War]

  vector<bool> done(N);
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    if (done[nd]) return;
    done[nd] = true;
    if (pt >= 0) out(pt, nd);
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
    }
  };
  dfs(dfs, 0, -1);

  done = vector<bool>(N);
  queue<ll> que;
  que.push(0);
  done[0] = true;
  while (not que.empty()) {
    ll nd = que.front(); que.pop();
    for (ll cld : nbr[nd]) {
      if (done[cld]) continue;
      done[cld] = true;
      out(nd, cld);
      que.push(cld);
    }
  }

  return 0;
}

