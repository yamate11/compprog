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

  ll N, T; cin >> N >> T;
  auto nbr = vector<vector<pll>>(N);
  REP(t, 0, T) {
    ll m; cin >> m;
    REP(_m, 0, m) {
      ll u, v; cin >> u >> v; u--; v--;
      nbr[u].emplace_back(t, v);
      nbr[v].emplace_back(t, u);
    }
  }
  ll K; cin >> K;
  // @InpVec(K, A, dec=1) [MJd9zEZr]
  auto A = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; A[i] = v; }
  // @End [MJd9zEZr]

  vector toadd(T, vector<ll>());
  for (auto [t, v] : nbr[0]) toadd[t].push_back(v);
  vector added(N, false);
  added[0] = true;
  REP(k, 0, K) {
    ll t = A[k];
    auto cur = move(toadd[t]);
    toadd[t] = vector<ll>();
    for (ll v : cur) if (not added[v]) {
        if (v == N - 1) {
          cout << k + 1 << "\n";
          return 0;
        }
        added[v] = true;
        for (auto [tt, vv] : nbr[v]) toadd[tt].push_back(vv);
      }
  }
  cout << "-1\n";

  return 0;
}

