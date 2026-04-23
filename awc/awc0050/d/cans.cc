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

  ll N, M, K; cin >> N >> M >> K;
  // @InpNbrList(N, M, nbr, dec=1, read=W) [6W86lUpy]
  struct nbr_t {
    int nd;
    ll W;
    nbr_t(int nd_ = int(), ll W_ = ll()) : nd(nd_), W(W_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll W; cin >> W;
    nbr[u].emplace_back(v, W);
    nbr[v].emplace_back(u, W);
  }
  // @End [6W86lUpy]

  // @InpMVec(K, ((L, dec=1), C)) [wHu4oyf7]
  auto L = vector(K, ll());
  auto C = vector(K, ll());
  for (int i = 0; i < K; i++) {
    ll v1; cin >> v1; v1 -= 1; L[i] = v1;
    ll v2; cin >> v2; C[i] = v2;
  }
  // @End [wHu4oyf7]

  vector<ll> crCost(N);
  REP(i, 0, K) crCost[L[i]] = C[i];

  ll big = 1e18;
  vector dist(N, big);
  dist[0] = crCost[0];
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  pque.emplace(crCost[0], 0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      for (auto [peer, len] : nbr[nd]) {
        len += crCost[peer];
        if (dist[peer] > d + len) {
          dist[peer] = d + len;
          pque.emplace(d + len, peer);
        }
      }
    }
  }
  cout << dist[N - 1] << "\n";
  return 0;
}

