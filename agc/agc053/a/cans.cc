#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
// #include <atcoder/all>
// using namespace atcoder;
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

  ll N; cin >> N;
  string S; cin >> S;
  vector<ll> A(N + 1); REP(i, N + 1) cin >> A[i];
  ll K = LLONG_MAX;
  REP(i, N) K = min(K, abs(A[i + 1] - A[i]));
  vector<ll> base(N + 1);
  for (ll i = 0; i < N; ) {
    for ( ; i < N and S[i] == '>'; i++);
    for ( ; i < N and S[i] == '<'; i++) updMax(base[i+1], base[i] + 1);
  }
  for (ll i = N - 1; i >= 0; ) {
    for ( ; i >= 0 and S[i] == '<'; i--);
    for ( ; i >= 0 and S[i] == '>'; i--) updMax(base[i], base[i+1] + 1);
  }
  vector ans(K, base);
  REP(i, N + 1) {
    ll r = A[i] - base[i] * K;
    REP(j, K) ans[j][i] += (r / K) + (j < r % K ? 1 : 0);
  }
  cout << K << "\n";
  REP(j, K) {
    REP(i, N + 1) cout << ans[j][i] << " ";
    cout << "\n";
  }

  return 0;
}

