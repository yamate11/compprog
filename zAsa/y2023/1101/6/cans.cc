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
  // @InpNbrList(N, M, nbr, dec=1, read=(C, D)) [APDaqZBD]
  struct nbr_t {
    int nd;
    ll C;
    ll D;
    nbr_t() {}
    nbr_t(int nd_, ll C_, ll D_) : nd(nd_), C(C_), D(D_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll C; cin >> C;
    ll D; cin >> D;
    nbr[u].emplace_back(v, C, D);
    nbr[v].emplace_back(u, C, D);
  }
  // @End [APDaqZBD]

  auto f = [&](ll t, ll c, ll d) -> ll {
    auto g = [&](ll s) -> ll { return c + s + (d / (s + 1)); };
    if (g(t) <= g(t + 1)) return g(t);
    ll p0 = llround(sqrt(d) - 1);
    ll ret = 1e18;
    REP(p, max(0LL, p0 - 2), p0 + 3) ret = min(ret, g(p));
    return ret;
  };

  ll big = 1e18;
  vector dist(N, big);
  priority_queue<pll, vector<pll>, greater<pll>> pque;
  dist[0] = 0;
  pque.emplace(0, 0);
  while (not pque.empty()) {
    auto [d, nd] = pque.top(); pque.pop();
    if (d == dist[nd]) {
      for (auto peer : nbr[nd]) {
        ll new_dist = f(d, peer.C, peer.D);
        if (new_dist < dist[peer.nd]) {
          dist[peer.nd] = new_dist;
          pque.emplace(new_dist, peer.nd);
        }
      }
    }
  }
  if (dist[N - 1] == big) {
    cout << -1 << endl;
  }else {
    cout << dist[N - 1] << endl;
  }


  return 0;
}

