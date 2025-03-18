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
  // @InpNbrList(N, M, nbr, dec=1, read=W) [dx1qF0l7]
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
  // @End [dx1qF0l7]

  vector dist(1LL << N, vector(N, vector<ll>()));
  dist[1][0] = vector<ll>{0};
  REP(x, 1, 1LL << N) {
    REP(i, 0, N) {
      if (dist[x][i].empty()) continue;
      for (nbr_t p : nbr[i]) {
        auto [j, w] = p;
        if (x >> j & 1) continue;
        ll new_x = x | (1LL << j);
        for (ll v : dist[x][i]) {
          ll new_d = v ^ w;
          dist[new_x][j].push_back(new_d);
        }
      }
    }
  }
  ll big = LLONG_MAX;
  ll ans = big;
  REP(x, 1, 1LL << N) {
    for (ll v : dist[x][N - 1]) ans = min(ans, v);
  }

  cout << ans << endl;

  return 0;
}

