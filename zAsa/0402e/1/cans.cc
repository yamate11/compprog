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

using pdd = pair<double, double>;

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  ll A, B, N; cin >> A >> B >> N;
  double T = sqrt(A * A + B * B);
  double phi = atan2(B, A);

  auto op = [&](ll C, ll D) -> bool {
    vector<pdd> vC, vD;
    if (C >= T) vC.emplace_back(0.0, M_PI/2);
    else {
      double alpha = asin(C / T);
      double b1 = alpha - phi;
      double b2 = M_PI - alpha - phi;
      if (b1 >= 0) vC.emplace_back(0.0, b1);
      if (b2 <= M_PI / 2) vC.emplace_back(b2, M_PI / 2);
    }
    if (D >= T) vD.emplace_back(0.0, M_PI/2);
    else {
      double beta = acos(D / T);
      double b1 = phi - beta;
      double b2 = phi + beta;
      if (b1 >= 0) vD.emplace_back(0.0, b1);
      if (b2 <= M_PI / 2) vD.emplace_back(b2, M_PI / 2);
    }
    for (auto [a, b] : vC) for (auto [c, d] : vD) if (max(a, c) <= min(b, d)) return true;
    return false;
  };

  REP(i, 0, N) {
    ll C, D; cin >> C >> D;
    cout << (op(C, D) ? "YES\n" : "NO\n");
  }

  return 0;
}

