#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;
#define REP2(i, a, b) for (ll i = (a); i < (b); i++)
#define REP2R(i, a, b) for (ll i = (a); i >= (b); i--)
#define REP(i, b) REP2(i, 0, b)
#define ALL(coll) (coll).begin(), (coll).end()
#define SIZE(v) ((ll)((v).size()))

// @@ !! LIM(forall)

// ---- inserted library file forall.cc
#line 35 "/home/y-tanabe/proj/compprog/clib/forall.cc"

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
#line 12 "forall_skel.cc"

int main(/* int argc, char *argv[] */) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout << setprecision(20);

  {
    vector<ll> vec1 = {10, -5, 3, 4, -6, 2};
    assert(FORALL(i, 0, SIZE(vec1), vec1[i] <= 10));
    assert(not FORALL(i, 0, SIZE(vec1), vec1[i] >= 0));
    assert(EXISTS(i, 0, SIZE(vec1), vec1[i] <= -6));
    assert(not EXISTS(i, 0, SIZE(vec1), vec1[i] < -6));
    assert(EXFIND(i, 0, SIZE(vec1), vec1[i] < 0) == 1);
    assert(EXFIND_D(i, 0, SIZE(vec1), vec1[i] < -10, -1LL) == -1LL);
    assert(not FORALL(i, 0, SIZE(vec1), -6 <= vec1[i] and vec1[i] <= 5));
    assert(COUNT(i, 0, SIZE(vec1), vec1[i] % 2 == 0) == 4);
    assert(COUNT(i, 0, SIZE(vec1) - 1, vec1[i] < vec1[i + 1]) == 3);
  }
  {
    vector<ll> vec1 = {10, -5, 3, 4, -6, 2};
    assert(FORALL_C(x, vec1, x <= 10));
    assert(not FORALL_C(x, vec1, x >= 0));
    assert(EXISTS_C(x, vec1, x <= -6));
    assert(not EXISTS_C(x, vec1, x < -6));
    assert(EXFIND_C(x, vec1, x < 0) == -5);
    assert(EXFIND_D_C(x, vec1, x < -10, 100LL) == 100);
  }
  {
    auto func = [&](ll x, ll a) -> ll { return (x - 3) * (x - 3) + a; };
    assert(FORALL(x, 0, 7, func(x, 1) >= 1));
    assert(EXISTS(x, 0, 7, func(x, 1) < 2));
    assert(FORALL(a, -3, 3, FORALL(x, 0, 7, func(x, a) >= a)));
    assert(EXISTS(a, -3, 3, FORALL(x, 0, 7, func(x, a) >= 2)));
  }
  return 0;
}

