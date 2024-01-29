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

  ll N, D, K; cin >> N >> D >> K;
  // @InpMVec(D, (L, R)) [K8Tx6wuv]
  auto L = vector(D, ll());
  auto R = vector(D, ll());
  for (int i = 0; i < D; i++) {
    ll v1; cin >> v1; L[i] = v1;
    ll v2; cin >> v2; R[i] = v2;
  }
  // @End [K8Tx6wuv]
  // @InpMVec(K, (S, T)) [4P3IQ7vw]
  auto S = vector(K, ll());
  auto T = vector(K, ll());
  for (int i = 0; i < K; i++) {
    ll v1; cin >> v1; S[i] = v1;
    ll v2; cin >> v2; T[i] = v2;
  }
  // @End [4P3IQ7vw]
  
  auto C = S;
  vector ans(K, 0LL);
  REP(d, 0, D) {
    REP(k, 0, K) {
      if (C[k] == T[k]) continue;
      if (not (L[d] <= C[k] and C[k] <= R[d])) continue;
      if      (C[k] < T[k]) updMax(C[k], min(T[k], R[d]));
      else if (T[k] < C[k]) updMin(C[k], max(T[k], L[d]));
      else                  assert(0);
      if (C[k] == T[k]) ans[k] = d + 1;
    }
  }
  REPOUT(i, 0, K, ans[i], "\n");

  return 0;
}

