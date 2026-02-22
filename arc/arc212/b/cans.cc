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

// @@ !! LIM(input)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  ll x0, y0, c0; cin >> x0 >> y0 >> c0; x0--; y0--;
  // @InpNbrList(N, M - 1, fwd, dir=True, dec=1, read=C) [6o6ErAHX]
  struct fwd_t {
    int nd;
    ll C;
    fwd_t(int nd_ = int(), ll C_ = ll()) : nd(nd_), C(C_) {}
  };
  auto fwd = vector(N, vector(0, fwd_t()));
  for (int i = 0; i < M - 1; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    fwd[u].emplace_back(v, C);
  }
  // @End [6o6ErAHX]
  ll big = 1e18;
  vector dist(N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[y0] = c0;
  pque.emplace(c0, y0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (dist[nd] == d) {
      for (auto [peer, cost] : fwd[nd]) {
        if (dist[peer] > dist[nd] + cost) {
          dist[peer] = dist[nd] + cost;
          pque.emplace(dist[peer], peer);
        }
      }
    }
  }
  ll ans = dist[x0];
  if (ans == big) ans = -1;
  cout << ans << endl;

  return 0;
}

