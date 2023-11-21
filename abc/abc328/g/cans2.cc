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
  // @InpVec(N, A) [Nkl8GU60]
  auto A = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
  // @End [Nkl8GU60]
  // @InpVec(N, B) [FLansxnX]
  auto B = vector(N, ll());
  for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
  // @End [FLansxnX]

  auto g = [&](ll prelen, ll lo, ll hi) -> ll {
    ll ret = 0;
    REP(i, 0, hi - lo) ret += abs(B[prelen + i] - A[lo + i]);
    return ret;
  };

  ll big = 1e18;
  vector tbl(1LL << (N + 1), big);
  auto f = [&](auto rF, ll x, ll prelen) -> ll {
    ll& ret = tbl[x];
    ll lo = -1;
    ll hi = -1;
    if (ret == big) {
      if (x == 0) ret = 0;
      else {
        while (true) {
          for (lo = hi + 1; lo <= N and not (x >> lo & 1); lo++);
          if (lo > N) break;
          for (hi = lo + 1; hi <= N and not (x >> hi & 1); hi++);
          assert(hi <= N);
          {
            ll newX = x ^ (1LL << lo) ^ (1LL << hi);
            ll v = g(prelen, lo, hi) + rF(rF, newX, prelen + hi - lo);
            updMin(ret, v);
          }
          REP(newHi, lo + 1, hi) {
            ll newX = x ^ (1LL << newHi) ^ (1LL << hi);
            ll v = C + g(prelen, newHi, hi) + rF(rF, newX, prelen + hi - newHi);
            updMin(ret, v);
          }
          REP(newLo, lo + 1, hi) {
            ll newX = x ^ (1LL << lo) ^ (1LL << newLo);
            ll v = C + g(prelen, lo, newLo) + rF(rF, newX, prelen + newLo - lo);
            updMin(ret, v);
          }
          REP(newLo, lo + 1, hi) REP(newHi, newLo + 1, hi) {
            ll newX = x ^ (1LL << newLo) ^ (1LL << newHi);
            ll v = 2*C + g(prelen, newLo, newHi) + rF(rF, newX, prelen + newHi - newLo);
            updMin(ret, v);
          }
        }
      }
    }
    return ret;
  };

  cout << f(f, (1 << 0) | (1 << N), 0) << endl;
  return 0;
}

