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

  auto solve = [&]() -> void {
    ll N; cin >> N;
    // @InpGrid(N, N, H) [pk6GRC6U]
    auto H = vector(N, vector(N, ll()));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++) { ll v; cin >> v; H[i][j] = v; }
    // @End [pk6GRC6U]

    ll big = 1e18;

    auto f = [&](const auto& C) -> ll {
      ll vinc = C[0];
      ll vsame = 0;
      REP(i, 1, N) {
        ll winc = vinc;
        ll wsame = vsame;
        vinc = big;
        vsame = big;
        if (wsame < big) {
          if (not EXISTS(j, 0, N, H[i - 1][j] + 0 == H[i][j] + 1)) {
            updMin(vinc, wsame + C[i]);
          }
          if (not EXISTS(j, 0, N, H[i - 1][j] + 0 == H[i][j] + 0)) {
            updMin(vsame, wsame);
          }
        }
        if (winc < big) {
          if (not EXISTS(j, 0, N, H[i - 1][j] + 1 == H[i][j] + 1)) {
            updMin(vinc, winc + C[i]);
          }
          if (not EXISTS(j, 0, N, H[i - 1][j] + 1 == H[i][j] + 0)) {
            updMin(vsame, winc);
          }
        }
      }
      return min(vinc, vsame);
    };


    // @InpVec(N, A) [UF0YOe5C]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [UF0YOe5C]
    // @InpVec(N, B) [fZJnh43p]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [fZJnh43p]

    ll x = f(A);
    REP(i, 0, N) REP(j, i + 1, N) swap(H[i][j], H[j][i]);
    ll y = f(B);
    ll ans = x + y;
    if (ans >= big) ans = -1;
    cout << ans << "\n";
  };

  ll T; cin >> T;
  for (ll _t = 0; _t < T; _t++) solve();

  return 0;
}

