#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(rerror)

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
