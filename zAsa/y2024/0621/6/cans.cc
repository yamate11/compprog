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

  ll N, M; cin >> N >> M;
  // @InpMVec(M, ((A, dec=1), (B, dec=1), C)) [yshI1Oii]
  auto A = vector(M, ll());
  auto B = vector(M, ll());
  auto C = vector(M, ll());
  for (int i = 0; i < M; i++) {
    ll v1; cin >> v1; v1 -= 1; A[i] = v1;
    ll v2; cin >> v2; v2 -= 1; B[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [yshI1Oii]

  ll big = 1e18;
  vector dist(N, vector(N, big));
  REP(p, 0, N) dist[p][p] = 0;
  REP(i, 0, M) {
    updMin(dist[A[i]][B[i]], C[i]);
    updMin(dist[B[i]][A[i]], C[i]);
  }
  REP(r, 0, N) REP(p, 0, N) REP(q, 0, N) updMin(dist[p][q], dist[p][r] + dist[r][q]);
  ll s = 0;
  REP(p, 0, N) REP(q, p + 1, N) s += dist[p][q];

  ll K; cin >> K;
  REP(k, 0, K) {
    ll x, y, z; cin >> x >> y >> z; x--; y--;
    REP(p, 0, N) REP(q, p + 1, N) {
      ll a = dist[p][x] + z + dist[y][q];
      ll b = dist[p][y] + z + dist[x][q];
      ll new_d = min(dist[p][q], min(a, b));
      s -= dist[p][q] - new_d;
      dist[p][q] = new_d;
      dist[q][p] = new_d;
    }
    cout << s << "\n";
  }

  return 0;
}

