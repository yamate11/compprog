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

  ll N; cin >> N;
  // @InpVec(N, P) [qArdx0ED]
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; P[i] = v; }
  // @End [qArdx0ED]
  // @InpVec(N - 1, W) [fSFZHWMY]
  auto W = vector(N - 1, ll());
  for (int i = 0; i < N - 1; i++) { ll v; cin >> v; W[i] = v; }
  // @End [fSFZHWMY]
  vector tbl_init(1LL << N, vector(N, -1LL));
  auto tbl = tbl_init;
  REP(i, 0, N) tbl[1LL << i][i] = 0;
  REP(i, 1, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(x, 0, 1LL << N) REP(k, 0, N) if (prev[x][k] >= 0) {
      REP(j, 0, N) if (not (x >> j & 1)) {
        updMax(tbl[x | (1LL << j)][j], prev[x][k] + abs(P[j] - P[k]) * W[i - 1]);
      }
    }
  }
  ll ans = *ranges::max_element(tbl[(1LL << N) - 1]);
  cout << ans << endl;

  return 0;
}

