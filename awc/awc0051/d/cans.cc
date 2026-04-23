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

  ll N, M, K, T; cin >> N >> M >> K >> T;
  // @InpNbrList(N, M, nbr, dec=1, read=W) [ONIS5nEK]
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
  // @End [ONIS5nEK]
  // @InpVec(K, G, dec=1) [tMKlTvLW]
  auto G = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; G[i] = v; }
  // @End [tMKlTvLW]
  vector<bool> water(N, false);
  REP(i, 0, K) water[G[i]] = true;
  ll big = 1e18;
  vector dist(N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[0] = water[0] ? T : 0;
  pque.emplace(dist[0], 0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      for (auto [peer, len] : nbr[nd]) {
        ll new_d = d + len + (water[peer] ? T : 0);
        if (dist[peer] > new_d) {
          dist[peer] = new_d;
          pque.emplace(new_d, peer);
        }
      }
    }
  }
  cout << dist[N - 1] << endl;
  return 0;
}

