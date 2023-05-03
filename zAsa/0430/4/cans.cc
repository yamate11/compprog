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

  ll N, Q; cin >> N >> Q;
  // @InpVec(N, X) [yIazuyK8]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [yIazuyK8]
  // @InpNbrList(N, N - 1, nbr, dec=1) [eNvTjHvF]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [eNvTjHvF]
  vector mvec(N, vector<ll>());
  auto dfs = [&](auto rF, ll nd, ll pt) -> void {
    vector<ll> vec{X[nd]};
    for (ll cld : nbr[nd]) {
      if (cld == pt) continue;
      rF(rF, cld, nd);
      auto v1 = move(vec);
      vec = vector<ll>();
      const auto& v2 = mvec[cld];
      ll i1 = 0, i2 = 0;
      while (i1 < SIZE(v1) or i2 < SIZE(v2)) {
        if (i1 == SIZE(v1) or (i2 < SIZE(v2) and v1[i1] < v2[i2])) {
          vec.push_back(v2[i2]);
          i2++;
        }else {
          vec.push_back(v1[i1]);
          i1++;
        }
      }
      if (SIZE(vec) >= 20) vec.resize(20);
    }
    mvec[nd] = move(vec);
  };
  dfs(dfs, 0, -1);
  REP(_q, 0, Q) {
    ll v, k; cin >> v >> k; v--;
    cout << mvec[v][k - 1] << "\n";
  }

  return 0;
}

