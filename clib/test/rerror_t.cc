#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(rerror)

// ---- inserted library file rerror.cc

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


// ---- end rerror.cc

// @@ !! LIM -- end mark --

int main() {
  assert(may_eq(3,3));
  assert(may_le(3,4));
  assert(may_le(3,3));
  assert(may_ge(4,3));
  assert(may_ge(3,3));
  assert(! may_eq(3,4));
  assert(! may_le(4,3));
  assert(! may_ge(3,4));

  assert(! may_eq(3-1e-6, 3));
  assert(  may_eq(3-1e-14, 3));
  assert(  may_eq(3+1e-14, 3));
  assert(! may_eq(3+1e-6, 3));

  assert(  may_le(3-1e-6, 3));
  assert(  may_le(3-1e-14, 3));
  assert(  may_le(3+1e-14, 3));
  assert(! may_le(3+1e-6, 3));

  assert(! may_ge(3-1e-6, 3));
  assert(  may_ge(3-1e-14, 3));
  assert(  may_ge(3+1e-14, 3));
  assert(  may_ge(3+1e-6, 3));

  assert(! may_eq(3-1e-4, 3, 1e-6));
  assert(  may_eq(3-1e-8, 3, 1e-6));
  assert(  may_eq(3+1e-8, 3, 1e-6));
  assert(! may_eq(3+1e-4, 3, 1e-6));

  assert(! may_eq_abs_only(3-1e-6, 3));
  assert(  may_eq_abs_only(3-1e-14, 3));
  assert(  may_eq_abs_only(3+1e-14, 3));
  assert(! may_eq_abs_only(3+1e-6, 3));

  assert(  may_le_abs_only(3-1e-6, 3));
  assert(  may_le_abs_only(3-1e-14, 3));
  assert(  may_le_abs_only(3+1e-14, 3));
  assert(! may_le_abs_only(3+1e-6, 3));

  assert(! may_ge_abs_only(3-1e-6, 3));
  assert(  may_ge_abs_only(3-1e-14, 3));
  assert(  may_ge_abs_only(3+1e-14, 3));
  assert(  may_ge_abs_only(3+1e-6, 3));

  assert(! may_eq(3-1e-4, 3, 1e-6, true));
  assert(  may_eq(3-1e-8, 3, 1e-6, true));
  assert(  may_eq(3+1e-8, 3, 1e-6, true));
  assert(! may_eq(3+1e-4, 3, 1e-6, true));

  assert(! may_eq(1e10-100, 1e10));
  assert(  may_eq(1e10-  1, 1e10));
  assert(  may_eq(1e10+  1, 1e10));
  assert(! may_eq(1e10+100, 1e10));

  assert(! may_eq_abs_only(1e10-100, 1e10));
  assert(! may_eq_abs_only(1e10-  1, 1e10));
  assert(! may_eq_abs_only(1e10+  1, 1e10));
  assert(! may_eq_abs_only(1e10+100, 1e10));

  cout << "Test Done." << endl;
}
