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
// published at https://github.com/yamate11/compprog-clib/blob/master/input.cc

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

  ll N, M, T; cin >> N >> M >> T;
  // @InpVec(N, S) [25gyTu2p]
  auto S = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; S[i] = v; }
  // @End [25gyTu2p]
  ll big = 1LL << 60;
  vector dist(N, vector<ll>(N, big));
  REP(i, 0, M) {
    ll u, v, w; cin >> u >> v >> w; dist[u][v] = w;
  }
  vector tbl(1LL << N, vector(N, big));
  tbl[1][0] = 0;
  REP(x, 0, 1LL << N) REP(i, 0, N) {
    if (tbl[x][i] < big) {
      REP(j, 0, N) {
        if (not (x >> j & 1) and dist[i][j] < big) updMin(tbl[x | (1LL << j)][j], tbl[x][i] + dist[i][j]);
      }
    }
  }
  vector val(1LL << N, 1LL);
  REP(x, 1, 1LL << N) {
    ll k = countr_zero((u64)x);
    ll y = x ^ (1LL << k);
    ll tmp;
    if (__builtin_mul_overflow(val[y], S[k], &tmp) or tmp >= T) val[x] = T;
    else val[x] = tmp;
  }
  ll ans = big;
  REP(x, 0, 1LL << N) if (tbl[x][N - 1] < big and val[x] >= T) ans = min(ans, tbl[x][N - 1]);
  if (ans == big) ans = -1;
  cout << ans << "\n";
  


  return 0;
}

