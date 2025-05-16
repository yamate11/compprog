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

  auto f = [&](const auto& X) {
    vector<ll> ret(N + 1);
    ll vmin = 0;
    ret[0] = 0;
    REP(i, 1, N + 1) {
      ret[i] = max(ret[i - 1], X[i] - vmin);
      if (X[i] < vmin) vmin = X[i];
    }
    return ret;
  };

  // @InpVec(N, A) [mzaGz8kC]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [mzaGz8kC]

  if (N == 2) {
    cout << A[0] * A[1] << endl;
    return 0;
  }

  vector B(N + 1, 0LL);
  REP(i, 0, N) B[i + 1] = B[i] + A[i];

  auto vecL = f(B);
  REP(i, 0, N + 1) B[i] = -B[i];
  auto vecLmin = f(B);
  REP(i, 0, N + 1) vecLmin[i] = -vecLmin[i];
  
  reverse(ALL(A));
  vector C(N + 1, 0LL);
  REP(i, 0, N) C[i + 1] = C[i] + A[i];
  auto vecR = f(C);
  REP(i, 0, N + 1) C[i] = -C[i];
  auto vecRmin = f(C);
  REP(i, 0, N + 1) vecRmin[i] = -vecRmin[i];
  reverse(ALL(vecR));
  reverse(ALL(vecRmin));

  ll ans = 0;
  REP(i, 1, N) {
    updMax(ans, vecL[i] * vecR[i]);
    updMax(ans, vecLmin[i] * vecRmin[i]);
  }
  cout << ans << "\n";

  return 0;
}

