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
    // @InpVec(N, A) [dR3vlRfW]
    auto A = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; A[i] = v; }
    // @End [dR3vlRfW]
    // @InpVec(N, B) [Prp7wuGG]
    auto B = vector(N, ll());
    for (int i = 0; i < N; i++) { ll v; cin >> v; B[i] = v; }
    // @End [Prp7wuGG]
  
    auto sA = A;
    auto sB = B;
    sort(ALL(sA));
    sort(ALL(sB));
    if (sA != sB) return false;

    auto func1 = [&](const auto& vec) -> vector<ll> {
      ll sz = SIZE(vec);
      vector<ll> ret;
      REP(i, 0, sz) if (vec[i] % 2 != 0) {
        if ((i + 1 < sz and vec[i + 1] % 2 != 0) or (i + 2 < sz and vec[i + 2] % 2 != 0)) return ret;
      }
      REP(i, 0, sz) if (vec[i] % 2 != 0) ret.push_back(i);
      return ret;
    };

    bool aoA = FORALL(i, 0, N, A[i] % 2 != 0);
    bool aoB = FORALL(i, 0, N, B[i] % 2 != 0);
    if (aoA != aoB) return false;
    if (aoA) return A == B;

    auto fixA = func1(A);
    auto fixB = func1(B);
  
    if (fixA != fixB) return false;
    if (fixA.empty()) {
      vector<ll> eA, eB;
      REP(i, 0, N) if (A[i] % 2 == 0) eA.push_back(A[i]);
      REP(i, 0, N) if (B[i] % 2 == 0) eB.push_back(B[i]);
      return SIZE(eA) != 2 or eA == eB;
    }
    if (not FORALL(i, 0, SIZE(fixA), A[fixA[i]] == B[fixA[i]])) return false;
    fixA.push_back(N);
    REP(i, 0, SIZE(fixA)) {
      ll b = (i == 0) ? 0 : fixA[i - 1] + 1;
      vector<ll> P(A.begin() + b, A.begin() + fixA[i]);
      vector<ll> Q(B.begin() + b, B.begin() + fixA[i]);
      if (SIZE(P) == 2 and P != Q) return false;
      sort(ALL(P));
      sort(ALL(Q));
      if (P != Q) return false;
    }
    return true;
  };

  cout << (solve() ? "Yes\n" : "No\n");
  return 0;
}

