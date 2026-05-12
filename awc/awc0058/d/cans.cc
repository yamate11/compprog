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

  ll N, M, K; cin >> N >> M >> K; K--;
  // @InpNbrList(N, M, nbr, dec=1, read=C) [NmYk4KLP]
  struct nbr_t {
    int nd;
    ll C;
    nbr_t(int nd_ = int(), ll C_ = ll()) : nd(nd_), C(C_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    nbr[u].emplace_back(v, C);
    nbr[v].emplace_back(u, C);
  }
  // @End [NmYk4KLP]

  ll big = 1e18;
  vector dist(N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[K] = 0;
  pque.emplace(0, K);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      for (auto [peer, len] : nbr[nd]) {
        if (dist[peer] > d + len) {
          dist[peer] = d + len;
          pque.emplace(d + len, peer);
        }
      }
    }
  }
  if (dist[0] >= big or dist[N - 1] >= big) {
    cout << -1 << endl;
  }else {
    cout << dist[0] + dist[N - 1] << endl;
  }
  return 0;
}

