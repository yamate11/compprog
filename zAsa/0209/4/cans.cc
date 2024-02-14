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

  ll N, K; cin >> N >> K;
  // @InpVec(K, A) [pS3YcWCo]
  auto A = vector(K, ll());
  for (int i = 0; i < K; i++) { ll v; cin >> v; A[i] = v; }
  // @End [pS3YcWCo]

  if (K % 2 == 0) {
    ll ans = 0;
    REP(i, 0, K / 2) ans += A[2*i + 1] - A[2*i];
    cout << ans << endl;
  }else {
    vector<ll> P(K / 2), Q(K / 2);
    REP(i, 0, K / 2) P[i] = A[2*i + 1] - A[2*i];
    REP(i, 0, K / 2) Q[i] = A[2*i + 2] - A[2*i + 1];
    vector<ll> SP(K / 2 + 1), SQ(K / 2 + 1);
    REP(i, 0, K / 2) SP[i + 1] = SP[i] + P[i];
    REPrev(i, K / 2 - 1, 0) SQ[i] = SQ[i + 1] + Q[i];
    ll big = 1e18;
    ll ans = big;
    REP(i, 0, K) updMin(ans, SP[(i + 1) / 2] + SQ[i / 2]);
    cout << ans << endl;
  }

  return 0;
}

