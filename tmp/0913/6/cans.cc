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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) { if (i != (a)) cout << (sep); cout << (exp); } cout << "\n"

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
  // @InpNbrList(N, M, nbr, dec=1, read=len) [s2pdkmDO]
  struct nbr_t {
    int nd;
    ll len;
    nbr_t() {}
    nbr_t(int nd_, ll len_) : nd(nd_), len(len_) {}
  };
  auto nbr = vector(N, vector(0, nbr_t()));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v; u -= 1; v -= 1;
    ll len; cin >> len;
    nbr[u].emplace_back(v, len);
    nbr[v].emplace_back(u, len);
  }
  // @End [s2pdkmDO]
  ll big = 1e18;
  auto dist = vector(N, vector(N, big));
  REP(i, 0, N) dist[i][i] = 0;
  REP(i, 0, N) for (auto [j, e] : nbr[i]) dist[i][j] = e;
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(dist[i][j], dist[i][k] + dist[k][j]);
  ll K; cin >> K;
  REP(_k, 0, K) {
    ll x, y, z; cin >> x >> y >> z; x--; y--;
    updMin(dist[x][y], z);
    updMin(dist[y][x], z);
    REP(i, 0, N) REP(j, 0, N) updMin(dist[i][j], dist[i][x] + dist[x][j]);
    REP(i, 0, N) REP(j, 0, N) updMin(dist[i][j], dist[i][y] + dist[y][j]);
    ll s = 0;
    REP(i, 0, N) REP(j, i + 1, N) s += dist[i][j];
    cout << s << "\n";
  }


  return 0;
}

