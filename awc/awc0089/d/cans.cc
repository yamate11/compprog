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

  ll N, K, P; cin >> N >> K >> P;
  // @InpVec(N, M) [F4II2Vrz]
  auto M = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; M[i] = v; }
  // @End [F4II2Vrz]
  // @InpNbrList(N, K, nbr, dec=1) [eiyb7rGq]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < K; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [eiyb7rGq]
  // @InpVec(P, E, dec=1) [VJgARnwB]
  auto E = vector(P, ll());
  for (int i = 0; i < P; i++) { ll v; cin >> v; v -= 1; E[i] = v; }
  // @End [VJgARnwB]

  ll big = 1LL << 60;
  vector<ll> dist(N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[0] = 0;
  pque.emplace(0, 0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      for (ll peer: nbr[nd]) {
        ll len = M[nd] * M[peer];
        ll new_d = dist[nd] + len;
        if (dist[peer] > new_d) {
          dist[peer] = new_d;
          pque.emplace(new_d, peer);
        }
      }
    }
  }
  ll ans = big;
  REP(i, 0, P) ans = min(ans, dist[E[i]]);
  cout << ans << endl;

  return 0;
}

