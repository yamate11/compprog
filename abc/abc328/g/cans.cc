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

using ull = unsigned long long;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll N, C; cin >> N >> C;
  // @InpVec(N, A) [Nkl8GU60]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Nkl8GU60]
  // @InpVec(N, B) [FLansxnX]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [FLansxnX]

  ll big = 1e18;
  auto tbl = vector(1LL << N, big);
  tbl[(1LL << N) - 1] = 0;
  REPrev(x, (1LL << N) - 1, 0) {
    ll n = N - popcount(ull(x));
    REP(lo, 0, N) {
      if (not (x >> lo & 1)) continue;
      REP(hi, lo, N) {
        if (not (x >> hi & 1)) break;
        ll cost = 0;
        REP(i, 0, hi - lo + 1) cost += abs(B[n + i] - A[lo + i]);
        if (lo - 1 >= 0 and     (x >> (lo - 1) & 1)) cost += C;
        if (hi + 1 <  N and     (x >> (hi + 1) & 1)) cost += C;
        ll tmp1 = (1LL << (hi + 1)) - 1;
        ll tmp2 = (1LL << lo) - 1;
        ll rem = tmp1 & ~tmp2;
        updMin(tbl[x & ~rem], tbl[x] + cost);
      }
    }
  }
  cout << tbl[0] << endl;

  return 0;
}

