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

bool r_eq(Real x, Real y, Real err = g_err) {
  return abs(x - y) <= err || abs(x - y) <= abs(x) * err;
}
bool r_le(Real x, Real y, Real err = g_err) {
  return x - y <= err || x - y <= abs(x) * err;
}
bool r_ge(Real x, Real y, Real err = g_err) { return r_le(y, x, err); }
bool r_gt(Real x, Real y, Real err = g_err) { return !r_le(x, y, err); }
bool r_lt(Real x, Real y, Real err = g_err) { return !r_le(y, x, err); }
bool r_ne(Real x, Real y, Real err = g_err) { return !r_eq(x, y, err); }

bool rp_eq(Real x, Real y, Real err = g_err) { return abs(x - y) <= err; }
bool rp_le(Real x, Real y, Real err = g_err) { return x - y <= err; }
bool rp_ge(Real x, Real y, Real err = g_err) { return rp_le(y, x, err); }
bool rp_gt(Real x, Real y, Real err = g_err) { return !rp_le(x, y, err); }
bool rp_lt(Real x, Real y, Real err = g_err) { return !rp_le(y, x, err); }
bool rp_ne(Real x, Real y, Real err = g_err) { return !rp_eq(x, y, err); }

// ---- end rerror.cc

// @@ !! LIM -- end mark --

int main() {
  assert(r_eq(3,3));
  assert(r_ne(3,4));
  assert(r_le(3,4));
  assert(r_le(3,3));
  assert(r_ge(4,3));
  assert(r_ge(3,3));
  assert(r_lt(3,4));
  assert(r_gt(4,3));
  assert(! r_eq(3,4));
  assert(! r_ne(3,3));
  assert(! r_le(4,3));
  assert(! r_ge(3,4));
  assert(! r_lt(4,3));
  assert(! r_lt(3,3));
  assert(! r_gt(3,4));
  assert(! r_gt(3,3));

  assert(! r_eq(3-1e-6, 3));
  assert(  r_eq(3-1e-14, 3));
  assert(  r_eq(3+1e-14, 3));
  assert(! r_eq(3+1e-6, 3));

  assert(  r_ne(3-1e-6, 3));
  assert(! r_ne(3-1e-14, 3));
  assert(! r_ne(3+1e-14, 3));
  assert(  r_ne(3+1e-6, 3));

  assert(  r_lt(3-1e-6, 3));
  assert(! r_lt(3-1e-14, 3));
  assert(! r_lt(3+1e-14, 3));
  assert(! r_lt(3+1e-6, 3));

  assert(  r_le(3-1e-6, 3));
  assert(  r_le(3-1e-14, 3));
  assert(  r_le(3+1e-14, 3));
  assert(! r_le(3+1e-6, 3));

  assert(! r_gt(3-1e-6, 3));
  assert(! r_gt(3-1e-14, 3));
  assert(! r_gt(3+1e-14, 3));
  assert(  r_gt(3+1e-6, 3));

  assert(! r_ge(3-1e-6, 3));
  assert(  r_ge(3-1e-14, 3));
  assert(  r_ge(3+1e-14, 3));
  assert(  r_ge(3+1e-6, 3));

  assert(! r_eq(3-1e-4, 3, 1e-6));
  assert(  r_eq(3-1e-8, 3, 1e-6));
  assert(  r_eq(3+1e-8, 3, 1e-6));
  assert(! r_eq(3+1e-4, 3, 1e-6));

  assert(! rp_eq(3-1e-6, 3));
  assert(  rp_eq(3-1e-14, 3));
  assert(  rp_eq(3+1e-14, 3));
  assert(! rp_eq(3+1e-6, 3));

  assert(  rp_ne(3-1e-6, 3));
  assert(! rp_ne(3-1e-14, 3));
  assert(! rp_ne(3+1e-14, 3));
  assert(  rp_ne(3+1e-6, 3));

  assert(  rp_lt(3-1e-6, 3));
  assert(! rp_lt(3-1e-14, 3));
  assert(! rp_lt(3+1e-14, 3));
  assert(! rp_lt(3+1e-6, 3));

  assert(  rp_le(3-1e-6, 3));
  assert(  rp_le(3-1e-14, 3));
  assert(  rp_le(3+1e-14, 3));
  assert(! rp_le(3+1e-6, 3));

  assert(! rp_gt(3-1e-6, 3));
  assert(! rp_gt(3-1e-14, 3));
  assert(! rp_gt(3+1e-14, 3));
  assert(  rp_gt(3+1e-6, 3));

  assert(! rp_ge(3-1e-6, 3));
  assert(  rp_ge(3-1e-14, 3));
  assert(  rp_ge(3+1e-14, 3));
  assert(  rp_ge(3+1e-6, 3));

  assert(! rp_eq(3-1e-4, 3, 1e-6));
  assert(  rp_eq(3-1e-8, 3, 1e-6));
  assert(  rp_eq(3+1e-8, 3, 1e-6));
  assert(! rp_eq(3+1e-4, 3, 1e-6));

  assert(! r_eq(1e10-100, 1e10));
  assert(  r_eq(1e10-  1, 1e10));
  assert(  r_eq(1e10+  1, 1e10));
  assert(! r_eq(1e10+100, 1e10));

  assert(! rp_eq(1e10-100, 1e10));
  assert(! rp_eq(1e10-  1, 1e10));
  assert(! rp_eq(1e10+  1, 1e10));
  assert(! rp_eq(1e10+100, 1e10));

  assert(  r_lt(1e10-100, 1e10));
  assert(! r_lt(1e10-  1, 1e10));
  assert(! r_lt(1e10+  1, 1e10));
  assert(! r_lt(1e10+100, 1e10));

  assert(  rp_lt(1e10-100, 1e10));
  assert(  rp_lt(1e10-  1, 1e10));
  assert(! rp_lt(1e10+  1, 1e10));
  assert(! rp_lt(1e10+100, 1e10));

  cout << "Test Done." << endl;
}
