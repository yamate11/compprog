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

  ll N, M, L; cin >> N >> M >> L;
  ll big = 1e18;
  vector dist(N, vector(N, big));
  REP(i, 0, N) dist[i][i] = 0;
  REP(i, 0, M) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    dist[a][b] = dist[b][a] = c;
  }
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(dist[i][j], dist[i][k] + dist[k][j]);

  vector days(N, vector(N, big));
  REP(i, 0, N) REP(j, 0, N) {
    if (i == j) days[i][j] = 0;
    else if (dist[i][j] <= L) days[i][j] = 1;
  }
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(days[i][j], days[i][k] + days[k][j]);
  ll Q; cin >> Q;
  REP(q, 0, Q) {
    ll s, t; cin >> s >> t; s--; t--;
    ll ans = days[s][t] >= big ? -1 : days[s][t] - 1;
    cout << ans << "\n";
  }



  return 0;
}

