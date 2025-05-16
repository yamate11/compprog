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

  ll N, X; cin >> N >> X;
  // @InpMVec(N, (S, C, P)) [ZNcfknxF]
  auto S = vector(N, ll());
  auto C = vector(N, ll());
  auto P = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; S[i] = v1;
    ll v2; cin >> v2; C[i] = v2;
    ll v3; cin >> v3; P[i] = v3;
  }
  // @End [ZNcfknxF]

  vector tbl(1LL << N, vector(X + 1, -10.0));
  auto f = [&](auto rF, ll a, ll x) -> double {
    double& r = tbl[a][x];
    if (r < -1.0) {
      double val = 0.0;
      REP(i, 0, N) {
        if ((a >> i & 1) and x >= C[i]) {
          double probW = P[i] / 100.0;
          double probL = 1.0 - probW;
          updMax(val, probW * (S[i] + rF(rF, a ^ (1LL << i), x - C[i])) + probL * rF(rF, a, x - C[i]));
        }
      }
      r = val;
    }
    return r;
  };
  cout << f(f, (1LL << N) - 1, X) << "\n";

  return 0;
}

