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

  ll N, C, K; cin >> N >> C >> K;
  // @InpMVec(N, (B, W)) [KMff92S1]
  auto B = vector(N, ll());
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; B[i] = v1;
    ll v2; cin >> v2; W[i] = v2;
  }
  // @End [KMff92S1]

  vector tbl(K + 1, vector(C + 1, -1LL));
  tbl[0][0] = 0;
  REP(i, 0, N) REPrev(k, K, 0) REPrev(w, C, 0) if (tbl[k][w] >= 0) {
    if (k + 1 <= K) {
      if (w + W[i] / 2 <= C) updMax(tbl[k + 1][w + W[i] / 2], tbl[k][w] + B[i]);
    }
    if (w + W[i] <= C) updMax(tbl[k][w + W[i]], tbl[k][w] + B[i]);
  }
  ll ans = 0;
  REP(k, 0, K + 1) REP(w, 0, C + 1) ans = max(ans, tbl[k][w]);
  cout << ans << endl;

  return 0;
}

