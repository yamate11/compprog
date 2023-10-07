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

  ll HA, WA; cin >> HA >> WA;
  // @InpVec(HA, A, type=string) [VZ3NbX6x]
  auto A = vector(HA, string());
  for (int i = 0; i < HA; i++) { string v; cin >> v; A[i] = v; }
  // @End [VZ3NbX6x]
  ll HB, WB; cin >> HB >> WB;
  // @InpVec(HB, B, type=string) [0ngqBOQ6]
  auto B = vector(HB, string());
  for (int i = 0; i < HB; i++) { string v; cin >> v; B[i] = v; }
  // @End [0ngqBOQ6]
  ll HX, WX; cin >> HX >> WX;
  // @InpVec(HX, X, type=string) [Wq7kEBXl]
  auto X = vector(HX, string());
  for (int i = 0; i < HX; i++) { string v; cin >> v; X[i] = v; }
  // @End [Wq7kEBXl]

  vector XX(30, string(30, '.'));
  REP(i, 0, HX) REP(j, 0, WX) XX[10 + i][10 + j] = X[i][j];

  auto check = [&](ll dar, ll dac, ll dbr, ll dbc) -> bool {
    vector Y(30, string(30, '.'));
    REP(i, 0, HA) REP(j, 0, WA) Y[10 + dar + i][10 + dac + j] = A[i][j];
    REP(i, 0, HB) REP(j, 0, WB) {
      if (B[i][j] == '#') Y[10 + dbr + i][10 + dbc + j] = '#';
    }
    return XX == Y;
  };

  bool b = EXISTS(dar, -HA + 1, HA - 1 + 1,
                  EXISTS(dac, -WA + 1, WA - 1 + 1,
                         EXISTS(dbr, -HB + 1, HB - 1 + 1,
                                EXISTS(dbc, -WB + 1, WB - 1 + 1, check(dar, dac, dbr, dbc)))));
  cout << (b ? "Yes\n" : "No\n");
    
  return 0;
}

