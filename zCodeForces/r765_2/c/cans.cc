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

  ll N, L, K; cin >> N >> L >> K;
  vector<ll> D(N + 1), A(N);
  REP(i, N) cin >> D[i];
  REP(i, N) cin >> A[i];
  D[N] = L;

  ll big = 1e10;
  vector tbl_init(K + 1, vector(N + 1, big));
  auto tbl = tbl_init;
  tbl[0][0] = 0;
  REP2(i, 1, N + 1) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(rm, K + 1) {
      REP(ln, N) {
        if (prev[rm][ln] >= big) continue;
        updMin(tbl[rm][i],      prev[rm][ln] + A[ln] * (D[i] - D[i - 1]));
        if (rm + 1 <= K) updMin(tbl[rm + 1][ln], prev[rm][ln] + A[ln] * (D[i] - D[i - 1]));
      }
    }
  }
  ll ans = tbl[0][N];
  REP(rm, K + 1) ans = min(ans, tbl[rm][N]);
  cout << ans << "\n";

  return 0;
}

