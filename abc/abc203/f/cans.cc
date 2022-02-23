#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;

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

#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, K; cin >> N >> K;
  vector<ll> A(N); REP(i, N) cin >> A[i];
  sort(ALL(A));
  const ll lim = 64 - __builtin_clzll(A[N-1]);
  const ll big = 1e15;
  auto tbl = vector(N + 1, vector(lim + 1, big));
  tbl[0][0] = 0;
  REP(i, N) REP(k, lim + 1) {
    updMin(tbl[i + 1][k], tbl[i][k] + 1);
    ll j = lower_bound(ALL(A), (A[i] + 2) / 2) - A.begin();
    if (k + 1 < lim + 1) updMin(tbl[i + 1][k + 1], tbl[j][k]);
  }
  REP(k, lim + 1) if (tbl[N][k] <= K) {
    cout << k << " " << tbl[N][k] << endl;
    break;
  }
  
  return 0;
}

