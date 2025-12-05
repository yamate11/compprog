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

  ll N, Ma, Mb; cin >> N >> Ma >> Mb;
  // @InpMVec(N, (A, B, C)) [LB97wF6D]
  auto A = vector(N, ll());
  auto B = vector(N, ll());
  auto C = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; A[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
    ll v3; cin >> v3; C[i] = v3;
  }
  // @End [LB97wF6D]

  ll totA = accumulate(ALL(A), 0LL);
  ll totB = accumulate(ALL(B), 0LL);
  ll K = min(totA / Ma, totB / Mb);

  if (N == 1) {
    if (A[0] * Mb == B[0] * Ma) {
      cout << C[0] << endl;
    }else {
      cout << -1 << endl;
    }
    return 0;
  }

  ll big = 1e18;
  ll H1 = N / 2;
  ll H2 = N - H1;
  vector info1(totA + 1, vector(totB + 1, big));
  REP(x, 0, 1LL << H1) {
    ll sa = 0, sb = 0, sc = 0;
    REP(i, 0, N) if (x >> i & 1) {
      sa += A[i];
      sb += B[i];
      sc += C[i];
    }
    updMin(info1[sa][sb], sc);
  }
  ll ans = big;
  REP(x, 0, 1LL << H2) {
    ll sa = 0, sb = 0, sc = 0;
    REP(i, 0, N) if (x >> i & 1) {
      sa += A[H1 + i];
      sb += B[H1 + i];
      sc += C[H1 + i];
    }
    REP(k, 1, K + 1) {
      ll a1 = Ma * k - sa;
      ll b1 = Mb * k - sb;
      if (a1 >= 0 and b1 >= 0) updMin(ans, sc + info1[a1][b1]);
    }
  }
  if (ans >= big) ans = -1;
  cout << ans << endl;
  return 0;
}

