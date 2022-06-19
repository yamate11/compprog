#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

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

  auto solve = [&]() -> void {
    ll N, M; cin >> N >> M;
    vector A(N, vector(M, 0LL));
    REP(i, N) REP(j, M) cin >> A[i][j];
    if ((N + M) % 2 == 0) {
      cout << "NO\n";
      return;
    }
    const ll big = 1e10;
    vector vmax(N, vector(M, -big));
    vector vmin(N, vector(M, big));
    vmax[0][0] = A[0][0];
    vmin[0][0] = A[0][0];
    REP(i, N) REP(j, M) {
      if (i + 1 < N) {
        updMax(vmax[i + 1][j], vmax[i][j] + A[i + 1][j]);
        updMin(vmin[i + 1][j], vmin[i][j] + A[i + 1][j]);
      }
      if (j + 1 < M) {
        updMax(vmax[i][j + 1], vmax[i][j] + A[i][j + 1]);
        updMin(vmin[i][j + 1], vmin[i][j] + A[i][j + 1]);
      }
    }
    if (vmax[N - 1][M - 1] >= 0 and vmin[N - 1][M - 1] <= 0) {
      cout << "YES\n";
    }else {
      cout << "NO\n";
    }
  };

  ll T; cin >> T;
  for (ll t = 0; t < T; t++) solve();

  return 0;
}

