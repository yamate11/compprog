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
  ll big = 1e18;
  vector dist(N, vector(N, big));
  REP(i, 0, N) dist[i][i] = 0;
  REP(i, 0, M) {
    ll u, v, w; cin >> u >> v >> w; u--; v--;
    dist[u][v] = w;
  }
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(dist[i][j], dist[i][k] + dist[k][j]);
  ll S, K; cin >> S >> K; S--;
  // @InpVec(K, T, dec=1) [3ro5hqnQ]
  auto T = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; v -= 1; T[i] = v; }
  // @End [3ro5hqnQ]
  vector tbl(1LL << K, vector(K, big));
  REP(k, 0, K) tbl[1LL << k][k] = dist[S][T[k]];
  REP(x, 0, 1LL << K) REP(k, 0, K) if (tbl[x][k] < big) {
    REP(t, 0, K) if (not (x >> t & 1)) {
      updMin(tbl[x | (1LL << t)][t], tbl[x][k] + dist[T[k]][T[t]]);
    }
  }
  ll full = (1LL << K) - 1;
  ll ans = big;
  REP(i, 0, K) updMin(ans, tbl[full][i] + dist[T[i]][S]);
  if (ans >= big) ans = -1;
  cout << ans << endl;

  return 0;
}

