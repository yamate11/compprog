#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  forall macros
    EXISTS    EXISTS_C
    FORALL    FORALL_C
    EXFIND    EXFIND_C    EXFIND_D    EXFIND_D_C
    COUNT     COUNT_C
    IMPLIES

  Usage:
    vector<ll> vec(N); ....

    if (FORALL(i, 0, N, vec[i] < 0)) cout << "All elements are negative." << endl;
    if (EXISTS(i, 0, N, vec[i] < 0)) cout << "There exists a negative." << endl;
    cout << "with i = " << EXFIND(i, 0, N, vec[i] < 0) << endl;
    cout << "with i = " << EXFIND_D(i, 0, N, vec[i] < 0, -1LL) << endl;
    // EXFIND(i, 0, N, cond) returns the least i where cond holds; fails if there is no such i.
    // EXFIND_D(i, 0, N, cond, def) returns the least i where cond holds; or returns def if there is no such i.

    if (FORALL_C(x, vec, x < 0)) cout << "All elements are negative." << endl;
    if (EXISTS_C(x, vec, x < 0)) cout << "There exists a negative." << endl;
    cout << "with x = " << EXFIND_C(x, vec, x < 0, -1LL) << endl;

 */

// @@ !! LIM()

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- forall.cc

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

// @@ !! END ---- forall.cc
