#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

/*
  rerror.cc

  Handling rounding errors in double or long double
  Real means double (or long double, if RERROR_LONGDOUBLE is #defined to 1).

  Real g_err ... default error precision (1e-9)

  Comparison
    may_eq, may_le, may_ge, 

    may_eq(x, y)   x = y may be correct
    may_le(x, y)   x <= y may be correct.
    may_ge(x, y)   x >= y may be correct.

    The default precision is g_err (1e-9).  You can specify a precision as the third argument such as:
    may_eq(x, y, 1e-6).  
    Both relative and absolute precisions are used.  You can omit relative precision by calling
    may_eq_abs_only(x, y) or may_eq(x, y, g_err, true).

 */


// @@ !! LIM()

//////////////////////////////////////////////////////////////////////
// See help of libins command for dependency spec syntax.
// @@ !! BEGIN() ---- rerror.cc

#if RERROR_LONGDOUBLE
using Real = long double;
#else
using Real = double;
#endif

// Default Error Value.
Real g_err = 1e-9;    // Too small value is not good.

bool may_eq(Real x, Real y, Real err = g_err, bool abs_only = false) {
  return abs(x - y) <= err or (not abs_only and abs(x - y) <= abs(x) * err);
}
bool may_le(Real x, Real y, Real err = g_err, bool abs_only = false) {
  return x - y <= err or (not abs_only and x - y <= abs(x) * err);
}
bool may_ge(Real x, Real y, Real err = g_err, bool abs_only = false) {
  return y - x <= err or (not abs_only and y - x <= abs(x) * err);
}

bool may_eq_abs_only(Real x, Real y, Real err = g_err) { return may_eq(x, y, err, true); }
bool may_le_abs_only(Real x, Real y, Real err = g_err) { return may_le(x, y, err, true); }
bool may_ge_abs_only(Real x, Real y, Real err = g_err) { return may_ge(x, y, err, true); }


// @@ !! END ---- rerror.cc

