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

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    // @InpNbrList(N, M, nbr, dec=1) [SzN8buaK]
    auto nbr = vector(N, vector(0, int()));
    for (int i = 0; i < M; i++) {
      int u, v; cin >> u >> v; u -= 1; v -= 1;
      nbr[u].emplace_back(v);
      nbr[v].emplace_back(u);
    }
    // @End [SzN8buaK]
    REP(i, 0, N) {
      if (SIZE(nbr[i]) < 4) continue;
      vector<ll> seen(N, -1), prev(N, -1);
      queue<ll> que;
      seen[i] = 0;
      for (ll j : nbr[i]) {
        seen[j] = j;
        prev[j] = i;
        que.push(j);
      }
      while (not que.empty()) {
        ll nd = que.front(); que.pop();
        for (ll peer : nbr[nd]) {
          if (peer == prev[nd]) continue;
          if (seen[peer] == seen[nd]) continue;
          if (seen[peer] == -1) {
            seen[peer] = seen[nd];
            prev[peer] = nd;
            que.push(peer);
            continue;
          }
          cout << "YES\n";
          ll i0 = seen[nd];
          ll i1 = seen[peer];
          vector<pll> ans{{nd, peer}};
          for (ll x = nd; x != i; x = prev[x]) ans.emplace_back(x, prev[x]);
          for (ll x = peer; x != i; x = prev[x]) ans.emplace_back(x, prev[x]);
          ll cnt = 0;
          for (ll j : nbr[i]) {
            if (j != i0 and j != i1) {
              ans.emplace_back(i, j);
              cnt++;
              if (cnt == 2) break;
            }
          }
          cout << SIZE(ans) << "\n";
          for (auto [p, q] : ans) {
            cout << p + 1 << " " << q + 1 << "\n";
          }
          return;
        }
      }
    }
    cout << "NO\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

