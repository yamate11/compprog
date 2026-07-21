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
  // @InpMVec(N, (V, W)) [auAMpRlT]
  auto V = vector(N, ll());
  auto W = vector(N, ll());
  for (int i = 0; i < N; i++) {
    ll v1; cin >> v1; V[i] = v1;
    ll v2; cin >> v2; W[i] = v2;
  }
  // @End [auAMpRlT]

  vector tbl_init(2, vector<ll>(K + 1, -1LL));
  auto tbl = tbl_init;
  tbl[0][0] = 0;
  REP(i, 0, N) {
    auto prev = move(tbl);
    tbl = tbl_init;
    REP(k, 0, K + 1) if (prev[0][k] >= 0 and k + W[i] <= K) {
      updMax(tbl[1][k + W[i]], prev[0][k] + V[i]);
    }
    REP(k, 0, K + 1) if (prev[0][k] >= 0) {
      updMax(tbl[0][k], prev[0][k]);
    }
    REP(k, 0, K + 1) if (prev[1][k] >= 0) {
      updMax(tbl[0][k], prev[1][k]);
    }
  }
  ll ans = 0;
  REP(b, 0, 2) REP(k, 0, K + 1) ans = max(ans, tbl[b][k]);
  cout << ans << endl;

  return 0;
}

