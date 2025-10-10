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

// @@ !! LIM(input f:updMaxMin)

// ---- inserted library file input.cc

// The contents are empty.

// ---- end input.cc

// ---- inserted function f:updMaxMin from util.cc
template<typename T>
bool updMax(T& tmax, const T& x) {
  if (x > tmax) { tmax = x; return true;  }
  else          {           return false; }
}
template<typename T>
bool updMin(T& tmin, const T& x) {
  if (x < tmin) { tmin = x; return true;  }
  else          {           return false; }
}
// ---- end f:updMaxMin

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, M; cin >> N >> M;
  // @InpNbrList(N, M, nbr, dec=1, read=C) [Wsh4dq0I]
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
  // @End [Wsh4dq0I]

  ll big = 1e18;

  vector<vector<ll>> dist(N, vector<ll>(N, big));
  REP(i, 1, N) dist[i][i] = 0;
  REP(i, 1, N) for (auto [j, d] : nbr[i]) if (j > 0) dist[i][j] = dist[j][i] = d;
  REP(k, 1, N) REP(i, 1, N) REP(j, 1, N) updMin(dist[i][j], dist[i][k] + dist[k][j]);

  ll ans = big;
  ll sz = ssize(nbr[0]);
  REP(i, 0, sz) REP(j, i + 1, sz) {
    auto [pi, di] = nbr[0][i];
    auto [pj, dj] = nbr[0][j];
    ans = min(ans, di + dj + dist[pi][pj]);
  }
  if (ans == big) ans = -1;

  cout << ans << endl;



  return 0;
}

