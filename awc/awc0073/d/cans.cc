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

// @@ !! LIM(f:updMaxMin)

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

  ll N, M, K; cin >> N >> M >> K;
  ll big = 1LL << 60;
  vector dist(M, vector(M, big));
  REP(i, 0, M) dist[i][i] = 0;
  REP(i, 0, K) {
    ll u, v; cin >> u >> v; u--; v--;
    ll w; cin >> w;
    updMin(dist[u][v], w);
    updMin(dist[v][u], w);
  }
  REP(k, 0, M) REP(i, 0, M) REP(j, 0, M) updMin(dist[i][j], dist[i][k] + dist[j][k]);
  ll ans = 0;
  REP(i, 0, N) {
    ll s, t; cin >> s >> t; s--; t--;
    ans += dist[s][t];
  }
  cout << ans << endl;
  return 0;
}

