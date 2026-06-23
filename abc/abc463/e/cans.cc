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

  ll N, M, Y; cin >> N >> M >> Y;
  // @InpNbrList(N, M, nbr, dec=1, read=T) [w0HFWfEa]
  struct nbr_t {
    int nd;
    ll T;
    string show() const {
      return format("({}, {})", nd, T);
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
  // @End [w0HFWfEa]
  // @InpVec(N, X) [yRavGlYU]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [yRavGlYU]

  ll big = 1LL << 60;
  vector dist(N + 1, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[0] = 0;
  pque.emplace(0, 0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      if (nd == N) {
        REP(i, 0, N) {
          ll new_d = d + Y + X[i];
          if (new_d < dist[i]) {
            dist[i] = new_d;
            pque.emplace(new_d, i);
          }
        }
      }else {
        for (auto [peer, len] : nbr[nd]) {
          ll new_d = d + len;
          if (new_d < dist[peer]) {
            dist[peer] = new_d;
            pque.emplace(new_d, peer);
          }
        }
        ll new_dN = d + X[nd];
        if (new_dN < dist[N]) {
          dist[N] = new_dN;
          pque.emplace(new_dN, N);
        }
      }
    }
  }
  REPOUT(i, 1, N, dist[i], " ");

  return 0;
}

