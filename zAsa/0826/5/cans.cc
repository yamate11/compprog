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

  ll N, M, R; cin >> N >> M >> R;
  // @InpVec(R, vecR, dec=1) [MsTizoFl]
  auto vecR = vector(R, ll());
  for (int i = 0; i < R; i++) { ll v; cin >> v; v -= 1; vecR[i] = v; }
  // @End [MsTizoFl]
  ll big = 1e18;
  vector dist(N, vector(N, big));
  REP(i, 0, N) dist[i][i] = 0;
  REP(i, 0, M) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    dist[a][b] = dist[b][a] = c;
  }
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(dist[i][j], dist[i][k] + dist[k][j]);
  
  vector tbl(1LL << R, vector(R, big));
  REP(t, 0, R) tbl[1LL << t][t] = 0;
  REP(x, 0, 1LL << R) REP(t, 0, R) {
    if (tbl[x][t] >= big) continue;
    REP(s, 0, R) {
      if (s == t) continue;
      if (x >> s & 1) continue;
      ll y = x | (1LL << s);
      ll d = dist[vecR[t]][vecR[s]];
      updMin(tbl[y][s], tbl[x][t] + d);
    }
  }
  ll ans = big;
  REP(t, 0, R) ans = min(ans, tbl[(1LL << R) - 1][t]);
  cout << ans << endl;

  return 0;
}

