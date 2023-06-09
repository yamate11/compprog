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

  ll N, C; cin >> N >> C;
  // @InpMVec(N, (X, V)) [K7MRjbeh]
  auto X = vector(N, ll());
  auto V = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; X[i] = v1;
    ll v2; cin >> v2; V[i] = v2;
  }
  // @End [K7MRjbeh]

  vector<ll> A(N), B(N);
  ll s = 0;
  REP(i, 0, N) {
    s += V[i];
    A[i] = s;
  }
  s = 0;
  REPrev(i, N - 1, 0) {
    s += V[i];
    B[i] = s;
  }
  vector<ll> P(N), Q(N);
  ll u = 0;
  REP(i, 0, N) {
    updMax(u, A[i] - X[i]);
    P[i] = u;
  }
  u = 0;
  REPrev(i, N - 1, 0) {
    updMax(u, B[i] - (C - X[i]));
    Q[i] = u;
  }
  ll ans = 0;
  updMax(ans, P[N - 1]);
  updMax(ans, Q[0]);
  REP(i, 0, N - 1) {
    updMax(ans, A[i] - 2 * X[i] + Q[i + 1]);
  }
  REPrev(i, N - 1, 1) {
    updMax(ans, B[i] - 2 * (C - X[i]) + P[i - 1]);
  }
  cout << ans << endl;

  return 0;
}

