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

  ll N, M; cin >> N >> M;
  ll S, T; cin >> S >> T; S--; T--;
  // @InpNbrList(N, M, nbr, dec=1, read=D) [86q04Oo7]
  struct nbr_t {
    int nd;
    ll D;
    nbr_t() {}
    nbr_t(int nd_, ll D_) : nd(nd_), D(D_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll D; cin >> D;
    nbr[u].emplace_back(v, D);
    nbr[v].emplace_back(u, D);
  }
  // @End [86q04Oo7]

  ll big = 1e18;
  auto f = [&](ll st) -> vector<ll> {
    vector<ll> dist(N, big);
    dist[st] = 0;
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    pque.emplace(0, st);
    while (not pque.empty()) {
      auto [d, nd] = pque.top(); pque.pop();
      if (dist[nd] != d) continue;
      for (auto [peer, len] : nbr[nd]) {
        ll newD = d + len;
        if (newD < dist[peer]) {
          dist[peer] = newD;
          pque.emplace(newD, peer);
        }
      }
    }
    return dist;
  };

  auto distS = f(S);
  auto distT = f(T);
  REP(i, 0, N) if (distS[i] == distT[i] and distS[i] < big) {
    cout << i + 1 << endl;
    return 0;
  }
  cout << -1 << endl;
  return 0;
}

