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
#define REPOUT(i, a, b, exp, sep) REP(i, (a), (b)) cout << (exp) << (i + 1 == (b) ? "\n" : (sep))

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
  vector d1(N, vector(N, big));
  REP(i, 0, N) d1[i][i] = 0;
  REP(i, 0, M) {
    ll a, b, c; cin >> a >> b >> c; a--; b--;
    d1[a][b] = d1[b][a] = c;
  }
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(d1[i][j], d1[i][k] + d1[k][j]);
  vector d2(N, vector(N, big));
  REP(i, 0, N) REP(j, 0, N) if (d1[i][j] <= L) d2[i][j] = 1;
  REP(i, 0, N) d2[i][i] = 0;
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(d2[i][j], d2[i][k] + d2[k][j]);
  ll Q; cin >> Q;
  REP(i, 0, Q) {
    ll s, t; cin >> s >> t; s--; t--;
    if (d2[s][t] >= big) { cout << -1 << "\n"; }
    else cout << d2[s][t] - 1 << "\n";
  }
  


  return 0;
}

