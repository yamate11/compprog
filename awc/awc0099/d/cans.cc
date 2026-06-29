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

  ll N, L, K; cin >> N >> L >> K;
  // @InpMVec(N, (W, B)) [SkD99y1F]
  auto W = vector(N, ll());
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; W[i] = v1;
    ll v2; cin >> v2; B[i] = v2;
  }
  // @End [SkD99y1F]

  vector tbl(L + 1, vector(N + 1, -1LL));
  tbl[0][0] = 0;
  REP(i, 0, N) {
    REPrev(j, L, 0) REPrev(k, N, 0) {
      if (tbl[j][k] >= 0) {
        if (j + W[i] <= L) updMax(tbl[j + W[i]][k + 1], tbl[j][k] + B[i]);
      }
    }
  }
  ll ans = -1;
  REP(j, 0, L + 1) REP(k, 0, N + 1) {
    if ((k + 1) * (K - 1) + j < L) continue;
    updMax(ans, tbl[j][k]);
  }
  cout << ans << endl;
  return 0;
}

