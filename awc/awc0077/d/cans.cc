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
  // @InpVec(N, F) [8rrj1c2D]
  auto F = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; F[i] = v; }
  // @End [8rrj1c2D]
  // @InpNbrList(N, M, nbr, dec=1, read=T) [2xnAEZfN]
  struct nbr_t {
    int nd;
    ll T;
    ostream& operator<<(ostream& ostr) const {
      return ostr << "(" << nd << ", " << T << ")";
    }
    auto operator<=>(const nbr_t&) const = default;
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll T; cin >> T;
    nbr[u].emplace_back(v, T);
    nbr[v].emplace_back(u, T);
  }
  // @End [2xnAEZfN]

  vector moko(K + 1, vector<ll>());
  REP(i, 0, N) moko[F[i]].push_back(i);
  ll big = 1LL << 60;
  auto func = [&](ll coeff, const auto& init) -> vector<ll> {
    vector<ll> dist(N, big);
    priority_queue<pll, vector<pll>, greater<pll>> pque;
    dist[N - 1] = 0;
    pque.emplace(0, N - 1);
    for (auto [nd, d] : init) {
      dist[nd] = d;
      pque.emplace(d, nd);
    }
    while (not pque.empty()) {
      auto [d, nd] = pque.top(); pque.pop();
      if (dist[nd] == d) {
        for (auto [peer, len] : nbr[nd]) {
          ll new_d = d + len * coeff;
          if (new_d < dist[peer]) {
            dist[peer] = new_d;
            pque.emplace(new_d, peer);
          }
        }
      }
    }
    return dist;
  };
  
  vector<pll> init;
  REP(k, 1, K + 1) {
    auto dist = func(k, init);
    init = vector<pll>{};
    REP(nd, 0, N) {
      if (F[nd] <= k) {
        if (nd == 0) {
          ll ans = dist[0] >= big ? -1 : dist[0];
          cout << ans << "\n";
          return 0;
        }
        init.emplace_back(nd, dist[nd]);
      }
    }
  }
  assert(0);
  return 0;
}

