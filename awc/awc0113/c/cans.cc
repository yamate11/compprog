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

  ll N, M, K, Q, T; cin >> N >> M >> K >> Q >> T; T--;
  // @InpNbrList(N, M, nbr, dec=1) [P6bHgHdo]
  auto nbr = vector(N, vector(0, int()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    nbr[u].emplace_back(v);
    nbr[v].emplace_back(u);
  }
  // @End [P6bHgHdo]
  // @InpVec(K, S, dec=1) [rM1AB3V5]
  auto S = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; S[i] = v; }
  // @End [rM1AB3V5]
  // @InpVec(Q, P, dec=1) [RvyLgBcW]
  auto P = vector(Q, ll());
  for (int i = 0; i < Q; i++) { ll v; cin >> v; v -= 1; P[i] = v; }
  // @End [RvyLgBcW]
  vector<bool> burning(N, false);
  REP(i, 0, Q) burning[P[i]] = true;

  ll big = 1LL << 60;
  vector<ll> dist(N, big);
  queue<ll> que;
  dist[T] = 0;
  que.push(T);
  while (not que.empty()) {
    ll nd = que.front(); que.pop();
    for (auto peer : nbr[nd]) {
      if (not burning[peer] and dist[peer] == big) {
        dist[peer] = dist[nd] + 1;
        que.push(peer);
      }
    }
  }
  ll ans = 0;
  REP(i, 0, K) ans = max(ans, dist[S[i]]);
  if (ans == big) ans = -1;
  cout << ans << endl;

  return 0;
}

