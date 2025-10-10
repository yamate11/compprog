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

// @@ !! LIM()

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  auto nbr = vector(N, vector(0, pll()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v, 1);
    nbr[v].emplace_back(u, 1);
  }
  vector<ll> deg(N);
  REP(i, 0, N) deg[i] = ssize(nbr[i]);
  vector effective(N, true);
  vector<ll> to_proc;
  REP(i, 1, N - 1) if (deg[i] == 1) to_proc.push_back(i);
  while (not to_proc.empty()) {
    ll leaf = to_proc.back(); to_proc.pop_back();
    for (auto [peer, _d] : nbr[leaf]) {
      if (effective[peer]) {
        deg[peer]--;
        if (deg[peer] == 1 and peer != 0 and peer != N - 1) to_proc.push_back(peer);
      }
      effective[leaf] = false;
    }
  }
  REP(i, 1, N - 1) {
    if (effective[i] and deg[i] == 2) {
      ll x = -1, y = -1, d = 0;
      for (auto [peer, dd] : nbr[i]) {
        if (effective[peer]) {
          if (x < 0) x = peer;
          else y = peer;
          d += dd;
        }
      }
      nbr[x].emplace_back(y, d);
      nbr[y].emplace_back(x, d);
      effective[i] = false;
    }
  }
  REP(i, 0, N) {
    if (effective[i]) {
      vector<pll> z;
      for (auto [p, d] : nbr[i]) if (effective[p]) z.emplace_back(p, d);
      nbr[i] = move(z);
    }
  }

  vector<ll> ans(N);
  vector<bool> on_stack(N);
  auto dfs = [&](auto rF, ll nd, ll len) {
    if (nd == N - 1) {
      ans[len]++;
      return;
    }
    if (on_stack[nd]) return;
    on_stack[nd] = true;
    for (auto [p, d]: nbr[nd]) rF(rF, p, len + d);
    on_stack[nd] = false;
  };
  dfs(dfs, 0, 0);
  REPOUT(i, 1, N, ans[i], " ");

  return 0;
}

