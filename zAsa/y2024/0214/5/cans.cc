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
  // @InpMVec(N, (X, Y, Z)) [HKKPan8A]
  auto X = vector(N, ll());
  auto Y = vector(N, ll());
  auto Z = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; Y[i] = v2;
    ll v3; cin >> v3; Z[i] = v3;
  }
  // @End [HKKPan8A]

  auto dist = [&](ll i, ll j) -> ll { return abs(X[i] - X[j]) + abs(Y[i] - Y[j]) + max(0LL, Z[j] - Z[i]); };

  auto big = 1e18;
  auto tbl = vector(1LL << N, vector(N, big));
  tbl[1][0] = 0;
  REP(x, 1, 1LL << N) {
    REP(t, 0, N) {
      if (x >> t & 1) {
        REP(j, 0, N) {
          updMin(tbl[x | (1LL << j)][j], tbl[x][t] + dist(t, j));
        }
      }
    }
  }
  cout << tbl[(1LL << N) - 1][0] << endl;

  return 0;
}

