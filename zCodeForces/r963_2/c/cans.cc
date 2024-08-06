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

// @@ !! LIM(forall f:updMaxMin)

// ---- inserted library file forall.cc

#define EX_REP_LL(i, from, to) for (ll i = (from); i < (to); i++)
#define EX_REP_RB(x, coll) for (auto x : coll)
#define EXGEN(rep_part, cond, yes, no_behaviour) ([&]() { rep_part if (cond) return (yes); no_behaviour; }())
#define EXISTS_BASE(rep_part, cond) EXGEN(rep_part, cond, true, return false)
#define EXFIND_BASE(rep_part, cond, t) EXGEN(rep_part, cond, t, assert(0))
#define EXFIND_D_BASE(rep_part, cond, t, def) EXGEN(rep_part, cond, t, return def)

#define EXISTS(i, from, to, cond) EXISTS_BASE(EX_REP_LL(i, from, to), cond)
#define FORALL(i, from, to, cond) (not EXISTS(i, from, to, not (cond)))
#define EXFIND(i, from, to, cond) EXFIND_BASE(EX_REP_LL(i, from, to), cond, i)
#define EXFIND_D(i, from, to, cond, def) EXFIND_D_BASE(EX_REP_LL(i, from, to), cond, i, def)

#define EXISTS_C(x, coll, cond) EXISTS_BASE(EX_REP_RB(x, coll), cond)
#define FORALL_C(x, coll, cond) (not EXISTS_C(x, coll, not (cond)))
#define EXFIND_C(x, coll, cond) EXFIND_BASE(EX_REP_RB(x, coll), cond, x)
#define EXFIND_D_C(x, coll, cond, def) EXFIND_D_BASE(EX_REP_RB(x, coll), cond, x, def)

#define COUNT_BASE(rep_part, cond) ([&](){ ll ret = 0; rep_part if (cond) ret++; return ret; }())
#define COUNT(i, from, to, cond) COUNT_BASE(EX_REP_LL(i, from, to), cond)
#define COUNT_C(x, coll, cond) COUNT_BASE(EX_REP_RB(x, coll), cond)

#define IMPLIES(a, b) (not (a) or (b))

// ---- end forall.cc

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

  auto solve = [&]() -> ll {
    ll N, K; cin >> N >> K;
    // @InpVec(N, A) [5Iln6XMY]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [5Iln6XMY]

    bool shifted = false;
    vector<ll> P(N), R(N);
    if (FORALL(i, 0, N, A[i] % (2 * K) >= K)) {
      shifted = true;
      REP(i, 0, N) A[i] += K;
    }
    ll i0 = EXFIND(i, 0, N, A[i] % (2 * K) < K);
    ll lo = A[i0] % (2 * K);
    ll hi = lo + K;
    REP(i, 0, N) {
      ll r = A[i] % (2 * K);
      if (r <= K) {
        if (hi <= r or r + K <= lo) return -1;
        lo = max(lo, r);
        hi = min(hi, r + K);
      }else {
        ll r1 = r - K;
        if (r < hi) {
          lo = max(lo, r);
        }else if (lo < r1) {
          hi = min(hi, r1);
        }else {
          return -1;
        }
      }
    }
    ll ans = 0;
    REP(i, 0, N) {
      ll r = A[i] % (2 * K);
      if (r <= K) {
        ll p = A[i] / (2 * K);
        updMax(ans, p * 2 * K + lo);
      }else {
        ll p = A[i] / (2 * K);
        if (r <= lo) {
          updMax(ans, p * 2 * K + lo);
        }else {
          updMax(ans, (p + 1) * 2 * K + lo);
        }
      }
    }
    if (shifted) ans -= K;
    return ans;
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) cout << solve() << "\n";

  return 0;
}

