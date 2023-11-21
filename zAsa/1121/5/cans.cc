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

  ll N; cin >> N;
  // @InpMVec(N, (X, Y, Z)) [0a6X2Rud]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  auto Z = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
    ll v3; cin >> v3; Z[i] = v3;
  }
  // @End [0a6X2Rud]

  auto dist = [&](ll a, ll b) -> ll {
    return abs(X[a] - X[b]) + abs(Y[a] - Y[b]) + max(0LL, Z[b] - Z[a]);
  };

  ll big = 1e9;
  vector tbl(1LL << N, vector(N, big));
  tbl[1][0] = 0;
  REP(x, 1, 1LL << N) {
    REP(e, 0, N) {
      if (tbl[x][e] < big) {
        REP(g, 0, N) {
          if (not (x >> g & 1)) {
            updMin(tbl[x | (1LL << g)][g], tbl[x][e] + dist(e, g));
          }
        }
      }
    }
  }
  ll ans = big;
  REP(e, 1, N) updMin(ans, tbl[(1LL << N) - 1][e] + dist(e, 0));
  cout << ans << endl;

  return 0;
}

