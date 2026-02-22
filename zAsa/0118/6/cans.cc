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

  ll big = 1e18;

  ll N, M; cin >> N >> M;
  // @InpVec(N, A) [SeTQPH9n]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [SeTQPH9n]

  vector<ll> tblA_init(M + 1, big);
  vector<ll> tblB_init(M + 1, big);
  auto tblA = tblA_init;
  auto tblB = tblB_init;
  tblA[0] = 0;
  REP(i, 0, N) {
    auto prevA = move(tblA);
    tblA = tblA_init;
    auto prevB = move(tblB);
    tblB = tblB_init;
    REP(j, 0, M + 1) {
      if (prevA[j] < big) {
        updMin(tblB[j], prevA[j] + 1);
        if (j + A[i] <= M) updMin(tblA[j + A[i]], prevA[j]);
      }
      if (prevB[j] < big) {
        updMin(tblB[j], prevB[j]);
        if (j + A[i] <= M) updMin(tblA[j + A[i]], prevB[j]);
      }
    }
  }
  REP(x, 1, M + 1) {
    ll ans = min(tblA[x], tblB[x]);
    if (ans == big) ans = -1;
    cout << ans << endl;
  }

  return 0;
}

