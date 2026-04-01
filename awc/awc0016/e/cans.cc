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
  // @InpVec(N, P) [NO2azqoA]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [NO2azqoA]
  ll S, T; cin >> S >> T; S--; T--;
  // @InpNbrList(N, M, nbr, dec=1, read=W) [KHBQE0YL]
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
  // @End [KHBQE0YL]

  ll big = 1e18;
  vector gain(1LL << N, vector(N, -big));
  gain[1LL << S][S] = P[S];
  auto dfs = [&](auto rF, ll x, ll t, ll g) -> void {
    for (auto [p, w] : nbr[t]) {
      ll new_g, new_x;
      if (x >> p & 1) {
        new_g = g - w;
        new_x = x;
      }else {
        new_g = g - w + P[p];
        new_x = x | (1LL << p);
      }
      if (gain[new_x][p] < new_g) {
        gain[new_x][p] = new_g;
        rF(rF, new_x, p, new_g);
      }
    }
  };
  dfs(dfs, 1LL << S, S, P[S]);
  ll ans = -big;
  REP(x, 0, 1LL << N) {
    ans = max(ans, gain[x][T]);
  }
  cout << ans << endl;
  return 0;
}

