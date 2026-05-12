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

  auto solve = [&]() -> ll {
    ll N, M; cin >> N >> M;
    // @InpVec(N, C) [nnz7j4Vu]
    auto C = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; C[i] = v; }
    // @End [nnz7j4Vu]
    // @InpNbrList(N, M, o_nbr, dec=1) [u8lvyaPz]
    auto o_nbr = vector(N, vector(0, int()));
    for (int i = 0; i < M; i++) {
      int u, v; cin >> u >> v; u -= 1; v -= 1;
      o_nbr[u].emplace_back(v);
      o_nbr[v].emplace_back(u);
    }
    // @End [u8lvyaPz]
    
    ll big = 1LL << 60;
    vector dist(N, vector(N, big));
    queue<pll> que;
    dist[0][N - 1] = 0;
    que.emplace(0, N - 1);
    while (not que.empty()) {
      auto [i, j] = que.front(); que.pop();
      for (ll p : o_nbr[i]) for (ll q : o_nbr[j]) {
          if (C[p] != C[q] and dist[p][q] == big) {
            dist[p][q] = dist[i][j] + 1;
            que.emplace(p, q);
          }
        }
    }
    ll ans = dist[N - 1][0] == big ? -1 : dist[N - 1][0];
    return ans;
  };

  ll T; cin >> T;
  REP(t, 0, T) cout << solve() << "\n";

  return 0;
}

