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

// @@ !! LIM(forall)

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

// @@ !! LIM -- end mark --

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  auto solve = [&]() -> bool {
    ll N; cin >> N;
    // @InpVec(N, A) [YpVKwpnD]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [YpVKwpnD]
    // @InpVec(N, B) [WuB1I4mC]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [WuB1I4mC]
    auto AS = A;
    auto BS = B;
    sort(ALL(AS));
    sort(ALL(BS));
    if (AS != BS) return false;
    ll ne = 0, no = 0;
    REP(i, 0, N) {
      if (A[i] % 2 == 0) ne++;
      else no++;
    }
    if (ne == 0) return A == B;
    if (no == 0) return true;
    auto act_odd = [&](ll i, auto& vec) -> bool {
      if (vec[i] % 2 == 0) return false;
      if (i - 2 >= 0 and vec[i - 2] % 2 != 0) return true;
      if (i - 1 >= 0 and vec[i - 1] % 2 != 0) return true;
      if (i + 1 < SIZE(vec) and vec[i + 1] % 2 != 0) return true;
      if (i + 2 < SIZE(vec) and vec[i + 2] % 2 != 0) return true;
      return false;
    };
    bool mA = EXISTS(i, 0, N, act_odd(i, A));
    bool mB = EXISTS(i, 0, N, act_odd(i, B));
    if (mA and mB) return true;
    if (mA != mB) return false;
    vector<ll> oA, oB;
    oA.push_back(-1); oB.push_back(-1);
    REP(i, 0, N) if (A[i] % 2 != 0) oA.push_back(i);
    REP(i, 0, N) if (B[i] % 2 != 0) oB.push_back(i);
    oA.push_back(N); oB.push_back(N);
    if (EXISTS_C(i, oA, i >= 0 and i < N and A[i] != B[i])) return false;
    if (EXISTS(j, 0, SIZE(oA) - 1,
               oA[j + 1] - oA[j] <= 2 and EXISTS(k, oA[j] + 1, oA[j + 1], A[k] != B[k]))) return false;
    return true;
  };
  cout << (solve() ? "Yes\n" : "No\n");

  return 0;
}

