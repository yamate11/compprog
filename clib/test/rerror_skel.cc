#include <bits/stdc++.h>
#include <cassert>
typedef long long int ll;
using namespace std;

// @@ !! LIM(rerror)

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
