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

  ll N, H; cin >> N >> H;
  // @InpVec(N, X) [OGmyEpcW]
  auto X = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; X[i] = v; }
  // @End [OGmyEpcW]

  // @InpMVec(N -1, (P, F)) [wDcd7bex]
  auto P = vector(N -1, ll());
  auto F = vector(N -1, ll());
  for (int i = 0; i < N -1; i++) {
    ll v1; cin >> v1; P[i] = v1;
    ll v2; cin >> v2; F[i] = v2;
  }
  // @End [wDcd7bex]
  P.push_back(0);
  F.push_back(0);

  ll big = 1e18;
  auto tbl_init = vector(H + 1, vector(H + 1, big));
  auto tbl = tbl_init;
  REP(v, 0, H + 1) tbl[H][v] = 0;
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    ll dist = i == 0 ? X[i] : X[i] - X[i - 1];
    REP(u, 0, H + 1) REP(v, 0, H + 1) if (prev[u][v] < big) {
      ll ud = u - dist;
      ll vd = v + dist;
      if (ud >= 0 and vd >= 0 and vd <= H) {
        updMin(tbl[ud       ][vd       ], prev[u][v]);
        updMin(tbl[min(H, ud + F[i])][vd       ], prev[u][v] + P[i]);
        if (v + dist < H) {
          ll vv = v + dist - F[i];
          if (vv >= 0) {
            updMin(tbl[ud][vv], prev[u][v] + P[i]);
          }
        }else {
          REP(t, max(0LL, H - F[i]), H + 1) updMin(tbl[ud][t], prev[u][v] + P[i]);
        }
      }
    }
  }
  ll ans = big;
  REP(u, 0, H + 1) REP(v, 0, u + 1) ans = min(ans, tbl[u][v]);
  if (ans >= big) cout << -1 << endl;
  else cout << ans << endl;

  return 0;
}

