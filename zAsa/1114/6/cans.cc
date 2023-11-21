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

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((A, dec=1), (B, dec=1), C)) [ffZvZtVM]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [ffZvZtVM]
  ll K; cin >> K;
  // @InpMVec(K, ((X, dec=1), (Y, dec=1), Z)) [wNiNQuwH]
  auto X = vector(K, ll());
  auto Y = vector(K, ll());
  auto Z = vector(K, ll());
  for (int i = 0; i < K; i++) {
    ll v1; cin >> v1; v1 -= 1; X[i] = v1;
    ll v2; cin >> v2; v2 -= 1; Y[i] = v2;
    ll v3; cin >> v3; Z[i] = v3;
  }
  // @End [wNiNQuwH]

  ll big = 1e18;
  vector dist(N, vector(N, big));
  REP(i, 0, N) dist[i][i] = 0;
  REP(i, 0, M) dist[A[i]][B[i]] = dist[B[i]][A[i]] = C[i];
  REP(k, 0, N) REP(i, 0, N) REP(j, 0, N) updMin(dist[i][j], dist[i][k] + dist[k][j]);
  REP(k, 0, K) {
    REP(i, 0, N) REP(j, 0, N) {
      updMin(dist[i][j], dist[i][X[k]] + Z[k] + dist[Y[k]][j]);
      updMin(dist[i][j], dist[i][Y[k]] + Z[k] + dist[X[k]][j]);
    }
    ll s = 0;
    REP(i, 0, N) REP(j, i + 1, N) s += dist[i][j];
    cout << s << "\n";
  }

  return 0;
}

